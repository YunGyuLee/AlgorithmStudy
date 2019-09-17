//
//  main.cpp
//  sam5644
//
//  Created by new_mac on 2019. 8. 3..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

const int MAX_N = 11;
const int MAX_T = 101;
int A_info[MAX_T];
int B_info[MAX_T];
int M,BC;
struct info{
    int y;
    int x;
    int cover;
    int perfom;
};

int dir_y[4] = {-1,0,1,0};
int dir_x[4] = {0,1,0,-1};
info BC_info[8];
int A_y,A_x;
int B_y = 9;
int B_x = 9;


int find_max(){
    
    int result = -1;
    //A가접속가능한 BC 구한다
    vector<int> A_BC;
    for(int i=0;i<BC;i++){
        int dis = abs(A_y - BC_info[i].y) + abs(A_x - BC_info[i].x);
        if(dis <= BC_info[i].cover){
            A_BC.push_back(i);
        }
    }
    //B가 접속가능한 BC 구한다
    vector<int> B_BC;
    for(int i=0;i<BC;i++){
        int dis = abs(B_y - BC_info[i].y) + abs(B_x - BC_info[i].x);
        if(dis <= BC_info[i].cover){
            B_BC.push_back(i);
        }
    }
    if(A_BC.size() > 0 && B_BC.size() > 0){
    for(int i=0;i<A_BC.size();i++){
        for(int j=0;j<B_BC.size();j++){
            int total = 0;
            if(A_BC[i] == B_BC[j]){//동시접속
                total = BC_info[A_BC[i]].perfom;
            }else{
                total = BC_info[A_BC[i]].perfom + BC_info[B_BC[j]].perfom;
            }
            
            if(total > result)
                result = total;
            
        }
    }
    }else if(A_BC.size() == 0 && B_BC.size() > 0){
        for(int i = 0;i<B_BC.size();i++){
            int total = BC_info[B_BC[i]].perfom;
            if(total > result)
                result = total;
        }
        
        
    }else if(A_BC.size() > 0 && B_BC.size() == 0){
        for(int i = 0;i<A_BC.size();i++){
            int total = BC_info[A_BC[i]].perfom;
            if(total > result)
                result = total;
        }
        
    }else
        result = 0;
    
    
    
    return result;
    
    
}


int go(){
    
    int result = 0;
    result += find_max();
    for(int i=0;i<M;i++){
        int A_d = A_info[i];
        int B_d = B_info[i];
        if(A_d != 0){
        A_y = A_y + dir_y[A_d-1];
        A_x = A_x + dir_x[A_d-1];
        }
        if(B_d !=0){
        B_y = B_y + dir_y[B_d-1];
        B_x = B_x + dir_x[B_d-1];
        }
        result += find_max();
    }
    
    return result;

}



int main(int argc, const char * argv[]) {
    int T = 0;
    scanf("%d",&T);
    for(int testcase = 1;testcase<=T;testcase++){
        scanf("%d %d",&M,&BC);
        A_y = 0;
        A_x = 0;
        B_y = 9;
        B_x = 9;
        for(int j=0;j<M;j++){
            scanf("%d",&A_info[j]);
        }
        for(int j=0;j<M;j++){
            scanf("%d",&B_info[j]);
        }
        for(int i=0;i<BC;i++){
            int y,x,cover,perfom;
            scanf("%d %d %d %d",&x,&y,&cover,&perfom);
            BC_info[i] = {y-1,x-1,cover,perfom};
            
        }
        
        printf("#%d %d\n",testcase,go());
        
        
    }
    
    
    
    
    
    return 0;
}
