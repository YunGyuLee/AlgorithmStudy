//
//  main.cpp
//  sam2117
//
//  Created by new_mac on 2019. 8. 7..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//36분 만에 풀이완료.

#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
const int MAX_N = 21;
int map[MAX_N][MAX_N];
int n,m;

int find_max(int y,int x){
    int result = -1;
    for(int i=0;i<2*n;i++){
        int temp = 0;
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(map[j][k] == 1){
                    int dis = abs(j-y) + abs(k-x);
                    if(dis <= i)
                        temp++;
                    
                }
            }
        }
        
        int money = (i+1)*(i+1) + i*i;
        if(money <= m*temp){
          /*  cout<<"좌표: "<<y<<" "<<x<<endl;
            cout<<"거리 "<<i<<endl;
            cout<<"집들의 수: "<<temp<<endl;*/
            if(result<temp){
                result =temp;
            }
        }
    
    }
    
    return result;

}


int simul(){
    int result = -1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int temp = find_max(i, j);
            if(temp > result)
                result = temp;
        }
    }
    return result;

}



int main(int argc, const char * argv[]) {
    int T = 0;
    scanf("%d",&T);
    for(int testcase = 1;testcase<=T;testcase++){
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&map[i][j]);
            }
        }
        printf("#%d %d\n",testcase,simul());
        
    
    }
    
    
    
    return 0;
}
