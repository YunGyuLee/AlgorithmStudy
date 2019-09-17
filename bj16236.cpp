//
//  main.cpp
//  bj16236
//
//  Created by new_mac on 2019. 8. 1..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//43분 만에 풀이완료.


#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_N = 21;
int map[MAX_N][MAX_N];
int n;
int size = 2;
int s_y,s_x;

struct info{
    int y;
    int x;
    int t;
};

int dir_y[4] = {0,0,1,-1};
int dir_x[4] = {1,-1,0,0};

bool comp(info a, info b){
    if(a.t < b.t)
        return true;
    else if(a.t == b.t){
        if(a.y < b.y){
            return true;
        }else if(a.y == b.y){
            if(a.x < b.x)
                return true;
            else
                return false;
        }else{
            return false;
        }
    }else{
        return false;
    }

}


vector<info> bfs(int y,int x){
    int visited[MAX_N][MAX_N] = {0,};
    queue<pair<int,int>> queue;
    vector<info> result;
    queue.push(make_pair(y,x));
    visited[y][x] = 1;
    while(!queue.empty()){
        int now_y = queue.front().first;
        int now_x = queue.front().second;
        queue.pop();
        for(int i=0;i<4;i++){
            int next_y = now_y + dir_y[i];
            int next_x = now_x + dir_x[i];
            if(next_y<0 || next_y>n-1||next_x<0 || next_x>n-1)
                continue;
            if(visited[next_y][next_x] != 0)
                continue;
            if(map[next_y][next_x] == 0){
                queue.push(make_pair(next_y, next_x));
                visited[next_y][next_x]  = visited[now_y][now_x] + 1;
                continue;
            }
            
            if(map[next_y][next_x] > size)
                continue;
            else if(map[next_y][next_x] == size){
                queue.push(make_pair(next_y,next_x));
                visited[next_y][next_x] = visited[now_y][now_x] + 1;
            }else if(map[next_y][next_x] < size){
                visited[next_y][next_x] = visited[now_y][now_x] + 1;
                result.push_back(info{next_y,next_x,visited[next_y][next_x]});
            }
            
            
            
        }
        
    
    }
    
    return result;

}

void print_m(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void simul(){
    
    int t = 0;
    int eat = 0;
    while(1){
        vector<info> result = bfs(s_y, s_x);
        if(result.size() == 0)
            break;
        sort(result.begin(), result.end(), comp);
        int next_y = result[0].y;
        int next_x = result[0].x;
        int _t = result[0].t - 1;
        map[s_y][s_x] = 0;
        eat = eat + 1;
        if(eat == size){
            size++;
            eat = 0;
        }
        map[next_y][next_x] = 9;
        s_y = next_y;
        s_x = next_x;
        t += _t;
      
        
    }
    
    printf("%d\n",t);

}



int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int temp = 0;
            scanf("%d",&temp);
            map[i][j] = temp;
            if(temp == 9){
                s_y = i;
                s_x = j;
            }
        }
    }
    
    
    simul();
    
    
    return 0;
}
