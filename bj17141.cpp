//
//  main.cpp
//  bj17141
//
//  Created by new_mac on 2019. 7. 29..
//  Copyright © 2019년 new_mac. All rights reserved.
//

//backtracking 으로 풀었을 때 시간초과가 남. --> next_permutation으로 풀어서 정답! 1시간 30분 걸림!
//좀더 정확한 풀이방법으로 다시 풀었음. --> 처음에 빈칸의 개수를 세어놓고 bfs를 진행하면서 감염시킨 칸과 빈칸을 대조하며 비교한다.

#include <iostream>
#include <stdio.h>
#include <vector>
#include <deque>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAX_N = 52;
int n,m;
int map[MAX_N][MAX_N];
vector<pair<int,int>> virus;
int visited[MAX_N][MAX_N];
int dir_y[4] = {0,0,1,-1};
int dir_x[4] = {1,-1,0,0};
int clean;

int Answer = INT32_MAX;
int bfs(deque<pair<int,int>> queue){
    int t = 0;
    int result = 0;
    while(!queue.empty()){
        int size = queue.size();
        for(int i=0;i<size;i++){
            
        int now_y = queue.front().first;
        int now_x = queue.front().second;
        queue.pop_front();
        for(int i =0 ;i<4;i++){
            int next_y = now_y + dir_y[i];
            int next_x = now_x + dir_x[i];
            if(next_y<0 || next_y > n-1 || next_x <0 || next_x > n-1)
                continue;
            if(visited[next_y][next_x] != 0)
                continue;
            if(map[next_y][next_x] == 1)
                continue;
            if(map[next_y][next_x] == 0){
                result++;
            }
            visited[next_y][next_x] = visited[now_y][now_x] + 1;
            
            queue.push_back(make_pair(next_y,next_x));
        }
            
        }
        t++;
        if(result == clean)
            break;
        
    }
    
    if(result < clean)
        return 0;
    
    return t;
}

int find_time(){
    int result = -2;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j] == 0){
                return 0;
            }
            if(visited[i][j] > result){
                result = visited[i][j];
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j] == result){
                if(map[i][j] != 2){
                    return result-1;
                }
            }
        }
    }
    
    
    
    return result-2;
}

void print_m(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",visited[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void dfs(deque<pair<int,int>> queue){
    vector<int> select;
    for(int i=0;i<virus.size();i++){
        if(i<m)
            select.push_back(1);
        else
            select.push_back(0);
    }
    sort(select.begin(),select.end());
    int temp_v[MAX_N][MAX_N] = {0,};
    memcpy(temp_v,visited,sizeof(visited));
    do{
        deque<pair<int,int>> queue;
        memcpy(visited,temp_v,sizeof(visited));
        for(int i=0;i<virus.size();i++){
            if(select[i] == 1){
                int y = virus[i].first;
                int x = virus[i].second;
                queue.push_back(make_pair(y,x));
                visited[y][x] = 1;
            }
        }
       // bfs(queue);
        
        int result = bfs(queue);
        if(result !=0){
            if(Answer > result)
                Answer = result;
        }
        
        
        
    }while(next_permutation(select.begin(), select.end()));
   

    

}

bool check_map(){
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j] == 0)
                return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int temp = 0;
            scanf("%d",&temp);
            map[i][j] = temp;
            if(temp == 2){
                virus.push_back(make_pair(i,j));
            }else if(temp == 1){
                visited[i][j] = -1;
            }else{
                clean++;
            }
        }
    }
    
    if(check_map())
        cout<<0<<endl;
    else{
    deque<pair<int,int>> queue;
    dfs(queue);
    if(Answer == INT32_MAX)
        cout<<-1<<endl;
    else
        cout<<Answer<<endl;
    }
    
    
    
    return 0;
}
