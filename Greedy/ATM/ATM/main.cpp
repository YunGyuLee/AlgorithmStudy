//
//  main.cpp
//  ATM
//
//  Created by new_mac on 2019. 7. 18..
//  Copyright © 2019년 new_mac. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAX_N = 1002;
int n;
int p[MAX_N];
int sum[MAX_N];
int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    sort(p,p+n);
    sum[0] = p[0];
    for(int i=0;i<n-1;i++){
        sum[i+1] = sum[i] + p[i+1];
    }
    int result = 0;
    for(int i=0;i<n;i++){
        result += sum[i];
    }
    cout<<result<<endl;
    
    return 0;
}
