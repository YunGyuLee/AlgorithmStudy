//
//  main.cpp
//  shark_dinner
//
//  Created by new_mac on 2019. 7. 16..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//간단한 문제였지만 두가지 문제가 발생하여 틀렸다.
//1. 이 문제같은 경우에는 1->2 의 관계를 check했으면 2->1의 관계는 볼필요가 없다. 그리고 1==2 가 되는 경우 하나의 방향으로 임의로 정해
//주어야 한다. 이 부분을 간과해서 틀렸다.
//2. 이분 매칭의 dfs에서 이미 매칭이된 짝을 표현하는 배열이 초기값이 0이기 때문에 index를 0 부터 시작하면 모든 정점들이 0으로 매칭되어 있게 된다. 따라서 초기값을 -1로 변경하거나 index를 1부터 시작해야한다.



#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
int n;
const int MAX_N = 55;
struct shark{
    int size;
    int speed;
    int intel;
};
vector<shark> s;
vector<int>list[MAX_N];
int visited[MAX_N];
int ocup[MAX_N];
bool dfs(int x){
    for(int i=0;i<list[x].size();i++){
        int next = list[x][i];
        if(visited[next] != 0)
            continue;
        visited[next] = 1;
        if(ocup[next] == -1 || dfs(ocup[next])){
            ocup[next] = x;
            return true;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    memset(ocup,-1,sizeof(ocup));
    
    for(int i=0;i<n;i++){
        int size,speed,intel;
        scanf("%d %d %d",&size,&speed,&intel);
        s.push_back(shark{size,speed,intel});
    }
    
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
        
            if(s[i].size == s[j].size && s[i].speed == s[j].speed && s[i].intel == s[j].intel)
                list[i].push_back(j);
            else if(s[i].size >= s[j].size && s[i].speed >= s[j].speed && s[i].intel >= s[j].intel)
                list[i].push_back(j);
            else if(s[i].size <= s[j].size && s[i].speed <= s[j].speed && s[i].intel <= s[j].intel)
                list[j].push_back(i);
        }
    }
    
    
    
    int result = 0;
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            memset(visited,0,sizeof(visited));
            if(dfs(j))
                result++;
        }
    }
    cout<<n-result<<endl;
    
    return 0;
}
