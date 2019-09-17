//
//  main.cpp
//  sam5653_3rd
//
//  Created by new_mac on 2019. 9. 2..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//전에는 queue로 짰었는데 이번에는 전체 배열을 읽는 방식으로 짰다. 이방식이 좀더 시뮬레이션할때 간단하고 편한것같다.


#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAX_N = 352;
int n,m,k;
struct info{
    int state;
    int life;
    int idle_stemp;
    int live_stemp;
};
info map[MAX_N][MAX_N];
int dir_y[4] = {0,0,1,-1};
int dir_x[4] = {1,-1,0,0};
int cnt_live;
int cnt_idle;

int go(){
    int start_y = 150;
    int start_x = 150;
    int end_y = 150 + n;
    int end_x = 150 + m;
    for(int i=1;i<=k;i++){
        
        if(i%2==0){
            start_y -= 1;
            start_x -= 1;
            end_y = start_y + n + 2*i/2;
            end_x = start_x + m + 2*i/2;
        }
        for(int y = start_y;y<end_y;y++){
            for(int x= start_x;x<end_x;x++){
                if(map[y][x].state == 0)
                    continue;
                
                    if(map[y][x].state == 1){//비활성
                        if(i-map[y][x].idle_stemp == map[y][x].life){//활성상태로 변환
                            map[y][x].state = 2;
                            map[y][x].live_stemp = i;
                            cnt_idle--;
                            cnt_live++;
                        }
                        
                        
                    }else if(map[y][x].state == 2){//활성
                        for(int d=0;d<4;d++){
                            int next_y = y + dir_y[d];
                            int next_x = x + dir_x[d];
                            if(map[next_y][next_x].life == 0){
                                cnt_idle++;
                                map[next_y][next_x] = info{1,map[y][x].life,i,-1};
                            }else if(map[next_y][next_x].state ==1 && map[next_y][next_x].idle_stemp == i){
                                if(map[next_y][next_x].life < map[y][x].life){
                                    map[next_y][next_x] = info{1,map[y][x].life,i,-1};
                                }
                                
                            }
                            
                        }
                        
                        if(i-map[y][x].live_stemp == map[y][x].life){//죽은세포
                            map[y][x] = info{0,map[y][x].life,0,0};
                            cnt_live--;
                        }
                        
                        
                        
                    }
                    
        
            }
        }
        
        
        
    }
    
    
    return cnt_idle+cnt_live;


}



int main(int argc, const char * argv[]) {
    int T = 0;
    scanf("%d",&T);
    
    for(int testcase = 1;testcase<=T;testcase++){
        scanf("%d %d %d",&n,&m,&k);
        cnt_live = 0;
        cnt_idle = 0;
        memset(map,0,sizeof(map));
        for(int i=150;i<150+n;i++){
            for(int j=150;j<150+m;j++){
                int temp = 0;
                scanf("%d",&temp);
                if(temp != 0){
                    cnt_idle++;
                    map[i][j] = info{1,temp,0,-1};//비활성,0시간에 추가.
                }
            }
        }
        
        printf("#%d %d\n",testcase,go());
    
    }
    
    return 0;
}
