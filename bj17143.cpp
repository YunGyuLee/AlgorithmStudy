//
//  main.cpp
//  bj17143
//
//  Created by new_mac on 2019. 7. 31..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//1시간 36분 걸림. --> 첫 제출시 실패 --> 사실 상 못푼것....
//새로운 방식으로 풀어보려고 하였으나 결과적으로는 두개의 map을 사용하여야 한다.


#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

const int MAX_R = 102;
struct info{
    int s;
    int d;
    int z;
};

struct cor{
    int y;
    int x;
    int d;
};

int dir_y[4] = {-1,1,0,0};
int dir_x[4] = {0,0,1,-1};
int r,c,m;

info shark[MAX_R][MAX_R];
int visited[MAX_R][MAX_R];
info map[MAX_R][MAX_R];
int Answer;

int re_d(int d){
    if(d == 0)
        return 1;
    else if(d == 1)
        return 0;
    else if(d == 2)
        return 3;
    else if(d == 3)
        return 2;
    
    return -1;
}

void print_m(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d ",shark[i][j].z);
        }
        printf("\n");
    }
    printf("\n");
}

cor move(int y,int x){
    info now = shark[y][x];
    shark[y][x] = info{0,0,0};
    int now_y = y;
    int now_x = x;
    for(int i=0;i<now.s;i++){
        int t_y = now_y;
        int t_x = now_x;
        now_y = now_y + dir_y[now.d];
        now_x = now_x + dir_x[now.d];
        if(now_x<0 || now_x > c-1 || now_y <0 || now_y > r-1){
            now.d = re_d(now.d);
            now_y = t_y + dir_y[now.d];
            now_x = t_x + dir_x[now.d];
        }
    }
    
    cor result = cor{now_y,now_x,now.d};
    return result;

}


void fishing(queue<pair<int,int>> queue){
    
    for(int i=0;i<c;i++){
        
    //    print_m();
        int d_y = -1;
        int d_x = -1;
        //작살 코드
        for(int j=0;j<r;j++){
            if(shark[j][i].z != 0){
                d_y = j;
                d_x = i;
                break;
            }
        }
        
        if(d_y != -1 && d_x != -1){
        int size = queue.size();
        for(int j=0;j<size;j++){
            int now_y = queue.front().first;
            int now_x = queue.front().second;
            queue.pop();
            if(now_y == d_y && now_x == d_x){
              //  cout<<shark[now_y][now_x].z<<endl;
                Answer += shark[now_y][now_x].z;
                shark[now_y][now_x] = info{0,0,0};
            }else{
                queue.push(make_pair(now_y,now_x));
            }
        }
        }
        
        
        
        //이동 코드
        int size = queue.size();
        memset(visited,0,sizeof(visited));
        memset(map,0,sizeof(map));
        for(int j=0;j<size;j++){
            int now_y = queue.front().first;
            int now_x = queue.front().second;
            queue.pop();
            int now_s = shark[now_y][now_x].s;
            int now_z = shark[now_y][now_x].z;
            cor next = move(now_y,now_x);
            
            if(map[next.y][next.x].z == 0){
                map[next.y][next.x] = info{now_s,next.d,now_z};
                visited[next.y][next.x] = 1;
                queue.push(make_pair(next.y,next.x));
            }else{
                if(visited[next.y][next.x] == 1){
                    if(map[next.y][next.x].z < now_z){
                        map[next.y][next.x] = info{now_s,next.d,now_z};
                    }
                }
            }
            
        }
        memcpy(shark,map,sizeof(shark));
        
        
        
    }

}




int main(int argc, const char * argv[]) {
    scanf("%d %d %d",&r,&c,&m);
    queue<pair<int,int>> queue;
    for(int i=0;i<m;i++){
        int y,x,s,d,z;
        scanf("%d %d %d %d %d",&y,&x,&s,&d,&z);
        shark[y-1][x-1] = info{s,d-1,z};
        queue.push(make_pair(y-1,x-1));
        
    }
    fishing(queue);
    printf("%d\n",Answer);
    
    
    return 0;
}
