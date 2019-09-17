//
//  main.cpp
//  bj15684
//
//  Created by new_mac on 2019. 8. 8..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//2시간 17분걸림. --> 우선 사다리들의 연결상태를 알았어야했는데 그부분을 실수해서 초반에 시간을 날렸다.
//2번째 실수는 사다리를 놓을수 있는지 check하는 함수에서 왼쪽은 확인할 필요가없이 현재와 다음칸만 확인하면 되었었는데 이부분을 실수했다.
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAX_N = 11;
const int MAX_H = 31;

int N,M,H;
int answer = -1;

struct info{
    int y;
    int x;
    int v;
};

info map[MAX_H][MAX_N];

int find_one(int num,int y){
    int now = y;
    while(1){
        
        now = now+1;
        if(now>H){
            now = -1;
            break;
        }
        if(map[now][num].v == 1)
            break;
        
    }
    return now;
}
void print_m(){
    for(int i=0;i<=H;i++){
        for(int j=0;j<=N;j++){
            printf("%d ",map[i][j].v);
        }
        printf("\n");
    }
    printf("\n");
}

int go(int num){//1부터
//    printf("%d ",num);
    int result = num;//x값
    int start = find_one(num,0);//y값
    if(start == -1)
        return num;
    
    while(1){
        
    //    int next_y = map[start][result].y;
        int next_x = map[start][result].x;
        start = find_one(next_x, start);
        result = next_x;
  //      printf("%d ",result);
        if(start == -1){
        break;
        }
        
        
    }
    return result;
}



bool check(){
    for(int i=1;i<=N;i++){
        if(go(i) != i)
            return false;
    }
    return true;

}

bool check_l(int y,int x){
    if(map[y][x].v == 1)
        return false;
    int right_x = x+1;
    if(right_x<=N){
        if(map[y][right_x].v == 1)
            return false;
    }
    return true;

}

void dfs(int depth,int num,int b_y,int b_x){
  
   
   
    if(depth == num){
        if(check())
            answer = depth;
        return;
    }
    int cnt = 0;
    for(int i=b_y;i<=H;i++){
        int j=0;
        if(cnt == 0)
            j=b_x;
        else
            j =1;
        for(;j<N;j++){
            if(check_l(i, j)){
                map[i][j] = info{i,j+1,1};
                map[i][j+1] = info{i,j,1};
                dfs(depth+1, num,i,j);
                map[i][j] = info{0,0,0};
                map[i][j+1] = info{0,0,0};
            }
            
            
        }
        cnt++;
    }
    
    

}

void simul(){
    for(int i=0;i<=3;i++){
        dfs(0, i, 1, 1);
        if(answer != -1)
            break;
    }
    printf("%d\n",answer);
    
}



int main(int argc, const char * argv[]) {
    scanf("%d %d %d",&N,&M,&H);
    for(int i=0;i<M;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        map[a][b] = info{a,b+1,1};
        map[a][b+1] = info{a,b,1};
        
        
    }
    
    
    simul();
    
    
    return 0;
}
