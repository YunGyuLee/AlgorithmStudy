//
//  main.cpp
//  SCC
//
//  Created by new_mac on 2019. 7. 16..
//  Copyright © 2019년 new_mac. All rights reserved.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <math.h>

using namespace std;
const int MAX_V = 10002;
int v,e;
vector<int> list[MAX_V];
stack<int> s;
vector<vector<int>> SCC;
int v_id[MAX_V];
int id;
bool finished[MAX_V];

bool comp(vector<int> a,vector<int> b){
    if(a[0] < b[0])
        return true;
    else
        return false;

}


int dfs(int x){
    v_id[x] = ++id;//노드의 번호가 아닌 id로 설정해 주는 이유는 시작 노드의 순서에 관계없이 부모노드를 id의 값이 작은 것을 통일하기 위해서이다.
    int parent = v_id[x];
    s.push(x);
    for(int i=0;i<list[x].size();i++){
        int next = list[x][i];
        //방문하지 않은 노드 처리
        if(v_id[next] ==0){
            parent = min(parent,dfs(next));
        //방문은 했지만 현재 dfs를 수행중인 노드를 만났을 때 처리
        }else if(!finished[next]){
            parent = min(parent,v_id[next]);
        }
    }
    
    //자기자신이 부모임을 알아챘을 때 스택에서 자신을 만날때 까지 뽑는다.
    if(parent == v_id[x]){
        vector<int> scc;
        while(1){
            int temp = s.top();
            s.pop();
            scc.push_back(temp);
            finished[temp] = true;//스텍에서 뽑히고 나면 완전히 dfs가 끝났다고 볼 수 있다.
            if(temp == x)
                break;
        }
        SCC.push_back(scc);
    }
    
    
    return parent;
    

}


int main(int argc, const char * argv[]) {
    scanf("%d %d",&v,&e);
    for(int i=0;i<e;i++){
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        list[v1].push_back(v2);
    }
    
    for(int i=1;i<=v;i++){
        if(v_id[i] == 0)
            dfs(i);
    }
    
    
    for(int i=0;i<SCC.size();i++){
        sort(SCC[i].begin(),SCC[i].end());
    }
    
    sort(SCC.begin(),SCC.end(),comp);
    
    cout<<SCC.size()<<endl;
    for(int i=0;i<SCC.size();i++){
        for(int j=0;j<SCC[i].size();j++){
            printf("%d ",SCC[i][j]);
        }
        printf("%d\n",-1);
    }
    
    
    
    return 0;
}
