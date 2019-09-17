//
//  main.cpp
//  sam1953
//
//  Created by new_mac on 2019. 8. 8..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//30분만에 풀이완료.
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

const int MAX_N = 51;
int n,m;

int dir_y[4] = {-1,1,0,0};
int dir_x[4] = {0,0,-1,1};
int map[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int pipe[7][4] =
{ {1,1,1,1} , {1,1,0,0} ,{0,0,1,1},{1,0,0,1},{0,1,0,1},{0,1,1,0},{1,0,1,0}
};

int s_y,s_x;
int L;


int find_d(int d){
    if(d == 0){
        return 1;
    }else if(d == 1)
        return 0;
    else if(d == 2)
        return 3;
    else if(d == 3)
        return 2;
    else
        return -1;

}


int bfs(){
    int result =1;
    queue<pair<int,int>> queue;
    queue.push(make_pair(s_y, s_x));
    visited[s_y][s_x] = 1;
    while(!queue.empty()){
        int now_y = queue.front().first;
        int now_x = queue.front().second;
        int now_pipe = map[now_y][now_x];
        
        queue.pop();
        if(visited[now_y][now_x] == L)
            continue;
        for(int i=0;i<4;i++){
            int next_d = pipe[now_pipe-1][i];
            if(next_d == 0)
                continue;
            int next_y = now_y + dir_y[i];
            int next_x = now_x + dir_x[i];
            if(next_y<0||next_y>n-1||next_x<0||next_x>m-1||map[next_y][next_x] == 0)
                continue;
            if(visited[next_y][next_x] != 0)
                continue;
            int check_d = find_d(i);
            int next_pipe = map[next_y][next_x];
            if(pipe[next_pipe-1][check_d] == 1){
                visited[next_y][next_x] = visited[now_y][now_x] + 1;
                queue.push(make_pair(next_y, next_x));
                result++;
            
            }
            
            
            
            
        }
    
    
    }
    
    return result;

}


int main(int argc, const char * argv[]) {
    int T = 0;
    scanf("%d",&T);
    for(int testcase = 1 ;testcase<=T;testcase++){
        scanf("%d %d %d %d %d",&n,&m,&s_y,&s_x,&L);
        memset(visited,0,sizeof(visited));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%d",&map[i][j]);
            }
        }
        
        printf("#%d %d\n",testcase,bfs());
        
    }
    
    
    
    
    return 0;
}
