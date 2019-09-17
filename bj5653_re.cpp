//
//  main.cpp
//  boj5653_re
//
//  Created by new_mac on 2019. 8. 9..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//1시간 18분만에 정답! --> 문제에서 주어진 타임라인대로 시뮬레이션을 해서 반복문을어떻게 구성할지 생각해보자.

#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
const int MAX_N = 400;
struct info{
    int life;
    int state;//비활성, 활성, 죽음
    int t_stemp;//추가된시간.
    int l_stemp;//활성화된 시간.
};
int n,m,k;
info map[MAX_N][MAX_N];

int dir_y[4] = {0,0,1,-1};
int dir_x[4] = {1,-1,0,0};

void print_m(){
    for(int i=165;i<180;i++){
        for(int j=165;j<180;j++){
            printf("%d ",map[i][j].life);
        }
        printf("\n");
    }
    printf("\n");

}


int bfs(queue<pair<int,int>> idle){
    queue<pair<int,int>> live;
    for(int i=0;i<k;i++){
//        cout<<i<<"시간 후"<<endl;
        
    //    print_m();
        int l_size = live.size();
        int i_size = idle.size();
   //     cout<<l_size + i_size<<endl;
        for(int j=0;j<l_size;j++){
            int now_y = live.front().first;
            int now_x = live.front().second;
            live.pop();
            for(int d=0;d<4;d++){
                int next_y = now_y + dir_y[d];
                int next_x = now_x + dir_x[d];
                if(map[next_y][next_x].life == 0){
                    map[next_y][next_x] = info{map[now_y][now_x].life,1,i,-1};
                    idle.push(make_pair(next_y, next_x));//처음넣을때만 추가
                }else{
                    if(map[next_y][next_x].t_stemp == i){//방금추가 된것.
                        if(map[next_y][next_x].life < map[now_y][now_x].life){
                            map[next_y][next_x] = info{map[now_y][now_x].life,1,i,-1};
                        }
                    }
                
                }
                
                
            }
            if(i-map[now_y][now_x].l_stemp < map[now_y][now_x].life){//세포가 아직 죽지않았으면
                live.push(make_pair(now_y, now_x));
            }
            
            
        }
      //  int i_size = idle.size();
        for(int j=0;j<i_size;j++){
            int now_y = idle.front().first;
            int now_x = idle.front().second;
            idle.pop();
            if(i - map[now_y][now_x].t_stemp >= map[now_y][now_x].life){
                map[now_y][now_x].l_stemp = i;
                live.push(make_pair(now_y, now_x));
            }else
                idle.push(make_pair(now_y, now_x));
            
            
            
        }
        
        
        
    
    }
    int result = live.size() + idle.size();
    return result;
    
}



int main(int argc, const char * argv[]) {
    int T =0;
    scanf("%d",&T);
    for(int testcase = 1;testcase<=T;testcase++){
        scanf("%d %d %d",&n,&m,&k);
        queue<pair<int,int>> idle;
        memset(map, 0, sizeof(map));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int temp = 0;
                scanf("%d",&temp);
                if(temp>0){
                    map[175+i][175+j] = info{temp,1,-1,-1};
                    idle.push(make_pair(175+i, 175+j));
                  
                }
            }
            
        }
        printf("#%d %d",testcase,bfs(idle));
        
        
    }
    
    
    return 0;
}
