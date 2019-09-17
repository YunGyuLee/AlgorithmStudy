//
//  main.cpp
//  sam7465
//
//  Created by new_mac on 2019. 8. 5..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//20분만에 풀이완료 --> 연결요소 찾기 문제.


#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
const int MAX_N = 102;
const int MAX_Q = 1000;
int n,m;
int visited[MAX_N];
vector<int> list[MAX_N];
int q[MAX_Q];
int head;
int rear;
int q_size;

bool empty(){
    if(head == rear)
        return true;
    else
        return false;
}

bool full(){
    if(head == (rear+1)%MAX_Q)
        return true;
    else
        return false;
}

int front(){
    int result = 0;
    if(empty())
        return result;
    else{
        result = q[head];
        return result;
    }
}

bool push(int num){
    if(full())
        return false;
    else{
        q[rear] = num;
        rear = (rear+1)%MAX_Q;
        q_size++;
        return true;
    }
}
bool pop(){
    if(empty())
        return false;
    else{
        head = (head+1)%MAX_Q;
        q_size--;
        return true;
    }
}



void bfs(int num){
    push(num);
    visited[num] = 1;
    while(!empty()){
        int now = front();
        pop();
        for(int i=0;i<list[now].size();i++){
            int next = list[now][i];
            if(visited[next] == 1)
                continue;
            visited[next] = 1;
            push(next);
        }
        
    }

}

int main(int argc, const char * argv[]) {
    int T = 0;
    scanf("%d",&T);
    for(int testcase=1;testcase<=T;testcase++){
        scanf("%d %d",&n,&m);
        int result = 0;
        memset(visited,0,sizeof(visited));
        for(int i=0;i<MAX_N;i++){
            list[i].clear();
        }
        
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            list[a].push_back(b);
            list[b].push_back(a);
        
        
        }
        
        for(int i=1;i<=n;i++){
            if(visited[i] == 0){
                bfs(i);
                result++;
            }
                
        }
        
        printf("#%d %d\n",testcase,result);
        
        
    }
    return 0;
}
