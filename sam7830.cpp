//
//  main.cpp
//  sam7830
//
//  Created by new_mac on 2019. 7. 29..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//풀이실패
//동적프로그래밍을 사용해야한다.....

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

const int MAX_N = 752;
int n,m;
int map[MAX_N][MAX_N];
int check_size[4];
int dir_y[4] = {1,1,-1,-1};
int dir_x[4] = {-1,1,1,-1};
int Answer = -1;
int visited[MAX_N][MAX_N][4];
int s_y,s_x;
vector<pair<int,int>> cord;

int check_max(){
    int size = min(n,m);
    int result =0;
    if(size%2 == 0){
        result = size/2;
    }else{
        result = size/2 + 1;
    }
    return result;
    
}

bool find(int y,int x,int num){
    int left_y = y;
    int left_x = x;
    int right_y = y;
    int right_x = x;
    int last = 0;
    if(visited[y][x][0] == 0 && visited[y][x][1] ==0){
    
    for(int i=0;i<num-1;i++){
        last = i+1;
        left_y = left_y + dir_y[0];
        left_x = left_x + dir_x[0];
        
        right_y = right_y + dir_y[1];
        right_x = right_x + dir_x[1];
        if(left_y<0 || left_y>n-1||left_x<0||left_x>m-1||right_y<0||right_y>n-1||right_x<0||right_x>m-1)
            break;
        if(map[left_y][left_x] == 0 || map[right_y][right_x] == 0)
            break;
    }
        
        visited[y][x][0] = last;
        visited[y][x][1] = last;
        
    }else{
        
    }
    
    
    
    for(int i=0;i<num-1;i++){
        left_y = left_y + dir_y[1];
        left_x = left_x + dir_x[1];
        right_y = right_y + dir_y[0];
        right_x = right_x + dir_x[0];
        if(left_y<0 || left_y>n-1||left_x<0||left_x>m-1||right_y<0||right_y>n-1||right_x<0||right_x>m-1)
            return false;
        if(map[left_y][left_x] == 0 || map[right_y][right_x] == 0)
            return false;
    }
    
    if(map[left_y][left_x] == 1 && map[right_y][right_x] == 1 && left_y == right_y && left_x == right_x)
        return true;
    else
        return false;

    
    
    
}

bool check_bound(int y,int x,int num){
    int left_y = y+ (num-1)*dir_y[0];
    int left_x = x + (num-1)*dir_x[0];
    int right_y = y + (num-1)*dir_y[1];
    int right_x = x + (num-1)*dir_x[1];
    int down_y = left_y + (num-1)*dir_y[1];
    int donw_x = left_x + (num-1)*dir_x[1];
    if(left_y<0 || left_y>n-1||left_x<0||left_x>m-1||right_y<0||right_y>n-1||right_x<0||right_x>m-1||down_y<0||down_y>n-1||donw_x<0||donw_x>m-1)
        return false;
    if(map[left_y][left_x] == 0 || map[right_y][right_x] == 0 ||map[down_y][donw_x] == 0)
        return false;
    
    
    return true;
}


void simul(){
    int size = check_max();
    for(int i=size;i>=1;i--){
        
        for(int j=0;j<cord.size();j++){
            int y = cord[j].first;
            int x = cord[j].second;
    
            if(check_bound(y, x, i)){
                if(find(y,x,i)){
                        Answer = i;
                        return;
                }
            }
        
        }
        
    }

}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 0;
    scanf("%d",&T);
    for(int testcase = 1; testcase<=T;testcase++){
        scanf("%d %d",&n,&m);
        Answer = 0;
        int is_one = 0;
        cord.clear();
        for(int i=0; i<n; i++) {
            char buf[MAX_N];
            cin >> buf;
            for(int j=0; j<m; j++) {
                map[i][j] = buf[j] - '0';
                if(map[i][j] == 1){
                    cord.push_back(make_pair(i,j));
                }
            }
        }
        
        simul();
        
        printf("#%d %d\n",testcase,Answer);
        
        
    }
    
    return 0;
}
