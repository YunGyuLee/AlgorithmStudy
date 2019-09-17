//
//  main.cpp
//  topology_sort
//
//  Created by new_mac on 2019. 7. 2..
//  Copyright © 2019년 new_mac. All rights reserved.
//

//처음에 오답이유!! --> 위상정렬을 단순 bfs라고 생각했다. --> 위상정렬의 핵심은 queue에 차수가 0인 정점들을 순서대로 삽입하는 것인데
//처음 짠 코드에서는 출발시에만 차수가 0인 점들을 고려하고 그 이후는 단순 bfs로 작성하였다. queue에 삽입하는 조건을 차수가 0인 것들로 바꾸니 바로 통과되었다.

#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;


const int MAX_N = 32003;
int n,m;
int visited[MAX_N];
int visited2[MAX_N];
vector<int> list[MAX_N];

void bfs(queue<int> queue){
    while(!queue.empty()){
        int now = queue.front();
        printf("%d",now);
        queue.pop();
        for(int i=0;i<list[now].size();i++){
            int next = list[now][i];
            visited[next] -= 1;
            if(visited2[next] != 0)
                continue;
            if(visited[next] == 0){
                queue.push(next);
                visited2[next] = 1;
            }
        }
        
        if(!queue.empty())
            printf(" ");
            
    }

}

int main(int argc, const char * argv[]) {
   
    scanf("%d %d",&n,&m);
    
    queue<int> queue;
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        list[a].push_back(b);
        visited[b] += 1;
    }
    for(int i=1;i<=n;i++){
        if(visited[i] == 0){
            queue.push(i);
            visited2[i] = 1;
        }
    }
    
    bfs(queue);
    
    
    return 0;
}
