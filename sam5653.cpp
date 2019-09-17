//
//  main.cpp
//  sam5653
//
//  Created by new_mac on 2019. 7. 30..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//2시간 40분이 걸렸다....
// -->> 사실상 실패!, 제출하자마자 바로 정답이 뜨기는 했다.
//결론적으로 두개의 세포가 한곳에서 만날 때 처리를 정확하게 못한것이 잘못이였다.
// 시간을 쓴것은 크게 두부분.
// 1. 활성세포들의 확장전 비활성세포들의 개수를 저장. --> 확장 --> 저장해놓은 비활성세포들중 활성화 될것들 저장
// 이 순서로 진행했어야 했지만 확장 -> 비활성세포 활성화 로 잘못 생각하여 비활성세포들이 바로 활성화되는 오류가 생겼다.
// 2. 활성세포들이 확장할 때 같은곳을 점령하게 될 경우 어떻게 처리할 것인지 명확히 판단하지 못하여 오류.
#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
const int MAX_N = 700;

struct info{
    int life;
    int count;
    int state;//죽음 -1, 비활성1, 활성2
};

info map[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int n,m,k;
int dir_y[4] = {0,0,1,-1};
int dir_x[4] = {1,-1,0,0};


void print_m(){
    for(int i = 300;i<320;i++){
        for(int j=300;j<320;j++){
            printf("%d ",map[i][j].life);
        }
        printf("\n");
    }
    printf("\n");
}

int bfs(queue<pair<int,int>> unlive_q){
    int result = 0;
    queue<pair<int,int>> live_q;
    
    
    for(int i=0;i<k;i++){
        
        
        int size = live_q.size();
        int u_size = unlive_q.size();
        for(int j=0;j<size;j++){
            int now_y = live_q.front().first;
            int now_x = live_q.front().second;
            live_q.pop();
            map[now_y][now_x].count -= 1;
            map[now_y][now_x].state = i;
            for(int d=0;d<4;d++){
                int next_y = now_y + dir_y[d];
                int next_x = now_x + dir_x[d];
                if(next_y<0 || next_y > MAX_N-1 || next_x<0 || next_x>MAX_N-1){
                    cout<<"범위 초과"<<endl;
                    continue;
                }
                if(map[next_y][next_x].life !=0 && map[next_y][next_x].state == map[now_y][now_x].state &&map[next_y][next_x].count == map[next_y][next_x].life){//방금추가된 것이라면
                    if(map[next_y][next_x].life < map[now_y][now_x].life){
                        map[next_y][next_x].life = map[now_y][now_x].life;
                        map[next_y][next_x].count = map[now_y][now_x].life;
                        map[next_y][next_x].state = i;
                        continue;
                    }
                }
                
                if(map[next_y][next_x].life != 0)
                    continue;
                
                
                
                map[next_y][next_x].life = map[now_y][now_x].life;
                map[next_y][next_x].count = map[now_y][now_x].life;
                map[next_y][next_x].state = i;
                unlive_q.push(make_pair(next_y,next_x));
                
                
            }
            
            if(map[now_y][now_x].count + map[now_y][now_x].life == 0){
                map[now_y][now_x].state = 0;
            }else{
                live_q.push(make_pair(now_y, now_x));
            }
            
            
            
        }
        
        
        
        
        for(int j=0;j<u_size;j++){
            int now_y = unlive_q.front().first;
            int now_x = unlive_q.front().second;
            unlive_q.pop();
            map[now_y][now_x].count -= 1;
            if(map[now_y][now_x].count == 0){
                live_q.push(make_pair(now_y,now_x));
            }else{
                unlive_q.push(make_pair(now_y,now_x));
            }
            
            
        }
        
        
        
        
        
        //    printf("%d시간 후\n",i+1);
        //    print_m();
    }
    
    
    result = live_q.size() + unlive_q.size();
    return result;
}




int main(int argc, char** argv)
{
    int T = 0;
    scanf("%d",&T);
    for(int testcase = 1;testcase<=T;testcase++){
        scanf("%d %d %d",&n,&m,&k);
        queue<pair<int,int>> queue;
        memset(map,0,sizeof(map));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int temp=0;
                scanf("%d",&temp);
                if(temp != 0){
                    map[310 + i][310 + j] = info{temp,temp,0};
                    queue.push(make_pair(310+i,310+j));
                }
            }
        }
        
        printf("#%d %d\n",testcase,bfs(queue));
        
        
    }
    
    
    
    return 0;
    
}
