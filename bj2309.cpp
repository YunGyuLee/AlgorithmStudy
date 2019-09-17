//
//  main.cpp
//  bj2309
//
//  Created by new_mac on 2019. 9. 16..
//  Copyright © 2019년 new_mac. All rights reserved.
//

//nCm 문제 --> 재귀로 풀려고 하다보니 조금 꼬이는 부분이 발생.

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N = 9;
int jang[MAX_N];
int result[7];
int End;


void dfs(int cnt,int depth){
    if(End == 1)
        return;

    if(cnt == 7){
        
        int sum = 0;
        for(int i=0;i<7;i++){
            sum += result[i];
        }
        
        if(sum == 100){
            End = 1;
            for(int i=0;i<7;i++){
                printf("%d\n",result[i]);
            }

        }
        return;
    }
    

    for(int i=depth;i<9;i++){
            result[cnt] = jang[i];
            dfs(cnt+1,i+1);
            result[cnt] = 0;
    }
    
    
}


int main(int argc, const char * argv[]) {
    
    for(int i=0;i<9;i++){
        scanf("%d",&jang[i]);
    }
    
    sort(jang, jang+9);
    
    dfs(0,0);
    
    
    return 0;
}
