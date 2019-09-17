//
//  main.cpp
//  Max_flow
//
//  Created by new_mac on 2019. 7. 1..
//  Copyright © 2019년 new_mac. All rights reserved.
//
// 동빈나의 알고리즘에서 가정한 그래프는 방향 그래프였다. 때문에 한방향으로만 용량을 정해주면 되었지만 해당 문제에서는 양방향이 모두 가능하므로 양방향으로 용량을 정의해 주어야한다.
#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <math.h>
#include <cstring>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAX_n = 130;
int n;
int flow[MAX_n][MAX_n];
int capacity[MAX_n][MAX_n];
int visited[MAX_n];
vector<int> a[MAX_n];
int result;




void max_flow(int start,int end){

    while(1){
        queue<int> queue;
        queue.push(start);
        memset(visited,-1,sizeof(visited));
        visited[start] = start;
        while(!queue.empty()){
            int now_v = queue.front();
            queue.pop();
            for(int i=0;i<a[now_v].size();i++){
                int next_v = a[now_v][i];
                if(capacity[now_v][next_v] - flow[now_v][next_v] > 0 && visited[next_v] == -1){
                    queue.push(next_v);
                    visited[next_v] = now_v;
                    if(next_v == end)
                        break;
                }
                
            }
        
        }
        
        if(visited[end] == -1)
            break;
        int min_f = INT32_MAX;
        
        for(int i=end;i!=start;i = visited[i]){
            min_f = min(min_f, capacity[visited[i]][i] - flow[visited[i]][i]);//여기서 오류
        }
        
        for(int i=end;i!=start;i=visited[i]){
            flow[visited[i]][i] += min_f;
            flow[i][visited[i]] -= min_f;
        }
        
        result += min_f;
    
    }
    
    

}

int main(int argc, const char * argv[]) {
    
    
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char v1;
        char v2;
        int c;
     //   scanf(" %c %c %d",&v1,&v2,&c);
        cin>>v1>>v2>>c;
        int y = v1-'A';
        int x = v2-'A';
     
        a[y].push_back(x);
        a[x].push_back(y);
        capacity[y][x] += c; //두 노드가 두번이상 연결되어 있을 수도잇음. --> 이부분 실수
        capacity[x][y] += c; // 파이프가 양방향이므로!!!!!! --> 기본 에드몬드 알고리즘에서 추가해줘야한다!!
    }
    
    max_flow('A' - 'A', 'Z' - 'A');
    printf("%d\n",result);
    
    
    
    return 0;
}
