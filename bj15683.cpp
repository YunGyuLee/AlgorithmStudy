//
//  main.cpp
//  bj15683
//
//  Created by new_mac on 2019. 8. 9..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//1시간만에 풀이완료!
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;
const int MAX_N = 9;
int map[MAX_N][MAX_N];
int n,m;
struct info{
    int y;
    int x;
    int num;
};
int cctv_d[5][4] =
{{0,0,0,1},{0,1,0,1},{1,0,0,1},{1,1,0,1},{1,1,1,1}};
vector<info> cctv;
int dir_y[4] = {-1,0,1,0};
int dir_x[4] = {0,-1,0,1};
int answer = 1000;
void print_m(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}
void one_dir(int y,int x,int d){
    //int result = 0;
    int now_y = y;
    int now_x = x;
    while (1) {
        now_y = now_y + dir_y[d];
        now_x = now_x + dir_x[d];
        if(now_y<0||now_y>n-1||now_x<0||now_x>m-1)
            break;
        if(map[now_y][now_x] == 6)//벽이면 탈출
            break;
        if(map[now_y][now_x] == 0){
            map[now_y][now_x] = -1;
        }
        
    }
    
   // return result;

}


void go(int y,int x,int num,int d){
    int d_check[4] ={0,};

    for(int i=0;i<4;i++){
        int index = (i+d)%4;
        d_check[index] = cctv_d[num-1][i];
    }
    
    for(int i=0;i<4;i++){
        if(d_check[i] == 0)
            continue;
        one_dir(y, x, i);
        
    }
    

    
}


int check_save(){
    int result = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j] == 0)
                result++;
        }
    }
    return result;
}


void dfs(int depth){
    int t_map[MAX_N][MAX_N];
    memcpy(t_map, map, sizeof(map));
    if(depth == cctv.size()){
        int temp = check_save();
        if(temp < answer)
            answer = temp;
        return;
    }
    
    
        int y = cctv[depth].y;
        int x = cctv[depth].x;
        int num = cctv[depth].num;
    
    
        for(int d=0;d<4;d++){
            if(num == 5 && d==1)
                break;
            if(num == 2 && d==2)
                break;
            go(y, x, num, d);
            dfs(depth+1);
            memcpy(map, t_map, sizeof(map));
        }
    

}





int main(int argc, const char * argv[]) {
    
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int temp = 0;
            scanf("%d",&temp);
            map[i][j] =temp;
            if(temp>=1 && temp<=5){
                cctv.push_back(info{i,j,temp});
            }
        }
    }
    dfs(0);
    cout<<answer<<endl;
    
    
    return 0;
}
