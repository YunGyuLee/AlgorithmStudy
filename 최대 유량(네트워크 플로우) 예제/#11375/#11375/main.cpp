//
//  main.cpp
//  #11375
//
//  Created by new_mac on 2019. 7. 16..
//  Copyright © 2019년 new_mac. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

const int MAX_N = 1002;
int n,m;
vector<int> list[MAX_N];
int visited[MAX_N];
int empty[MAX_N];


bool dfs(int x){
    
    for(int i=0;i<list[x].size();i++){
        int next = list[x][i];
        if(visited[next] != 0)
            continue;
        visited[next] = 1;
        if(empty[next] == 0 || dfs(empty[next])){
            empty[next] = x;
            return true;
        }
        
    }
    return false;


}



int main(int argc, const char * argv[]) {
    scanf("%d %d",&n,&m);
    
    for(int i=1;i<=n;i++){
        int cnt = 0;
        scanf("%d",&cnt);
        for(int j=0;j<cnt;j++){
            int temp;
            scanf("%d",&temp);
            list[i].push_back(temp);
        }
    }
    
    int result = 0;
    for(int k=0;k<2;k++){
    for(int i=1;i<=n;i++){
        memset(visited,0,sizeof(visited));
            if(dfs(i))
                result++;
        
    }
    }
    cout<<result<<endl;
    
    
    return 0;
}
