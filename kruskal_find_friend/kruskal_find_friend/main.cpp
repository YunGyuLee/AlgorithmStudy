//
//  main.cpp
//  kruskal_find_friend
//
//  Created by new_mac on 2019. 6. 22..
//  Copyright © 2019년 new_mac. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
#include <string.h>
using namespace std;

const int MAX_N = 200000;

int parent[MAX_N][2];

char f1[21];
char f2[21];

int getParent(int x){
    if(parent[x][0] == x)
        return x;
    else
        return getParent(parent[x][0]);

}
bool isShare(int a,int b){
    a = getParent(a);
    b = getParent(b);
    if(a == b)
        return true;
    else
        return false;
}


void unionParent(int a,int b){
    a = getParent(a);
    b = getParent(b);
    
    if(a < b){
        parent[a][1] = parent[a][1] + parent[b][1];
        parent[b][0] = a;
    }else if(a > b){
        
        parent[b][1] = parent[b][1] + parent[a][1];
        parent[a][0] = b;
    }else
        return;
        
    
}



int main(int argc, const char * argv[]) {
    
    
    int T = 0;
    scanf("%d",&T);
    
    
    for(int testcase = 1;testcase<=T;testcase++){
        int f = 0;
        int cnt = 0;
        map<string,int> network;

        
        
        scanf("%d",&f);
        
        for(int i=0;i<2*f;i++){
            parent[i][0] = i;
            parent[i][1] = 1;
        }
        
        for(int i=0;i<f;i++){
            
            scanf("%s %s",f1,f2);
            if(network.count(f1) == 0){
                network[f1] = cnt;
                cnt++;
            }
            if(network.count(f2) == 0){
                network[f2] = cnt;
                cnt++;
            }
            
            unionParent(network[f1], network[f2]);
            int x = getParent(network[f1]);
            cout<<parent[x][1]<<'\n';
            
            
        }
        
        network.clear();
        
    }
    
    
    return 0;
}
