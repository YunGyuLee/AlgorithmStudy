//
//  main.cpp
//  bj17143_re
//
//  Created by new_mac on 2019. 8. 27..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//백준 사이트에서 재채점이 된 결과 시간초과가 떴길래 다시 풀어본 문제...
// --> 58분만에 풀이완료. 상어의 이동의 반복구간을 스킵하니 정답처리됨.
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAX_R = 102;
int r,c,m;
struct info{
    int y;
    int x;
    int s;
    int d;
    int z;
};


info map[MAX_R][MAX_R];

int dir_y[4] = {-1,1,0,0};
int dir_x[4] = {0,0,1,-1};


void print_m(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d ",map[i][j].z);
        }
        printf("\n");
    }
    printf("\n");
}


int re_dir(int dir){
    if(dir == 0){
        return 1;
    }else if(dir == 1)
        return 0;
    else if(dir == 2)
        return 3;
    else if(dir == 3)
        return 2;
    else
        return -1;
}


info move(int y,int x){
    int now_y = y;
    int now_x = x;
    int now_s = map[y][x].s;
    int now_d = map[y][x].d;
    if(now_d == 0){
        if(now_y != r-1)
            now_s = now_s%(2*(r-1));
    }else if(now_d == 1){
        if(now_y != 0)
            now_s = now_s%(2*(r-1));
    }else if(now_d == 2){
        if(now_x != 0)
             now_s = now_s%(2*(c-1));
    }else if(now_d == 3){
        if(now_x != c-1)
             now_s = now_s%(2*(c-1));
    }
    
    
    int now_z = map[y][x].z;
    for(int i=0;i<now_s;i++){
        int t_y = now_y;
        int t_x = now_x;
        now_y = now_y + dir_y[now_d];
        now_x = now_x + dir_x[now_d];
        if(now_y<0||now_y>r-1||now_x<0||now_x>c-1){
            now_d = re_dir(now_d);
            now_y = t_y + dir_y[now_d];
            now_x = t_x + dir_x[now_d];
        }
        
        
    }
    
    return info{now_y,now_x,now_s,now_d,now_z};
    
    
    
    
    
}



void move_S(){
    info t_map[MAX_R][MAX_R] = {0,};
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(map[i][j].z != 0){
                info temp = move(i,j);
                if(t_map[temp.y][temp.x].z == 0){
                    t_map[temp.y][temp.x] = temp;
                }else{
                    if(t_map[temp.y][temp.x].z < temp.z){
                        t_map[temp.y][temp.x] = temp;
                    }
                }
                
                
                
            }
        
        }
    }
    
    memcpy(map, t_map, sizeof(map));
    
}




void go(){
    int result = 0;
    for(int i=0;i<c;i++){
        //작살
        for(int j=0;j<r;j++){
            if(map[j][i].z != 0){
                result += map[j][i].z;
                map[j][i] = info{0,0,0,0,0};
                break;
            }
        }
        
        move_S();
        //상어이동
        
        
        
        
    }
    
    printf("%d\n",result);
    
    
}





int main(int argc, const char * argv[]) {
    scanf("%d %d %d",&r,&c,&m);
    for(int i=0;i<m;i++){
        int y,x,s,d,z;
        scanf("%d %d %d %d %d",&y,&x,&s,&d,&z);
        map[y-1][x-1] = info{y-1,x-1,s,d-1,z};
    }
    
    go();
    
    return 0;
}
