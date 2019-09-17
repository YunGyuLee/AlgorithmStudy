//
//  main.cpp
//  bj17070
//
//  Created by new_mac on 2019. 8. 29..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//1시간 7분만에 정답 --> 시간이 244ms인데... 최적화 해보자.
//함수의 인자와 전역변수의 값이 같아서 오류가 떴었다. 전역변수는 굳이인자로 넘겨줄 필요가 없다.
#include <iostream>
#include <stdio.h>
using namespace std;
const int MAX_N = 17;
int map[MAX_N][MAX_N];
int n;
int state;//파이프의 상태 : 1:가로,2:세로,3:대각선
struct info{
    int y;
    int x;
};

int dir_y[3] = {0,1,1};
int dir_x[3] = {1,0,1};

info pipe_h;//(y,x)
info pipe_t;
int answer;

int s_dir[3][3] =
{{1,0,1},{0,1,1},{1,1,1}};

//디버그용 코드
void print_pipe(){
    
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(pipe_h.y == i && pipe_h.x == j){
                printf("%d ",1);
                continue;
            }
            if(pipe_t.y == i && pipe_t.x == j){
                printf("%d ",1);
                continue;
            }
            printf("%d ",0);
        }
        printf("\n");
    }
    printf("\n");
}


bool check_four(int y,int x,int dir){
    
    if(dir == 0 || dir == 1){
        int next_y = y + dir_y[dir];
        int next_x = x + dir_x[dir];
            if(next_y>n-1||next_x>n-1)
                return false;
            if(map[next_y][next_x] == 1)
                return false;
    
        return true;
    }else{
    
        if(y+1>n-1||x+1>n-1)
            return false;
    
        for(int i=y;i<y+2;i++){
            for(int j=x;j<x+2;j++){
                if(map[i][j] == 1)
                    return false;
            }
        }
    return true;
    }
    
}


bool check(int State,int dir){
 

    if(s_dir[State-1][dir] == 1){
        if(check_four(pipe_h.y, pipe_h.x, dir))
            return true;
        else
            return false;
    }else
        return false;
    
}



void move(int State,int dir){
    if(State == 1){
        if(dir == 0){
            pipe_h = info{pipe_h.y + dir_y[dir],pipe_h.x + dir_x[dir]};
            pipe_t = info{pipe_t.y + dir_y[0],pipe_t.x + dir_x[0]};
            state = 1;
            return;
        }else if(dir == 2){
            pipe_h = info{pipe_h.y + dir_y[dir],pipe_h.x + dir_x[dir]};
            pipe_t = info{pipe_t.y + dir_y[0],pipe_t.x + dir_x[0]};
            state = 3;
            return;
        }else
            return;
        
    }else if(State == 2){
        if(dir == 1){
            pipe_h = info{pipe_h.y + dir_y[dir],pipe_h.x + dir_x[dir]};
            pipe_t = info{pipe_t.y + dir_y[1],pipe_t.x + dir_x[1]};
            state = 2;
            return;
        }else if(dir == 2){
            pipe_h = info{pipe_h.y + dir_y[dir],pipe_h.x + dir_x[dir]};
            pipe_t = info{pipe_t.y + dir_y[1],pipe_t.x + dir_x[1]};
            state = 3;
            return;
        }else
            return;
    }else if(State == 3){
        if(dir == 0){
            pipe_h = info{pipe_h.y + dir_y[dir],pipe_h.x + dir_x[dir]};
            pipe_t = info{pipe_t.y + dir_y[2],pipe_t.x + dir_x[2]};
            state = 1;
            return;
        }else if(dir == 1){
            pipe_h = info{pipe_h.y + dir_y[dir],pipe_h.x + dir_x[dir]};
            pipe_t = info{pipe_t.y + dir_y[2],pipe_t.x + dir_x[2]};
            state = 2;
            return;
        }else if(dir == 2){
            pipe_h = info{pipe_h.y + dir_y[dir],pipe_h.x + dir_x[dir]};
            pipe_t = info{pipe_t.y + dir_y[2],pipe_t.x + dir_x[2]};
            state = 3;
            return;
        }
    }

}



void dfs(){
    for(int i=0;i<3;i++){
        if(s_dir[state-1][i]==0)
            continue;
        if(check(state, i)){
            int t_state = state;
            info t_pipe_h = pipe_h;
            info t_pipe_t = pipe_t;
            move(state,i);
            dfs();
            pipe_h = t_pipe_h;
            pipe_t = t_pipe_t;
            state = t_state;
        }
    }
    
    if(pipe_h.y == n-1 && pipe_h.x == n-1)
        answer++;
    


}



int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&map[i][j]);
        }
    }
    
    pipe_h = info{0,1};
    pipe_t = info{0,0};
    state = 1;
   
    dfs();
    printf("%d\n",answer);
    return 0;
}
