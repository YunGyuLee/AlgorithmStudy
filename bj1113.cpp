//
//  main.cpp
//  bj1113
//
//  Created by new_mac on 2019. 8. 27..
//  Copyright © 2019년 new_mac. All rights reserved.
//

//물을 못채우는 경우까지 생각을 해줘야한다...
// --> visited를 초기화 할 필요가 없다.
#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <queue>

using namespace std;
const int MAX_N = 52;
int n,m;
int map[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int dir_y[4] = {0,0,-1,1};
int dir_x[4] = {1,-1,0,0};
int answer;

void print_m(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",visited[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}

void init_visited(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j] = 0;
        }
    }
    
}

bool is_fill(int y,int x){//넘치는지 확인하는 함수
    int height = map[y][x];
    queue<pair<int,int>> queue;
   
    visited[y][x] = -height;
    queue.push(make_pair(y,x));
    while(!queue.empty()){
        int now_y = queue.front().first;
        int now_x = queue.front().second;
        queue.pop();
        
        for(int i=0;i<4;i++){
            int next_y = now_y + dir_y[i];
            int next_x = now_x + dir_x[i];
            
            if(next_y<0||next_x<0||next_y>n-1||next_x>m-1){
                while(!queue.empty()){
                    queue.pop();
                }
                return false;
            }
            
        
            if(visited[next_y][next_x] == -height)
                continue;
            
            if(map[next_y][next_x] == height){
                visited[next_y][next_x] = -height;
                queue.push(make_pair(next_y,next_x));
            }
            
            
        }
    
    
    }
    
    return true;
    

}

void fill_water(int y,int x,int flag){//flag로 실제로 물을 채우는 것인지 이후에 정보전달을 위해 물을 채우는 것인지 구분.
    map[y][x] += 1;
    int height = map[y][x];
    if(flag == 1)
        answer++;
    queue<pair<int,int>> queue;
    visited[y][x] = height;
    queue.push(make_pair(y,x));
    while(!queue.empty()){
        int now_y = queue.front().first;
        int now_x = queue.front().second;
        queue.pop();
        for(int i=0;i<4;i++){
            int next_y = now_y + dir_y[i];
            int next_x = now_x + dir_x[i];
            
            
            if(visited[next_y][next_x] == height)
                continue;
            
            if(map[next_y][next_x]+1 == height){
                map[next_y][next_x] += 1;
                if(flag==1)
                    answer++;
                visited[next_y][next_x] = height;
                queue.push(make_pair(next_y,next_x));
            }
            
            
        }
        
        
    }
    
    

    
}



void fill(int y,int x){
   
    int flag = 1;
        if(!is_fill(y, x))
            flag = 0;
        fill_water(y, x,flag);
    
}



void go(){
    
    
    for(int k=1;k<=9;k++){
        init_visited();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j] == k && visited[i][j] ==0 ){
                fill(i, j);
            }
            
        }
    }
    }

}



int main(int argc, const char * argv[]) {
    
    
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        for(int j=0;j<m;j++){
            map[i][j] = temp[j] - '0';
        }
    }
    
    go();
    printf("%d\n",answer);
    
    return 0;
}
