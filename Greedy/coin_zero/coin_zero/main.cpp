//
//  main.cpp
//  coin_zero
//
//  Created by new_mac on 2019. 7. 17..
//  Copyright © 2019년 new_mac. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;
const int MAX_N = 11;
int n,k;
int coin[MAX_N];
int main(int argc, const char * argv[]) {
    scanf("%d %d",&n,&k);
    
    for(int i=0;i<n;i++){
        scanf("%d",&coin[i]);
    }
    
    int result = 0;
    for(int i=n-1;i>=0;i--){
        int temp = k/coin[i];
        if(temp > 0){
            result +=temp;
            k = k%coin[i];
        }
        if(k == 0)
            break;
    }
    
    cout<<result<<endl;
    
    return 0;
}
