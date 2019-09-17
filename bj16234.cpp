//
//  main.cpp
//  bj16234
//
//  Created by new_mac on 2019. 8. 3..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//최종 정답 1시간 10분 걸림.
//시간 초과 2번 --> 최적화를 생각안하고 대충풀어서 시간초과...


#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
using namespace std;
const int MAX_N = 102;
const int MAX_Q = 2500;
int n,L,R;
int map[MAX_N][MAX_N];
int line[MAX_N][MAX_N][4];//4방향의 국경선이 닫혀있는지 여부 --> 0은 닫혀있는 것.
int visited[MAX_N][MAX_N];
int dir_y[4] = {0,0,-1,1};
int dir_x[4] = {1,-1,0,0};

struct info{
    int y;
    int x;
};

info q[MAX_Q];
int head;
int rear;
int q_size;
bool empty(){
    if(head == rear)
        return true;
    else
        return false;
}

bool full(){
    if((rear+1)%MAX_Q == head)
        return true;
    else
        return false;
    
}

info front(){
    info result = {-1,-1};
    if(empty())
        return result;
    else{
        result = q[head];
        return result;
    }
        

}

bool push(info a){
    if(full())
        return false;
    else{
        q[rear] = a;
        q_size++;
        rear = (rear+1)%MAX_Q;
        return true;
    }
}

bool pop(){
    if(empty())
        return false;
    else{
        q_size--;
        head = (head+1)%MAX_Q;
        return true;
    }
    
}


bool open_line(){
    bool result = false;
    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            for(int i=0;i<4;i++){
                int next_y = y + dir_y[i];
                int next_x = x + dir_x[i];
                if(next_y<0||next_y>n-1||next_x<0||next_x>n-1)
                    continue;
                if(abs(map[y][x] - map[next_y][next_x]) >= L && abs(map[y][x] - map[next_y][next_x]) <=R ){
                    line[y][x][i] = 1;
                    result = true;
                }
            
            
            }
            
        }
    }
    return result;

}

void close_line(){
    memset(line,0,sizeof(line));
}


void print_m(){
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int bfs(int y,int x,int num){
    int total = 0;
    int cnt = 1;
    push(info{y,x});
    visited[y][x] = num;
    total += map[y][x];
    while(!empty()){
        int now_y = front().y;
        int now_x = front().x;
        pop();
        for(int i=0;i<4;i++){
            int next_y = now_y + dir_y[i];
            int next_x = now_x + dir_x[i];
            if(next_y<0||next_y>n-1||next_x<0||next_x>n-1)
                continue;
            if(line[now_y][now_x][i] == 0)//닫혀있으면
                continue;
            if(visited[next_y][next_x] != 0)
                continue;
            visited[next_y][next_x] = num;
            total += map[next_y][next_x];
            cnt++;
            push(info{next_y,next_x});
            
            
        }
        
        
    }
    return total/cnt;
}

void go(int size,int num){
    
    
    
}



bool move(){
    vector<int> num;
    bool result = false;
    int cnt = 1;
    if(open_line()){
        result =true;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j] == 0){
                    num.push_back(bfs(i, j, cnt));
                    cnt++;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j] != 0){
                    map[i][j] = num[visited[i][j]-1];
                }
            }
        }
        num.clear();
        close_line();
    }
        
    return result;
    
}


void simul(){
    for(int i=0;i<=2000;i++){
        memset(visited,0,sizeof(visited));
        if(!move()){
            printf("%d\n",i);
            return;
        }
    }

}



int main(int argc, const char * argv[]) {
    scanf("%d %d %d",&n,&L,&R);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&map[i][j]);
        }
    }
    
    simul();
    
    
    return 0;
}
