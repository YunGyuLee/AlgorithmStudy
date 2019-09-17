//
//  main.cpp
//  bj1799
//
//  Created by new_mac on 2019. 8. 8..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//흠... 이건 최적화를 해야하는 문제...
//체스판을 2부분으로 나누어야한다.. (전체 n을 줄이는 방법)
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

const int MAX_N = 10;
int n;
int map[MAX_N][MAX_N];
int dir_y[4] = {1,1,-1,-1};
int dir_x[4] = {1,-1,1,-1};
int answer = -1;
int pos;
int Answer = -1;
void one_dir(int y,int x,int d){
    int now_y = y;
    int now_x = x;
    while (1) {
        now_y = now_y + dir_y[d];
        now_x = now_x + dir_x[d];
        if(now_y<0||now_y>n-1||now_x<0||now_x>n-1)
            break;
        map[now_y][now_x] = 1;
    }

}

void mark(int y,int x){
    map[y][x] = 1;
    for(int i=0;i<4;i++){
        one_dir(y, x, i);
    }

}


void dfs1(int depth,int b_y,int b_x){
    int temp[MAX_N][MAX_N];
    memcpy(temp, map, sizeof(map));
    
        if(answer < depth)
            answer = depth;
    
    int cnt = 0;
    for(int i=b_y;i<n;i++){
        int j =0;
        if(cnt == 0)
            j = b_x;
        else
            j = 0;
        for(;j<n;j++){
            
            if((i+j)%2 == 0)
                continue;
            if(map[i][j] == 0){
                mark(i, j);
                dfs1(depth+1,i,j);
                memcpy(map, temp, sizeof(map));
            }
        }
        cnt++;
    }
    
    

}


void dfs2(int depth,int b_y,int b_x){
    int temp[MAX_N][MAX_N];
    memcpy(temp, map, sizeof(map));
    
        if(answer < depth)
            answer = depth;
   
    int cnt = 0;
    for(int i=b_y;i<n;i++){
        int j =0;
        if(cnt == 0)
            j = b_x;
        else
            j = 0;
        for(;j<n;j++){
            
            if((i+j)%2 != 0)
                continue;
            if(map[i][j] == 0){
                mark(i, j);
                dfs2(depth+1,i,j);
                memcpy(map, temp, sizeof(map));
            }
        }
        cnt++;
    }
    
    
    
}



int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int temp;
            scanf("%d",&temp);
            if(temp == 0)
                map[i][j] = 1;
            else{
                pos++;
                map[i][j] = 0;
            }
        }
    }
    int sum = 0;
    dfs1(0, 0, 0);
    sum += answer;
    answer = -1;
    dfs2(0,0,0);
    sum +=answer;
    cout<<sum<<endl;
    
    
    return 0;
}
