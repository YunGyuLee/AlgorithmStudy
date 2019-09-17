//
//  main.cpp
//  sam2112
//
//  Created by new_mac on 2019. 8. 7..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//첫제출 --> 제한시간 초과 1시간 30분 걸림.
//흠... 그냥 간단하게 생각했으면 풀릴문제였다...
//이해가 안가는 부분이... dfs를 돌릴때 이전 범위는 탐색하지 않는것과 탐색하는것이 시간적으로 큰차이가없는데 그 코드의 차이로 시간초과가 난다... --> 내가 잘못생각한 것이였음. nPn을 하고있었다. nCm으로 풀어야 풀리는문제
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX_D = 13;
const int MAX_W = 20;
int map[MAX_D][MAX_W];
int D,W,K;
int answer = -1;
int visited[MAX_D];
vector<int> v;
bool check_c(int num){
    int cnt = 1;
    for(int i=0;i<D-1;i++){
        
        if(map[i][num] == map[i+1][num]){
            cnt++;
        }else
            cnt = 1;
        if(cnt == K)
            return true;
        
    }
    
    return false;
}

vector<int> select_;

bool check(){
    for(int i=0;i<W;i++){
        if(!check_c(i)){
            return false;
        
        }
    }
    
    return true;
}


void put_m(int num,int input){
    for(int i=0;i<W;i++){
        map[num][i] = input;
    }

}

void dfs(int depth,int num,int before){//before!!!! 이 before가 nCm을 가능하게하는 코드!
    
    
    if(depth == num){
        if(check())
            answer = depth;
        return;
    }
   
    for(int i=0;i<D;i++){
            if(visited[i] == 1)
                continue;
            if(visited[i]==0){
            for(int j=0;j<2;j++){
                
                    visited[i] = 1;
                    int temp[MAX_W] = {0,};
                    for(int x = 0;x<W;x++){
                        temp[x] = map[i][x];
                    }
                    put_m(i, j);
                    dfs(depth+1,num,i+1);
                    for(int x=0;x<W;x++){
                        map[i][x] = temp[x];
                    }
                    visited[i] = 0;
                }
            
    }
    
    }
    
    
    
}

void dfs2(int depth,int num){
    int temp[MAX_D][MAX_W];
    memcpy(temp, map, sizeof(map));
    if(depth == num){
        if(check())
            answer = depth;
        return;
    }
    
    
            for(int j=0;j<2;j++){
                put_m(v[depth], j);
                dfs2(depth+1, num);
                memcpy(map,temp,sizeof(map));
            }
        
    
    
    

}


bool select_num(int num){
    
    int temp[MAX_D][MAX_W];
    memcpy(temp, map, sizeof(map));
    for(int i=0;i<D;i++){
        if(i<num)
            select_.push_back(1);
        else
            select_.push_back(0);
    }
    sort(select_.begin(),select_.end());
    do{
        v.clear();
        for(int i=0;i<D;i++){
            if(select_[i] == 1)
                v.push_back(i);
        }
        
        dfs2(0,num);
        if(answer != -1)
            break;
        
    
    }while(next_permutation(select_.begin(), select_.end()));
    select_.clear();
    
    return false;

}



void simul(){
    for(int i=0;i<=D;i++){
        select_num(i);
        if(answer != -1)
            break;
    }
    
}



int main(int argc, const char * argv[]) {
    int T = 0;
    scanf("%d",&T);
    for(int testcase = 1;testcase<=T;testcase++){
        scanf("%d %d %d",&D,&W,&K);
        answer = -1;
        select_.clear();
        memset(visited,0,sizeof(visited));
        for(int i=0;i<D;i++){
            for(int j=0;j<W;j++){
                scanf("%d",&map[i][j]);
            }
        }
        
        simul();
        printf("#%d %d\n",testcase,answer);
    
    
    }
    return 0;
}
