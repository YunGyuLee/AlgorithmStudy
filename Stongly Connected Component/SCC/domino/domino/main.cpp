//
//  main.cpp
//  domino
//
//  Created by new_mac on 2019. 7. 17..
//  Copyright © 2019년 new_mac. All rights reserved.
//

//----도미노 문제----
//처음에 list를 지역변수로 선언하여 메모리 오류가 났다. clear 해주지 않았기 때문에 계속 메모리에 남아있었던것이 문제가 되었던것 같다.
//전역 변수로 선언하고 초기화를 해줌으로써 해결하였다.
//해당 문제는 진입차수가 0인 SCC의 개수를 찾으면 되는 문제였다. SCC들의 진입차수는 각 정점이 어떤 그룹에 속해있는지를 알게되면 쉽게 구할 수 있다. 이때 정점의 그룹을 저장할 배열을 추가로 만들어서 해당 정점의 그룹을 미리 표시해 놓는다(dfs에서 stack에서 뽑을 시) 

//----축구전술 문제-----
//SCC들 끼리의 관계에서 하나의 정점에서 모든 정점들을 방문 가능하려면 진입차수가 0인 SCC가 무조건 1개만 존재해야한다.
// --> 즉, 진입차수가 0인 SCC가 한개일때 그 원소들을 출력하는 문제.
//타잔 알고리즘의 정확한 이해가 부족하여 stack에서 빠져나오는 순서를 해깔려서 SCC가 만들어지는 순서를 잘못 판단했다. --> 해결완료.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAX_N = 100002;


int n,m;
int v_id[MAX_N];
bool finished[MAX_N];
int id;
int group[MAX_N];
int indegree[MAX_N];
vector<vector<int>> SCC;
vector<int> list[MAX_N];
stack<int> s;

int dfs(int x){
    v_id[x] = ++id;
    int parent = v_id[x];
    s.push(x);
    for(int i=0;i<list[x].size();i++){
        int next = list[x][i];
        if(v_id[next] == 0){
            parent = min(parent,dfs(next));
        }else if(!finished[next]){
            parent = min(parent,v_id[next]);
        }
    }
    
    if(parent == v_id[x]){
        vector<int> scc;
        while(1){
            int temp = s.top();
            s.pop();
            scc.push_back(temp);
            group[temp] = SCC.size() + 1;
            finished[temp] = true;
            if(temp == x)
                break;
        }
        sort(scc.begin(),scc.end());
        SCC.push_back(scc);
        
    }
    return parent;
    
}




int main(int argc, const char * argv[]) {
    int T = 0;
    scanf("%d",&T);
    for(int testcase=1;testcase<=T;testcase++){
        scanf("%d %d",&n,&m);
        SCC.clear();
        memset(v_id,0,sizeof(v_id));
        memset(finished,false,sizeof(finished));
        memset(group,0,sizeof(group));
        memset(indegree,0,sizeof(indegree));
        id = 0;
        for(int i=0;i<n;i++){
            list[i].clear();
        }
        
        for(int i=0;i<m;i++){
            int v1,v2;
            scanf("%d %d",&v1,&v2);
            list[v1].push_back(v2);
        }
        
        for(int i=0;i<n;i++){
            if(v_id[i] == 0)
                dfs(i);
        }
    
        for(int i=0;i<n;i++){
            for(int j=0;j<list[i].size();j++){
                int next = list[i][j];
                if(group[i] != group[next]){
                    ++indegree[group[next]];
                }
                    
            }
        }
        int result = 0;
        int g = -1;
       
        
        for(int i=0;i<SCC.size();i++){
            if(indegree[i+1] == 0){
                result++;
                g = i;
            }
        }
        
        
        if(result == 0 || result >= 2)
            printf("Confused\n");
        else{
            for(int i=0;i<SCC[g].size();i++){
                printf("%d\n",SCC[g][i]);
            }
        }
            
        
        printf("\n");
    
    }
    return 0;
}
