//
//  main.cpp
//  sam6731
//
//  Created by new_mac on 2019. 8. 5..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//풀이실패 --> n의 범위가 너무 크기때문에 완탐으로는 풀 수 없음.
// 규칙을찾아야만 풀리는 문제...!

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int MAX_N = 1002;
int n;
char map[MAX_N][MAX_N];
char goal[MAX_N][MAX_N];

int dir_y[4] = {0,0,1,-1};
int dir_x[4] = {1,-1,0,0};


void reverse_c(int y,int x){
    if(map[y][x] == 'W')
        map[y][x] = 'B';
    else
        map[y][x] = 'W';
}


void one_dir(int y,int x,int dir){
    int now_y = y;
    int now_x = x;
    while(1){
        now_y = now_y + dir_y[dir];
        now_x = now_x + dir_x[dir];
        if(now_y<0||now_y>n-1||now_x<0||now_x>n-1)
            break;
        reverse_c(now_y, now_x);
    }
    
}

void go(int y,int x){
    reverse_c(y, x);
    for(int i=0;i<4;i++){
        one_dir(y, x, i);
    }
}

bool find_answer(int num){
    bool result = false;
    vector<int> select;
    vector<pair<int,int>> cord;
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cord.push_back(make_pair(i,j));
            if(cnt<num)
                select.push_back(1);
            else
                select.push_back(0);
            cnt++;
        }
    }
    sort(select.begin(),select.end());
    do{
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                map[i][j] = 'W';
            }
        }
        
        
        for(int i=0;i<select.size();i++){
            if(select[i] == 1){
                go(cord[i].first,cord[i].second);
            }
        }
        
        bool check = true;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(map[i][j] != goal[i][j]){
                    check = false;
                    break;
                }
            }
            if(!check)
                break;
        }
        if(check){
            result = true;
            break;
        }
        
        
        
    
    }while(next_permutation(select.begin(), select.end()));
    
    select.clear();
    cord.clear();
    
    return result;

}

int simul(){
    int result = 0;
    while(1){
        if(find_answer(result))
            break;
        result++;
    }
    return result;
}


int main(int argc, const char * argv[]) {
    int T = 0;
    scanf("%d",&T);
    for(int testcase = 1;testcase<=T;testcase++){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            string temp;
            cin >> temp;
            for(int j=0;j<n;j++){
                goal[i][j] = temp[j];
                map[i][j] = 'W';
            }
        }
        
        
        cout<<simul()<<endl;
        
        
        
    }
    return 0;
}
