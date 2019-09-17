//
//  main.cpp
//  sam2105
//
//  Created by new_mac on 2019. 8. 8..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//1시간 22분 풀이완료... 흠 왜 처음에 답이 안나왔던것인지 찾아야한다... 무엇이징...
//결국 초기화의 문제인듯하다.
//도착지에 도착했을 때 desert배열에서 빼면안되고 모든 탐색이 끝나고 빼야하는데 정답을 찾고 바로 빼버려서 문제가 생겼다.
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAX_N  = 21;
int n;
int map[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int desert[101];
int dir_y[4] = {1,1,-1,-1};
int dir_x[4] = {-1,1,1,-1};
int check[4] ;
int s_y,s_x;
int answer = -1;

void dfs(int depth,int y,int x,int d){
    
    
    for(int i=0;i<2;i++){
        int next_d = 0;
        if(d+i == 4)
            return;
        else
            next_d = d+i;
        int next_y = y + dir_y[next_d];
        int next_x = x + dir_x[next_d];
        if(next_y<0||next_y>n-1||next_x<0||next_x>n-1)
            continue;
        int next_desert = map[next_y][next_x];
        
        
        if(desert[next_desert] == 1){
            if(next_y == s_y && next_x == s_x){
                if(answer < depth+1)
                    answer = depth+1;
                return;
            }else
                continue;
        }
        
        desert[next_desert] = 1;
        
         //  cout<<next_y<<" "<<next_x<<"시작"<<"방향: "<<next_d<<endl;
        dfs(depth+1, next_y, next_x, next_d);
         //  cout<<next_y<<" "<<next_x<<" "<<next_d<<" 끝"<<endl;
        desert[next_desert] = 0;
        
    }
    
    
    
}


void simul(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            s_y = i;
            s_x = j;
        //    cout<<"시작: "<<i<<" "<<j<<endl;
            desert[map[i][j]] = 1;
            dfs(0, i, j, 0);
            desert[map[i][j]] = 0;
            
        }
    }
    
    
}

int main(int argc, const char * argv[]) {
    int T = 0;
    scanf("%d",&T);
    for(int testcase = 1;testcase<=T;testcase++){
        scanf("%d",&n);
        answer = -1;
        memset(desert,0,sizeof(desert));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&map[i][j]);
            }
        }
        simul();
        printf("#%d %d\n",testcase,answer);
        
        
    }
    
    
    return 0;
}
