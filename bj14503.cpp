//
//  main.cpp
//  bj14503
//
//  Created by new_mac on 2019. 9. 4..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//40분 만에 풀이완료.

#include <iostream>
#include <stdio.h>
using namespace std;
const int MAX_N = 51;
int n,m;
int map[MAX_N][MAX_N];

int dir_y[4] = {-1,0,1,0};
int dir_x[4] = {0,1,0,-1};


void print_m(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int find_d(int dir){
    int result = 0;
    if(dir == 0){
        result = 3;
    }else{
        result = dir-1;
    }
    return result;
}

int re_dir(int dir){
    if(dir == 0)
        return 2;
    else if(dir == 1)
        return 3;
    else if(dir == 2)
        return 0;
    else if(dir == 3)
        return 1;
    else
        return -1;
}

int move(int y,int x,int d){
    int result = 0;
    int next_y = y;
    int next_x = x;
    int next_d = d;
    int flag = 1;
    int check = 0;
    while(1){
        
        if(flag == 1){
            result++;
            map[next_y][next_x] = 2;
        }
        int t_y = next_y;
        int t_x = next_x;
        int t_d = next_d;
        
        next_d = find_d(next_d);
        check++;
        if(check == 5){
            
            next_y = next_y + dir_y[re_dir(t_d)];
            next_x = next_x + dir_x[re_dir(t_d)];
            if(map[next_y][next_x] == 2){
                check = 0;
                flag = 2;
                next_d = t_d;
                continue;
            }else{
                break;
            }
        
        }
            
        next_y = next_y + dir_y[next_d];
        next_x = next_x + dir_x[next_d];
        if(map[next_y][next_x] == 0){
            flag = 1;
            check = 0;
            continue;
        }else{
            next_y = t_y;
            next_x = t_x;
            flag = 2;
            continue;
        }
        
        
        
    
    
    
    }
    
    
    return result;

}



int main(int argc, const char * argv[]) {
    scanf("%d %d",&n,&m);
    int y,x,d;
    scanf("%d %d %d",&y,&x,&d);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&map[i][j]);
        }
    }
    
    printf("%d\n",move(y,x,d));
    
    
    return 0;
}
