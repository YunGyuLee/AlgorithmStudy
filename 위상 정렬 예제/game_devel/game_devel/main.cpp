//
//  main.cpp
//  game_devel
//
//  Created by new_mac on 2019. 7. 2..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//풀이 실패 --> 위상정렬의 개념을 잘못알고 있는것 같다!!
//우선 위상정렬은 정확히 bfs는 아니다! --> 진입차수가 0인 부분을 queue에 넣는다는 것이 특징!

//****포인트****
// 1과 2가 동시에 3으로 들어가는 그래프를 생각해보면 1,2가 모두 queue에서 빠져야 3을 방문하게된다.(이부분이 바로 진입차수가 0인 부분을 queue에 넣기 때문에 생기는 특징인데, 단순히 순서만 출력하면 되는 단순 위상정렬과 다르게 건설완료 시간을 출력해야 하기때문에 1에서 3으로 가는 시간과 2에서 3으로 가는 시간을 비교하여 '더 큰' 시간을 선택하여야 한다! 더 큰 시간을 선택해야 하는 이유는 1과 2가 끝나야 3으로 진행이 가능하기 때문에 더 큰시간을 선택하여야 두 작업이 모두 끝난 시간을 정확히 측정할 수 있다.!!!)
#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;


const int MAX_N = 502;
int n;
vector<int> list[MAX_N];
int indegree[MAX_N];
int visited[MAX_N];
int v_time[MAX_N];


void bfs(queue<int> queue){
    while(!queue.empty()){
        int now = queue.front();
        queue.pop();
       
        for(int i=0;i<list[now].size();i++){
            int next = list[now][i];
            indegree[next] -= 1;
            visited[next] = max(visited[next],visited[now] + v_time[next]);
            
            
            if(indegree[next] == 0){
                queue.push(next);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    scanf("%d",&n);
    
    
    
    for(int i=1;i<=n;i++){
        int t = 0;
        scanf("%d",&t);
        v_time[i] = t;
        
        while(1){
            int temp = 0;
            scanf("%d",&temp);
            if(temp == -1)
                break;
            
            list[temp].push_back(i);
            indegree[i] += 1;
            
        }
    }
    
    queue<int> queue;
    for(int i=1;i<=n;i++){
        if(indegree[i] == 0){
            queue.push(i);
            visited[i] = v_time[i];
        }
    }
    
    bfs(queue);
    for(int i=1;i<=n;i++){
        printf("%d\n",visited[i]);
    }
    
    return 0;
}
