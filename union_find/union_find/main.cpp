//
//  main.cpp
//  union_find
//
//  Created by new_mac on 2019. 6. 22..
//  Copyright © 2019년 new_mac. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge{
    int node_a;
    int node_b;
    int distance;
};


bool comp(Edge a, Edge b){
    if(a.distance < b.distance){
        return true;
    }else
        return false;
}


int getParent(int parent[],int x){
    if(parent[x] == x)
        return x;
    else
        return getParent(parent, parent[x]);
}

void unionParent(int parent[],int a, int b){
    
    a = getParent(parent, a);
    b = getParent(parent, b);
    
    if(a<b){
        parent[b] = a;
    }else{
        parent[a] = b;
    }
}


bool isShareParent(int parent[],int a,int b){
    a = getParent(parent, a);
    b = getParent(parent,b);
    if(a == b)
        return true;
    else
        return false;
}


int main(int argc, const char * argv[]) {
   
    const int MAX_N = 10000;
    int n=0,m=0;
    vector<Edge> edge;
    
    scanf("%d",&n);
    scanf("%d",&m);
    
    
    for(int i=0;i<m;i++){
        int a=0,b=0,c=0;
        scanf("%d %d %d",&a,&b,&c);
        edge.push_back(Edge{a,b,c});
    }
    
    
    int parent[MAX_N] = {0,};
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
    
    sort(edge.begin(),edge.end(),comp);
    int sum = 0;
    for(int i=0;i<m;i++){
        
        if(!isShareParent(parent, edge[i].node_a-1, edge[i].node_b-1)){
            sum = sum + edge[i].distance;
            unionParent(parent, edge[i].node_a-1, edge[i].node_b-1);
        }
    }
    
    cout<<sum<<endl;
    
    return 0;
}
