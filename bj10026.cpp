//
//  main.cpp
//  bj10026
//
//  Created by new_mac on 2019. 7. 29..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//23분만에 풀이완료!


#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <queue>
using namespace std;
const int MAX_N = 102;
int n;

char map[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int dir_y[4] = {0,0,1,-1};
int dir_x[4] = {1,-1,0,0};


void bfs(int y,int x,int color){
    queue<pair<int,int>> queue;
    queue.push(make_pair(y,x));
    visited[y][x] = 1;
    while(!queue.empty()){
        int now_y = queue.front().first;
        int now_x = queue.front().second;
        queue.pop();
        for(int i=0;i<4;i++){
            int next_y = now_y + dir_y[i];
            int next_x = now_x + dir_x[i];
            if(next_y<0 || next_y > n-1 || next_x<0 || next_x > n-1 || visited[next_y][next_x] == 1)
                continue;
            if(color == 0){
                if(map[now_y][now_x] != map[next_y][next_x])
                    continue;
                
            }else{
                if(map[now_y][now_x] == 'R'){
                    if(map[next_y][next_x] == 'B')
                        continue;
                }else if(map[now_y][now_x] == 'G'){
                    if(map[next_y][next_x] == 'B')
                        continue;
                }else if(map[now_y][now_x] == 'B'){
                    if(map[now_y][now_x] != map[next_y][next_x])
                        continue;
                }
            
            }
            
            visited[next_y][next_x] = 1;
            queue.push(make_pair(next_y,next_x));
            
        }
    }
    

}

int main(int argc, const char * argv[]) {
    
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        for(int j=0;j<n;j++){
            map[i][j] = temp[j];
        }
    }
    
    int result1 = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j] == 0){
                bfs(i, j, 0);
                result1++;
            }
        }
    }
    
    memset(visited, 0, sizeof(visited));
    int result2 = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j] == 0){
                bfs(i, j, 1);
                result2++;
            }
        }
    }

    printf("%d %d",result1,result2);
    
    
    return 0;
}
