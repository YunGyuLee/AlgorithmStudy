//
//  main.cpp
//  bj16235
//
//  Created by new_mac on 2019. 8. 2..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//50분 만에 풀이완료.

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
const int MAX_T = 1000;
const int MAX_N = 11;
int tree[MAX_N][MAX_N][MAX_T];
int map[MAX_N][MAX_N];
int A[MAX_N][MAX_N];
int n,m,k;

int dir_y[8] = {-1,-1,-1,0,0,1,1,1};
int dir_x[8] = {-1,0,1,-1,1,-1,0,1};
int Answer;

void go(){
    for(int i=0;i<k;i++){
        //봄
        for(int j=0;j<n;j++){
            for(int x=0;x<n;x++){
                int size = tree[j][x][0];
                if(size == 0)
                    continue;
                for(int t=1;t<=size;t++){
                    if(map[j][x] < tree[j][x][t]){
                        tree[j][x][t] = -tree[j][x][t];
                    }else{
                        map[j][x] -= tree[j][x][t];
                        ++tree[j][x][t];
                    }
                    
                    
                }
                
                
            }
        }
        
        //여름
        for(int j=0;j<n;j++){
            for(int x=0;x<n;x++){
                int size = tree[j][x][0];
                if(size == 0)
                    continue;
                for(int t=1;t<=size;t++){
                    if(tree[j][x][t] < 0){
                        map[j][x] += abs(tree[j][x][t])/2;
                        --tree[j][x][0];
                        tree[j][x][t] = 0;
                    }
                    
                    
                }
                
                
            }
        }
        
        //가을
        for(int j=0;j<n;j++){
            for(int x=0;x<n;x++){
                int size = tree[j][x][0];
                if(size == 0)
                    continue;
                for(int t=1;t<=size;t++){
                    if(tree[j][x][t]%5 == 0){
                        for(int d=0;d<8;d++) {
                            int next_y = j + dir_y[d];
                            int next_x = x + dir_x[d];
                            if(next_y<0 || next_y>n-1||next_x<0||next_x>n-1)
                                continue;
                            int t_size = tree[next_y][next_x][0];
                            tree[next_y][next_x][t_size + 1] = 1;
                            ++tree[next_y][next_x][0];
                        }
                        
                    }
                    
                }
                
            }
        }
        
        
        for(int j=0;j<n;j++){
            for(int x=0;x<n;x++){
                int size = tree[j][x][0];
                sort(tree[j][x]+1,tree[j][x] + size + 1);
            }
        }

        //겨울
        
        for(int j=0;j<n;j++){
            for(int x=0;x<n;x++){
                map[j][x] += A[j][x];
            }
        }
    
    }
    
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(tree[i][j][0] > 0){
                Answer += tree[i][j][0];
            }
        }
    }
    
    
    

}



int main(int argc, const char * argv[]) {
   
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&A[i][j]);
            map[i][j] = 5;
        }
    }
    for(int i=0;i<m;i++){
        int x,y,age;
        scanf("%d %d %d",&y,&x,&age);
        tree[y-1][x-1][0] = 1;
        tree[y-1][x-1][1] = age;
    }
    
    go();
    printf("%d\n",Answer);
    
    return 0;
}
