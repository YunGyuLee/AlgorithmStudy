//
//  main.cpp
//  sam7810
//
//  Created by new_mac on 2019. 8. 5..
//  Copyright © 2019년 new_mac. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
const int MAX_N = 500001;
const int MAX_M = 10000002;
int cnt[MAX_M];
int num[MAX_N];
int n;




int main(int argc, const char * argv[]) {
    
    int T = 0;
    scanf("%d",&T);
    for(int testcase = 1;testcase<=T;testcase++){
        scanf("%d",&n);
        int max_n = -1;
        int answer = 0;
        memset(cnt,0,sizeof(0));
        for(int i=0;i<n;i++){
            int temp = 0;
            scanf("%d",&temp);
            num[i] = temp;
            if(temp > max_n)
                max_n = temp;
            cnt[temp]++;
            
        }
        
        int before = 0;
        for(int i=1;i<=max_n;i++){
            int temp = n-before;
            cout<<i<<" "<<temp<<endl;
            if(i>temp){
                break;
            }
            before += cnt[i];
            answer = i;
            
        }
        
        for(int i=0;i<n;i++){
            cnt[num[i]] = 0;
        }
        printf("#%d %d\n",testcase,answer);
        
        
        
    }
    
    
    return 0;
}
