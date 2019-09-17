//
//  main.cpp
//  critical_path
//
//  Created by new_mac on 2019. 7. 5..
//  Copyright © 2019년 new_mac. All rights reserved.
//

//역추적을 수행하는 것을 실패하였다.!!!
//visited에 구해놓은 값을 이용하여 역추적한다.!!

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;


const int MAX_N = 10002;
int n,m;
vector<pair<int,int>> list[MAX_N];
vector<pair<int,int>> in_list[MAX_N];
int indegree[MAX_N];
int visited[MAX_N];
int start,end_p;
int answer = 0;
int in_visited[MAX_N];

void bfs(queue<int> queue){
    
        while(!queue.empty()){
            int now = queue.front();
            queue.pop();
            
            for(int i=0;i<list[now].size();i++){
                int next = list[now][i].first;//다음 정점
                int t = list[now][i].second;//이동시간
                visited[next] = max(visited[next], visited[now] + t);
                indegree[next] -= 1;
                if(indegree[next] == 0){
                    queue.push(next);
                }
                
            }
            
        }
    
    queue.push(end_p);
    int cnt = 0;
    while(!queue.empty()){
        int now = queue.front();
        queue.pop();
        for(int i=0;i<in_list[now].size();i++){
            int next = in_list[now][i].first;
            int t = in_list[now][i].second;
            if(visited[now] - visited[next] == t){
                cnt++;
                if(in_visited[next] == 0){//역추적할 때 이미 방문한 노드라면 그 이후의 노드는 카운팅 할 필요가 없으므로!!!
                    queue.push(next);
                    in_visited[next] = 1;
                }
            }
            
        }
        
        
    }
    
    cout<<visited[end_p]<<endl;
    cout<<cnt<<endl;
    

}
//중복되는 것들 까지 모두 세어주기 때문에 시간초과가 발생.  --> 기본적으로 너무 복잡하다!!
/*
int dfs(int now,int total,int cnt){
    
    
    
    if(now == end_p){
        if(total == visited[end_p]){
            answer += cnt;
            return 1;
        }else
            return -1;
            
    }
    
    for(int i=0;i<list[now].size();i++){
        int next = list[now][i].first;
        int t = list[now][i].second;
        if(t>0){
            cnt++;
        }
        if(vt[next] == 1){
            dfs(end_p,total + visited[end_p] - visited[next],cnt);
        }else{
           if(dfs(next,total + abs(t),cnt) == 1){
            list[now][i].second = -list[now][i].second;
            vt[now] = 1;
        }
        }
        if(t>0){
            cnt--;
        }
        
            
    }
    
    return 1;

}
*/
int main(int argc, const char * argv[]) {
    
    queue<int> queue;
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int s =0, d = 0, t = 0;
        scanf("%d %d %d",&s,&d,&t);
        list[s].push_back(make_pair(d,t));
        in_list[d].push_back(make_pair(s,t));
        indegree[d] +=1;
    }
    
    scanf("%d %d",&start,&end_p);
    
    queue.push(start);
    bfs(queue);
  
  
    
    return 0;
}
