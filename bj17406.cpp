//
//  main.cpp
//  bj17406
//
//  Created by new_mac on 2019. 9. 6..
//  Copyright © 2019년 new_mac. All rights reserved.
//

//46분만에 풀이완료. 바로 정답.

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAX_N = 51;
int n,m,k;
int map[MAX_N][MAX_N];
int visited[6];
struct info{
    int y;
    int x;
    int s;
};
info mat[6];
int dir_y[5] = {0,-1,0,1,0};
int dir_x[5] = {-1,0,1,0,-1};
int answer = 100000;



int cal_row(int num){
    int sum = 0;
    for(int i=0;i<m;i++){
        sum += map[num][i];
    }
    return sum;
}

int find_min(){
    int result = 100000;
    for(int i=0;i<n;i++){
        int temp = cal_row(i);
        if(result > temp){
            result = temp;
        }
    }
    return result;
}

void print_m(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}


void go(int y,int x,int s){
    int t_map[MAX_N][MAX_N] = {0,};
    memcpy(t_map, map, sizeof(map));
    for(int i=1;i<=s;i++){
        int start_y = y + i;
        int start_x = x;
        int next_y = start_y;
        int next_x = start_x;
        
        int y_max = y+i;
        int y_min = y-i;
        int x_max = x+i;
        int x_min = x-i;
        
        
        int dir = 0;
        while(1){
            int t_y = next_y;
            int t_x = next_x;
            
            next_y = next_y + dir_y[dir];
            next_x = next_x + dir_x[dir];
            if(next_y == start_y && next_x == start_x && dir !=0){
                t_map[next_y][next_x] = map[t_y][t_x];
                break;
            }
            if(next_y<y_min||next_y>y_max||next_x<x_min||next_x>x_max){
                next_y = t_y;
                next_x = t_x;
                dir++;
                continue;
            }
            t_map[next_y][next_x] = map[t_y][t_x];
        
        }
    
        
    }
    memcpy(map, t_map, sizeof(map));
    

}

void dfs(int depth){
    int t_map[MAX_N][MAX_N];
    memcpy(t_map, map, sizeof(map));
    if(depth == k){
        int result  = find_min();
        if(result < answer)
            answer = result;
        return;
    }
    for(int i=0;i<k;i++){
        if(visited[i] == 0){
            visited[i] = 1;
            go(mat[i].y,mat[i].x,mat[i].s);
            dfs(depth+1);
            memcpy(map, t_map, sizeof(map));
            visited[i] = 0;
        }
    }
    

}


int main(int argc, const char * argv[]) {
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&map[i][j]);
        }
    }
    
    for(int i=0;i<k;i++){
        int y,x,s;
        scanf("%d %d %d",&y,&x,&s);
        mat[i] = info{y-1,x-1,s};
    }
    
    
    dfs(0);
    printf("%d\n",answer);
    
    
    
    
    return 0;
}
