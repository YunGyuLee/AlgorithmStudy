//
//  main.cpp
//  rope
//
//  Created by new_mac on 2019. 7. 18..
//  Copyright © 2019년 new_mac. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

const int MAX_N = 100002;
int n;
int w[MAX_N];
int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&w[i]);
    }
    sort(w,w+n);
    
    int result = 0;
    for(int i=0;i<n;i++){
        result = max(w[i]*(n-i),result);
    }
    cout<<result<<endl;
    
    return 0;
}
