//
//  main.cpp
//  bj1920
//
//  Created by new_mac on 2019. 8. 14..
//  Copyright © 2019년 new_mac. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAX_N = 100001;
int A[MAX_N];
int n,m;


void find_x(int x,int start,int end){
    
   
    
    if(start > end){
        printf("%d\n",0);
        return;
    }
    int mid = (start + end)/2;
        
    if(x > A[mid]){
        find_x(x, mid + 1, end);
    }else if(x < A[mid]){
        find_x(x, start, mid - 1);
    }else{
        printf("%d\n",1);
        return;
    }
    
    
}


int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    sort(A,A+n);
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int temp = 0;
        scanf("%d",&temp);
        find_x(temp, 0, n-1);
        
    }
    
    
    return 0;
}
