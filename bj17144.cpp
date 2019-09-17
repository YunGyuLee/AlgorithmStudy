//
//  main.cpp
//  bj17144
//
//  Created by new_mac on 2019. 7. 31..
//  Copyright © 2019년 new_mac. All rights reserved.
//
// 시간 초과 --> 2시간 정도 걸림...
// 또 같은 실수를 반복하였다... 공기청정기로 지도의 위치가 바뀌는데 큐에서는 이전 지도의 위치를 정보로 가지고잇음...
//결국 실력인 것이다.... 단순한 오류가 아니고 완전히 놓친생각....
//확산도 bfs로 풀필요가 없다... 1번만 확산하기 때문에

#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
const int MAX_R = 52;
int r,c,t;
int map[MAX_R][MAX_R];
int visited[MAX_R][MAX_R];
struct air_C{
    int y1;
    int x1;
    int y2;
    int x2;
};

air_C air = air_C{-1,-1,-1,-1};
int dir_y[4] = {0,0,1,-1};
int dir_x[4] = {1,-1,0,0};
int Answer = 0;


void print_m(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
}

void move(){
    int t_map[MAX_R][MAX_R] = {0,};
    memcpy(t_map, map, sizeof(map));
    int now_y = air.y1;
    int now_x = air.x1;
    int up[4] = {0,3,1,2};
    int dir = 0;
    while(1){
        int t_y = now_y;
        int t_x = now_x;
        now_y = now_y + dir_y[up[dir]];
        now_x = now_x + dir_x[up[dir]];
        if(now_y<0||now_y>r-1||now_x<0||now_x>c-1){
            dir++;
            now_y = t_y;
            now_x = t_x;
            continue;
        }
        if(map[now_y][now_x] == -1)
            break;
        if(map[t_y][t_x] == -1){
            t_map[now_y][now_x] = 0;
        }else{
        t_map[now_y][now_x] = map[t_y][t_x];
        }
    }
    
    
    now_y = air.y2;
    now_x = air.x2;
    int down[4] = {0,2,1,3};
    dir = 0;
    
    while(1){
        int t_y = now_y;
        int t_x = now_x;
        now_y = now_y + dir_y[down[dir]];
        now_x = now_x + dir_x[down[dir]];
        if(now_y<0||now_y>r-1||now_x<0||now_x>c-1){
            dir++;
            now_y = t_y;
            now_x = t_x;
            continue;
        }
        if(map[now_y][now_x] == -1)
            break;
        if(map[t_y][t_x] == -1){
            t_map[now_y][now_x] = 0;
        }else{
            t_map[now_y][now_x] = map[t_y][t_x];
        }
    }
    
    
    
    
    
    t_map[air.y1][air.x1] = -1;
    t_map[air.y2][air.x2] = -1;
    memcpy(map, t_map, sizeof(map));
    
    
    
    

}


void bfs(queue<pair<int,int>> queue){
    
    for(int i=0;i<t;i++){
        
        int size = queue.size();
        int t_map[MAX_R][MAX_R] = {0,};
        
        while(!queue.empty()){
            int now_y = queue.front().first;
            int now_x = queue.front().second;
          //  cout<<now_y<<" "<<now_x<<endl;
            queue.pop();
            int cnt = 0;
            int now_mon = map[now_y][now_x];
            
            for(int d=0;d<4;d++){
                int next_y = now_y + dir_y[d];
                int next_x = now_x + dir_x[d];
                if(next_y<0||next_y>r-1||next_x<0||next_x>c-1||map[next_y][next_x] == -1)
                    continue;
                cnt++;
                
                if(visited[next_y][next_x] == 0){
                    visited[next_y][next_x] = 1;
                    t_map[next_y][next_x] += now_mon/5;
                }else{
                    t_map[next_y][next_x] += now_mon/5;
                }
                
                
                
            }
            now_mon = now_mon - (now_mon/5)*cnt;
            t_map[now_y][now_x] += now_mon;
            
            
            
        }
        
        t_map[air.y1][air.x1] = -1;
        t_map[air.y2][air.x2] = -1;
        memcpy(map, t_map, sizeof(map));
        
        
        
        move();
        
        memset(visited,0,sizeof(visited));
        for(int j=0;j<r;j++){
            for(int k=0;k<c;k++){
                if(map[j][k] > 0){
                    visited[j][k] = 1;
                    queue.push(make_pair(j,k));
                }
            }
        }
        
        
    }
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(map[i][j] > 0)
                Answer += map[i][j];
        }
    }
    
    
    

}



int main(int argc, const char * argv[]) {
    scanf("%d %d %d",&r,&c,&t);
    queue<pair<int,int>> queue;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int temp = 0;
            scanf("%d",&temp);
            map[i][j] = temp;
            if(temp == -1){
                if(air.y1 == -1){
                    air.y1 = i;
                    air.x1 = j;
                }else{
                    air.y2 = i;
                    air.x2 = j;
                }
            }else if(temp > 0){
                queue.push(make_pair(i,j));
                visited[i][j] = 1;
            }
            
        }
        
    }
    
    bfs(queue);
    printf("%d\n",Answer);
    
    
    return 0;
}
