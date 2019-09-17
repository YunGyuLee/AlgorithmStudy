//
//  main.cpp
//  bj15685
//
//  Created by new_mac on 2019. 8. 6..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//똥싸는 시간제외 43분만에 풀이완료.
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
const int MAX_S = 101;
int map[MAX_S][MAX_S];//0~100
int n;
int dir_y[4] = {0,-1,0,1};
int dir_x[4] = {1,0,-1,0};



int find_d(int dir){
    if(dir == 3)
        return 0;
    else
        return dir+1;

}

void print_m(){
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void make_dragon(int y,int x,int dir,int gen){
    vector<int> info;
    info.push_back(dir);
    map[y][x] = 1;
    int end_y = y+dir_y[dir];
    int end_x = x+dir_x[dir];
    map[end_y][end_x] = 1;
    
    for(int i=0;i<gen;i++){
        int size = info.size();
        for(int j=size-1;j>=0;j--){
            int next_d = find_d(info[j]);
            end_y = end_y + dir_y[next_d];
            end_x = end_x + dir_x[next_d];
            map[end_y][end_x] = 1;
            info.push_back(next_d);
        }
        
        
    
    }
    
    
    
    
    

}

int find_rec(){
    int result = 0;
    for(int i=0;i<MAX_S-1;i++){
        for(int j=0;j<MAX_S-1;j++){
            if(map[i][j] == 1 && map[i][j+1] == 1 && map[i+1][j] == 1 && map[i+1][j+1] == 1){
                result++;
            }
            
            
        }
    }

    return result;
}


int main(int argc, const char * argv[]) {
    
    
    
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int x,y,d,g;
        scanf("%d %d %d %d",&x,&y,&d,&g);
        make_dragon(y, x, d, g);
        //여기에 드래곤 커브를 그리는 함수
        
    
    }
    printf("%d",find_rec());
    //맵에서 정사각형 찾기
    
    
    
    return 0;
}
