//
//  main.cpp
//  bj9466
//
//  Created by new_mac on 2019. 7. 29..
//  Copyright © 2019년 new_mac. All rights reserved.
//실패!! --> 다시 풀어볼것.
//와 시발!!!! ㅈㄴ 짜릿하다!! 하앙!!!! ><
// 우선 풀긴 풀었는데 상당히 어려운 문제였다.... dfs의 심화버전인데 이문제를 정확하게 이해하면 어떤문제도 문제없을듯.

//우선 현재 진행중인 dfs의 정점인지 탐색이 완료된 정점인지를 구분하여야 했는데 이부분을 하지않아서 오류가 발생.
//그리고 그래프의 특성상 한번 dfs를 수행하면 해당 번호가 팀에 속하는지 못하는지를 알수 있다. 기존에는 팀에 속하는 사람들만 카운트 하고
//팀에 속하지 못하는 사람들은 중복해서 dfs를 수행했다면 팀에 속하지 못하는 사람들까지 체크해서 불필요한 중복을 줄였다.
//이부분을 해결하니 바로 통과되었다.



#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <stack>
using namespace std;
const int MAX_N = 100002;
int n;

int list[MAX_N];
int visited[MAX_N];

int dfs(int num){
    int result = 0;
    visited[num] = 3;
    if(list[num] != 0){
        int next = list[num];
    
        if(visited[next] == 0){
            result = dfs(next);
        }else{
            if(visited[next] == 3)//진행중인 dfs
                result = next;
            else{//이미 검증된 정점
                result = 0;
            }
        }
    
    }else{
            return 0;
    }
    
    
    if(result == 0){
        visited[num] = 1;
    }else{
        visited[num] = 2;
        if(result == num){
            result = 0;
        }
    }
    
    return result;

}


int main(int argc, const char * argv[]) {
    int T = 0;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d",&n);
        memset(visited,0,sizeof(visited));
        memset(list,0,sizeof(list));
        
        for(int j=1;j<=n;j++){
            int temp = 0;
            scanf("%d",&temp);
            list[j] = temp;
        }
        
        for(int i=1;i<=n;i++){
            if(visited[i] ==0){
                dfs(i);
            }
        }
        int cnt = 0;
        for(int i=1;i<=n;i++){
            if(visited[i] == 1)
                cnt++;
        }
        cout<<cnt<<endl;
        
    }
    
    
    return 0;
}
