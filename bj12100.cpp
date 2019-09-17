//
//  main.cpp
//  bj12100
//
//  Created by new_mac on 2019. 9. 1..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//1시간 17분 걸림. --> 코드 자체를 구현하는 시간보다 검증하는데 많은 시간을 보낸듯. 처음에 move함수를 짤때 시간이 좀 오래걸렸다.

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const int MAX_N = 21;
int n;
int dir_y[4] = {0,0,1,-1};
int dir_x[4] = {1,-1,0,0};
struct info{
    int value;
    int is_sum;
};
info map[MAX_N][MAX_N];
int answer = -1;



void print_m(info map[MAX_N][MAX_N]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",map[i][j].value);
        }
        printf("\n");
        
    }
    printf("\n");
    
}


void move_R(int num,int dir){//행 이동
    if(dir == 0){//오른쪽 이동
        info t_map[MAX_N] = {0,};
        for(int i=n-1;i>=0;i--){
            if(map[num][i].value != 0){
                
                int next = i;
                while(1){
                    int t_next = next;
                    next = next + dir_x[dir];
                    if(next>n-1){
                        next = t_next;
                        break;
                    }
                    if(t_map[next].value != 0){
                        next = t_next;
                        break;
                    }
                    
                    
                }
                
                if(next == n-1){
                    t_map[next].value = map[num][i].value;
                    continue;
                }
                
                if(t_map[next+1].is_sum == 0 && t_map[next+1].value == map[num][i].value){
                    t_map[next+1].value += map[num][i].value;
                    t_map[next+1].is_sum = 1;
                }else{
                    t_map[next].value = map[num][i].value;
                }
                
                
                
                
            }
            
            
        }
        
        for(int i=0;i<n;i++){
            map[num][i].value = t_map[i].value;
        }
        
        
    }else if(dir == 1){
        info t_map[MAX_N] = {0,};
        for(int i=0;i<n;i++){
            if(map[num][i].value != 0){
                int next = i;
                while(1){
                    int t_next = next;
                    next = next + dir_x[dir];
                    if(next<0){
                        next = t_next;
                        break;
                    }
                    if(t_map[next].value != 0){
                        next = t_next;
                        break;
                    }
                    
                    
                }
                
                if(next == 0){
                    t_map[next].value = map[num][i].value;
                    continue;
                }
                
                if(t_map[next-1].is_sum == 0 && t_map[next-1].value == map[num][i].value){
                    t_map[next-1].value += map[num][i].value;
                    t_map[next-1].is_sum = 1;
                }else{
                    t_map[next].value = map[num][i].value;
                }
                
                
                
                
            }
            
            
        }
        
        for(int i=0;i<n;i++){
            map[num][i].value = t_map[i].value;
        }
    }
    
    

}


void move_C(int num,int dir){
    if(dir == 2){//아래쪽 이동
        info t_map[MAX_N] = {0,};
    
        for(int i=n-1;i>=0;i--){
            if(map[i][num].value != 0){
                
                int next = i;
                while(1){
                    int t_next = next;
                    next = next + dir_y[dir];
                    if(next>n-1){
                        next = t_next;
                        break;
                    }
                    if(t_map[next].value != 0){
                        next = t_next;
                        break;
                    }
                    
                    
                }
                
                if(next == n-1){
                    t_map[next].value = map[i][num].value;
                    continue;
                }
                
                if(t_map[next+1].is_sum == 0 && t_map[next+1].value == map[i][num].value){
                    t_map[next+1].value += map[i][num].value;
                    t_map[next+1].is_sum = 1;
                }else{
                    t_map[next].value = map[i][num].value;
                }
                
                
                
                
            }
            
            
        }
        
        for(int i=0;i<n;i++){
            map[i][num].value = t_map[i].value;
        }
        
        
    }else if(dir == 3){
        info t_map[MAX_N] = {0,};
        for(int i=0;i<n;i++){
            if(map[i][num].value != 0){
                int next = i;
                while(1){
                    int t_next = next;
                    next = next + dir_y[dir];
                    if(next<0){
                        next = t_next;
                        break;
                    }
                    if(t_map[next].value != 0){
                        next = t_next;
                        break;
                    }
                    
                    
                }
                
                if(next == 0){
                    t_map[next].value = map[i][num].value;
                    continue;
                }
                
                if(t_map[next-1].is_sum == 0 && t_map[next-1].value == map[i][num].value){
                    t_map[next-1].value += map[i][num].value;
                    t_map[next-1].is_sum = 1;
                }else{
                    t_map[next].value = map[i][num].value;
                }
                
                
                
                
            }
            
            
        }
        
        for(int i=0;i<n;i++){
            map[i][num].value = t_map[i].value;
        }
    }
    
    
    

}


void move(int dir){
    if(dir == 0){
        for(int i=0;i<n;i++){
            move_R(i, dir);
        }
    }else if(dir == 1){
        for(int i=0;i<n;i++){
            move_R(i, dir);
        }
    }else if(dir == 2){
        for(int i=0;i<n;i++){
            move_C(i, dir);
        }
    }else if(dir == 3){
        for(int i=0;i<n;i++){
            move_C(i, dir);
        }
    }
    
    
    
}


int find_max(){
    int result = -1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(result < map[i][j].value)
                result = map[i][j].value;
        }
    }
    return result;
}


void dfs(int depth){
   
    if(depth == 5){
        int result = find_max();
        if(result > answer)
            answer = result;
        return;
    }
    info t_map[MAX_N][MAX_N];
    memcpy(t_map, map, sizeof(map));
    
    
    
    for(int i=0;i<4;i++){
        move(i);
        dfs(depth+1);
        memcpy(map, t_map, sizeof(map));
    }
    
    
    
}



int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&map[i][j].value);
        }
    }
    
    dfs(0);
    printf("%d\n",answer);
    
    return 0;
}
