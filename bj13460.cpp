//
//  main.cpp
//  bj13460
//
//  Created by new_mac on 2019. 8. 30..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//1시간 9분 정답완료.
//첫제출시 틀렸습니다가 떳는데 그이유가... 10번까지는 정답으로 볼수있는데 9번까지라고 조건을 잘못읽었다!! --> 조건 잘읽자!!
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
const int MAX_N = 11;
char map[MAX_N][MAX_N];
int n,m;
struct info{
    int y;
    int x;
};

info bid[2]; //R,B
int succ,fail;
int answer = 100;

int dir_y[4] = {0,0,1,-1};
int dir_x[4] = {1,-1,0,0};

void print_m(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
}


int check(int dir){
    int result = -1;
    if(dir == 0){
        if(bid[0].y == bid[1].y){//서로 영향을 줌
            if(bid[0].x < bid[1].x){
                //파란색이 먼저
                result = 1;
            }else
                result = 0;
        }
        
    }else if(dir == 1){
        if(bid[0].y == bid[1].y){//서로 영향을 줌
            if(bid[0].x < bid[1].x){
                //빨간색이 먼저
                result = 0;
            }else
                result = 1;
        }
        
    }else if(dir == 2){
        if(bid[0].x == bid[1].x){//서로 영향을 줌
            if(bid[0].y < bid[1].y){
                //파란색이 먼저
                result = 1;
            }else
                result = 0;
        }
        
        
    }else{
        if(bid[0].x == bid[1].x){//서로 영향을 줌
            if(bid[0].y < bid[1].y){
                //빨간색이 먼저
                result = 0;
            }else
                result = 1;
        }
        
        
        
    }
    
    return result;


}


bool move_one(int b_num,int dir){
    bool result = true;
    int cnt = 0;
    int next_y = bid[b_num].y;
    int next_x = bid[b_num].x;
    map[next_y][next_x] = '.';
    while(1){
        int t_y = next_y;
        int t_x = next_x;
        next_y = next_y + dir_y[dir];
        next_x = next_x + dir_x[dir];
        
        if(map[next_y][next_x] == 'O'){
            bid[b_num].y = -1;
            bid[b_num].x = -1;
            if(b_num == 0)
                succ = 1;
            else
                fail = 1;
            break;
        }
        if(map[next_y][next_x] != '.'){
            if(cnt == 0)
                result = false;
            char b = 'a';
            if(b_num == 0)
                b = 'R';
            else
                b = 'B';
            map[t_y][t_x] = b;
            bid[b_num].y = t_y;
            bid[b_num].x = t_x;
            break;
        }
        
        cnt++;
        
    }
    
    return result;

}


bool move(int dir){
    
    int flag = check(dir);
    if(flag == -1){
        bool a = move_one(0, dir);
        bool b = move_one(1, dir);
        if(a || b)
            return true;
        else
            return false;
    }else if(flag == 0){
        bool a = move_one(0, dir);
        bool b = move_one(1, dir);
        if(a || b)
            return true;
        else
            return false;
    }else if(flag == 1){
        bool a = move_one(1, dir);
        bool b = move_one(0, dir);
        if(a || b)
            return true;
        else
            return false;
    }
    
    return true;
}



void dfs(int depth){
    
    if(depth > answer)
        return;
    if(depth>10)
        return;
    if(fail == 1)
        return;
    if(succ == 1 && fail == 0){
        if(answer > depth)
            answer = depth;
        return;
    }
        
    
    char t_map[MAX_N][MAX_N];
    memcpy(t_map, map, sizeof(map));
    int t_succ = succ;
    int t_fail = fail;
    info t_bid[2];
    memcpy(t_bid, bid, sizeof(bid));
    
    for(int i=0;i<4;i++){
        if(move(i)){
            dfs(depth+1);
            memcpy(map, t_map, sizeof(map));
            memcpy(bid, t_bid, sizeof(bid));
            succ = t_succ;
            fail = t_fail;
        }
        
        
        
        
    }

}







int main(int argc, const char * argv[]) {
    
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        string temp;
        cin >> temp;
        for(int j=0;j<m;j++){
            map[i][j] = temp[j];
            if(temp[j] == 'R'){
                bid[0] = info{i,j};
            }
            if(temp[j] == 'B'){
                bid[1] = info{i,j};
            }
            
            
        }
    }
    dfs(0);
    if(answer == 100)
        answer = -1;
    printf("%d",answer);
    
    return 0;
}
