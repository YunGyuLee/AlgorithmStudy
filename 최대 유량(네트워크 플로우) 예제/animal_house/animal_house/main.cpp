//
//  main.cpp
//  animal_house
//
//  Created by new_mac on 2019. 7. 6..
//  Copyright © 2019년 new_mac. All rights reserved.
//


//네트워크 플로우 유형의 문제중 특별한 형태의 문제인 이분매칭에 관한 문제!!
// 이분 매칭은 네트워크 플로우로 V*E^2의 시간으로 풀수 도 있지만
// dfs를 이용하면 V*E로 더욱 빠르고 쉽게 풀 수 있다.
#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

const int MAX_N = 204;
const int MAX_M = 204;

int n,m;

vector<int> list[MAX_N];
int visited[MAX_M]; //처음에 왜 방문된 정점을 신경 써 줘야 하는지 이해를 못했다. 하지만 각 정점마다 dfs를 수행 할 때마다 visited가 초기화 된다는 것을 확인하고 이해했다. 자세한 것은 밑의 코드로 설명.
int match[MAX_M]; //해당 정점과 매칭하고 있는 정점.

bool dfs(int x){
    
    for(int i=0;i<list[x].size();i++){
        int next = list[x][i];
        if(visited[next]) //여기서 방문되었다는 의미는 새롭게 매칭 시킬 하나의 정점에 대하여 dfs를 수행할 때 이미 해당 점은 dfs에 의해 재조정이 되었고 추가적인 재조정은 불가능 함을 의미한다.
            continue;
        visited[next] = 1;
        if(match[next] == 0 || dfs(match[next])){
            match[next] = x;
            return true;
        }
    }
    return false;
}



int main(int argc, const char * argv[]) {
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        
        int num;
        scanf("%d",&num);
        for(int j=0;j<num;j++){
            int d;
            scanf("%d",&d);
            list[i].push_back(d);
            }
        
    }
   
    
    int cnt = 0;
    for(int i=1;i<=n;i++){
        memset(visited,0,sizeof(visited));
        if(dfs(i))
            cnt++;
    }
    cout<<cnt<<endl;
    
    return 0;
}
