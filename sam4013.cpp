//
//  main.cpp
//  sam4013
//
//  Created by new_mac on 2019. 8. 5..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//
//58분만에 풀이완료... --> 방향들의 정보도 같이 queue에 넣어주엇어야했는데 깜빡해서 시간이 오래걸렸다...

#include <iostream>
#include <stdio.h>
#include <queue>
#include <math.h>
using namespace std;
int k;
int magnet[4][8];//1이 S극, 0이 N극
int dir_m[2] = {-1,1};

void turn(int num,int dir){
    int temp[8] = {0,};
    if(dir == 1){
        
        temp[0] = magnet[num][7];
        for(int i=1;i<8;i++){
            temp[i] = magnet[num][i-1];
        }
        for(int i=0;i<8;i++){
            magnet[num][i] = temp[i];
        }
        
    }else{
        temp[7] = magnet[num][0];
        for(int i=0;i<7;i++){
            temp[i] = magnet[num][i+1];
        }
        for(int i=0;i<8;i++){
            magnet[num][i] = temp[i];
        }
    
    }
    
    
    
}


void go(int num,int dir){
    int visited[4] = {0,};
    queue<pair<int,int>> queue; //num,dir
    queue.push(make_pair(num,dir));
    visited[num] = dir;
    while(!queue.empty()){
        int now = queue.front().first;
        int now_d = queue.front().second;
        queue.pop();
        for(int i = 0;i<2;i++){
            int next = now + dir_m[i];
            if(next<0||next>3)
                continue;
            if(visited[next] != 0)
                continue;
            if(i==0){
                if(magnet[now][6] != magnet[next][2]){
                    queue.push(make_pair(next,-now_d));
                    visited[next] = -now_d;
                }
            }else{
                if(magnet[now][2] != magnet[next][6]){
                    queue.push(make_pair(next,-now_d));
                    visited[next] = -now_d;
                }
            }
            
        }
    
    }
    for(int i=0;i<4;i++){
        if(visited[i] == -1){
            turn(i, -1);
        }else if(visited[i] == 1){
            turn(i,1);
        }
    }
    

}

int calcul(){
    int result = 0;
    for(int i=0;i<4;i++){
        result += magnet[i][0]*pow(2,i);
    }
    return result;
}



int main(int argc, const char * argv[]) {
    int T= 0 ;
    scanf("%d",&T);
    for(int testcase = 1;testcase<=T;testcase++){
        scanf("%d",&k);
        for(int i=0;i<4;i++){
            for(int j=0;j<8;j++){
                scanf("%d",&magnet[i][j]);
            }
        }
        for(int i=0;i<k;i++){
            int num,dir;
            scanf("%d %d",&num,&dir);
            //-1해줘야함.
            //여기에 알고릐즘!
            go(num-1, dir);
            
        }
        printf("#%d %d\n",testcase,calcul());
        
    }
    return 0;
}
