//
//  main.cpp
//  sam3074
//
//  Created by new_mac on 2019. 8. 3..
//  Copyright © 2019년 new_mac. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_N = 100001;
int n,m;



vector<int> cnt;





int main(int argc, const char * argv[]) {
    int T= 0;
    scanf("%d",&T);
    for(int testcase=1;testcase<=T;testcase++){
        scanf("%d %d",&n,&m);
        cnt.clear();
        for(int i=0;i<n;i++){
            int temp = 0;
            scanf("%d",&temp);
            cnt.push_back(temp);
        }
        sort(cnt.begin(),cnt.end());
        
        
        
        
    }
    
    
    return 0;
}
