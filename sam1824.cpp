//
//  main.cpp
//  sam1824
//
//  Created by new_mac on 2019. 7. 31..
//  Copyright © 2019년 new_mac. All rights reserved.
//

//2시간 40분만에 풀이완료.... --> 문제가 어려웠다.
//테스트케이스가 풍성해서 뭔가 어거지로 맞춘느낌
//와.... 가비지 컬렉터가 없어서 그런지... 세그먼트 폴트가 떴던 이유는 결국 구조체의 찌꺼기가 남아서 그랬던것이였다...!!!
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string.h>
using namespace std;
const int MAX_N = 22;
int n,m;
char map[MAX_N][MAX_N];
int mem = 0;
int visited[MAX_N][MAX_N][16][4];
int dir_y[4] = {0,0,1,-1};
int dir_x[4] = {1,-1,0,0};
struct cor{
    int y;
    int x;
};
cor next_;
cor go(int y,int x,int d){
    
    int next_y = y + dir_y[d];
    int next_x = x + dir_x[d];
    
    if(next_x <0){
        next_x = m-1;
    }else if(next_x >m-1){
        next_x = 0;
    }
    if(next_y <0 ){
        next_y = n-1;
    }else if(next_y >n-1){
        next_y = 0;
    }
    
    
    
    return cor{next_y,next_x};
    
}


bool move(int y,int x,int d){
    //  cout<<d<<endl;
    bool result = false;
    int now_y = y;
    int now_x = x;
    int dir = d;
    //    while(1){
    
    
    //    cout<<mem<<" "<<dir<<" "<<now_y<<" "<<now_x<<endl;
    
    
    int t_y = now_y;
    int t_x = now_x;
    
    if(map[now_y][now_x] == '<'){
        dir = 1;
    }else if(map[now_y][now_x] == '>'){
        dir = 0;
    }else if(map[now_y][now_x] == '^'){
        dir = 3;
    }else if(map[now_y][now_x] == 'v'){
        dir = 2;
    }else if(map[now_y][now_x] == '_'){
        if(mem == 0){
            dir = 0;
        }else{
            dir = 1;
        }
        
    }else if(map[now_y][now_x] == '|'){
        if(mem == 0){
            dir = 2;
        }else{
            dir = 3;
        }
    }
    else if(map[now_y][now_x] == '@'){
        return true;
    }else if(map[now_y][now_x] >= '0' && map[now_y][now_x] <= '9'){
        mem = map[t_y][t_x] - '0' ;
        
    }else if(map[now_y][now_x] == '+'){
        if(mem == 15){
            mem = 0;
        }else{
            ++mem;
        }
    }else if(map[now_y][now_x] == '-'){
        if(mem == 0){
            mem = 15;
        }else{
            --mem;
        }
    }
    
    if(visited[y][x][mem][dir] == 1){
        return false;
    }else{
        visited[y][x][mem][dir] = 1;
    }
    
    next_ = go(now_y,now_x,dir);
    now_y = next_.y;
    now_x = next_.x;
    
    
    if(map[t_y][t_x] == '?'){
        
        
        for(int i=0;i<4;i++){
            next_ = go(t_y,t_x,i);
            now_y = next_.y;
            now_x = next_.x;
            
            
            if(move(now_y,now_x,i)){
                result = true;
                break;
            }
        }
        
        return result;
        
    }else{
        
        return move(now_y,now_x,dir);
    }
    
    
    //   }
    
    
    
}

int main(int argc, const char * argv[]) {
    int T = 0;
    scanf("%d",&T);
    for(int testcase = 1;testcase<=T;testcase++){
        scanf("%d %d",&n,&m);
        mem = 0;
        memset(visited,-1,sizeof(visited));
        memset(map,-1,sizeof(map));
        for(int i=0;i<n;i++){
            string temp;
            cin>>temp;
            for(int j=0;j<m;j++){
                map[i][j] = temp[j];
            }
            temp.clear();
        }
        
        printf("#%d %s\n", testcase, move(0, 0, 0) ? "YES" : "NO");
        
        
    }
    
    return 0;
}
