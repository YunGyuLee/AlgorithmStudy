//
//  main.cpp
//  bj1941
//
//  Created by new_mac on 2019. 8. 8..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//1시간 4분 걸림.... --> 흠 처음보는 유형의 문제...
//내 풀이가 맞았다. 단순한 백트레킹으로는 잡을수 없는 10자모양등이 있기때문에 이문제는 먼저 7개를 선택하고 그들이 연결이되어있는지를 판단해야하는 문제였다.
#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
char map[5][5];
int visited[5][5];
int temp[5][5];
int S;
int Y;
int answer;
int dir_y[4] = {0,0,-1,1};
int dir_x[4] = {1,-1,0,0};

void bfs(int y,int x){
    queue<pair<int,int>> queue;
    queue.push(make_pair(y, x));
    visited[y][x] = 1;
    if(map[y][x] == 'S'){
        S++;
    }else
        Y++;
    while (!queue.empty()) {
        int now_y = queue.front().first;
        int now_x = queue.front().second;
        queue.pop();
        for(int i=0;i<4;i++){
            int next_y = now_y + dir_y[i];
            int next_x = now_x + dir_x[i];
            if(next_x<0||next_x>4||next_y<0||next_y>4)
                continue;
            if(visited[next_y][next_x] == 1)
                continue;
            if(temp[next_y][next_x] == 1){
                queue.push(make_pair(next_y, next_x));
                visited[next_y][next_x] = 1;
                if(map[next_y][next_x] == 'S')
                    S++;
                else
                    Y++;
                
            }
            
        }
        
        
    }
    if(S>=4 && S+Y==7){
     //   cout<<S<<" "<<Y<<endl;

        answer++;
    }
}

void simul(){
    vector<int> select;
    vector<pair<int,int>> cord;
    for(int i=0;i<25;i++){
        if(i<7)
            select.push_back(1);
        else
            select.push_back(0);
    }
    sort(select.begin(), select.end());
    
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cord.push_back(make_pair(i, j));
        }
    }
    do{
        
        int cnt = 0;
        int s_y=0;
        int s_x=0;
        S=0;
        Y=0;
        memset(temp, 0, sizeof(temp));
        memset(visited,0,sizeof(visited));
        for(int i=0;i<25;i++){
            if(select[i] == 1){
                int y = cord[i].first;
                int x = cord[i].second;
                temp[y][x] = 1;
                if(cnt == 0){
                    s_y = y;
                    s_x = x;
                }
                cnt++;
            }
                
        }
        
        bfs(s_y, s_x);
        
        
        
    }while (next_permutation(select.begin(), select.end()));
        


}


/*
void dfs(int y,int x,int depth){
    if(map[y][x] == 'S')
        S++;
    else
        Y++;
    visited[y][x] = 1;
    if(depth == 7){
        
        if(S>Y)
            answer++;
        visited[y][x] = 0;
        if(map[y][x] == 'S')
            S--;
        else
            Y--;

        return;
    }
    for(int i =0;i<4;i++){
        int next_y = y + dir_y[i];
        int next_x = x + dir_x[i];
        if(next_y<0||next_y>4||next_x<0||next_x>4)
            continue;
        if(visited[next_y][next_x] == 1)
            continue;
        dfs(next_y, next_x, depth+1);
        
    }
    visited[y][x] = 0;
    if(map[y][x] == 'S')
        S--;
    else
        Y--;

}
*/
int main(int argc, const char * argv[]) {
    for(int i=0;i<5;i++){
        string temp;
        cin>>temp;
        for(int j=0;j<5;j++){
            map[i][j] = temp[j];
        }
    }
    
    simul();
    cout<<answer<<endl;
    
    
    return 0;
}
