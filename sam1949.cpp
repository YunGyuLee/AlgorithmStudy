//
//  main.cpp
//  sam1949
//
//  Created by new_mac on 2019. 8. 9..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//흠... bfs로 풀려다가 실패했는데... 다시보자//
//bfs로 고민하다가 dfs로 풀었다 1시간 30분....
#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N = 9;
int map[MAX_N][MAX_N];
int visited[MAX_N][MAX_N][2];//공사를 했는지 안했는지. //1이 한거//0이 안한거
int N,K;

int dir_y[4] = {0,0,1,-1};
int dir_x[4] = {1,-1,0,0};
struct info{
    int y;
    int x;
    int pos;
    int high;

};
int max_h = -1;
int Answer = -1;


void dfs(int depth,int y,int x,int pos){
    
    for(int i=0;i<4;i++){
        int next_y = y + dir_y[i];
        int next_x = x + dir_x[i];
        if(next_y<0||next_y>N-1||next_x<0||next_x>N-1)
            continue;
        if(map[y][x] > map[next_y][next_x]){
            if(visited[next_y][next_x][pos] == 1)
                continue;
            visited[next_y][next_x][pos] = 1;
            dfs(depth+1, next_y, next_x, pos);
            visited[next_y][next_x][pos] = 0;
        }else{
            if(pos == 0){
                if(visited[next_y][next_x][pos] == 1)
                    continue;
                if(map[next_y][next_x]-K <= map[y][x]-1){
                    int temp = map[next_y][next_x];
                    map[next_y][next_x] = map[y][x] -1;
                    visited[next_y][next_x][1] = 1;
                    dfs(depth+1, next_y, next_x, 1);
                    visited[next_y][next_x][1] = 0;
                    map[next_y][next_x] = temp;
                }
            
            }
        }
        
        
        
    }
    
    if(Answer < depth)
        Answer = depth;
    

}




void bfs(int y,int x){
    
    int visited_[MAX_N][MAX_N][2] = {0,};
    queue<info> queue;
    queue.push(info{y,x,0,0});
    visited_[y][x][0] = 1;
    while(!queue.empty()){
        int now_y = queue.front().y;
        int now_x = queue.front().x;
        int now_pos = queue.front().pos;
        queue.pop();
        for(int i = 0;i<4;i++){
            int next_y = now_y + dir_y[i];
            int next_x = now_x + dir_x[i];
            if(next_y<0||next_y>N-1||next_x<0||next_x>N-1)
                continue;
            if(map[next_y][next_x] < map[now_y][now_x]){
                if(visited_[next_y][next_x][now_pos] >= visited_[now_y][now_x][now_pos] + 1)
                    continue;
                visited_[next_y][next_x][now_pos] = visited_[now_y][now_x][now_pos] + 1;
                queue.push(info{next_y,next_x,now_pos,map[next_y][next_x]});
            }else{
                if(now_pos == 0 && map[next_y][next_x] -K <= map[now_y][now_x]-1){
                    if(visited_[next_y][next_x][1] >= visited_[now_y][now_x][now_pos] + 1)
                        continue;
                    map[next_y][next_x] = map[now_y][now_x] -1;
                    visited_[next_y][next_x][1] = visited_[now_y][now_x][now_pos] + 1;
                    queue.push(info{next_y,next_x,1,0});
                }
            }
            
        
        }
        
        
    
    }
     for(int k=0;k<2;k++){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
        //    printf("%d ",visited_[i][j][k]);
                if(visited_[i][j][k] > Answer)
                    Answer = visited_[i][j][k];
            }
      //  printf("\n");
        }
      //   printf("\n");
    
}
}



int main(int argc, const char * argv[]) {
    int T = 0;
    scanf("%d",&T);
    for(int testcase = 1;testcase<=T;testcase++){
        scanf("%d %d",&N,&K);
        max_h = -1;
        memset(visited,0,sizeof(visited));
        Answer = -1;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                int temp = 0;
                scanf("%d",&temp);
                map[i][j] = temp;
                if(max_h < temp)
                    max_h = temp;
            }
        }
        int t_map[MAX_N][MAX_N];
        memcpy(t_map, map, sizeof(map));
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(map[i][j] == max_h){
               /*     visited[i][j][0] = 1;
                    dfs(1,i, j,0);
                    visited[i][j][0] = 0;*/
                  //  cout<<i<<" "<<j<<endl;
                    bfs(i, j);
                    memcpy(map, t_map, sizeof(map));
                }
            }
        }
        
        printf("#%d %d\n",testcase,Answer);
        
    
    }
    
    
    return 0;
}
