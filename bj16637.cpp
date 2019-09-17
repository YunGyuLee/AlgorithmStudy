//
//  main.cpp
//  bj16637
//
//  Created by new_mac on 2019. 9. 6..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//1시간 7분 첫 제출 틀렸습니다.
//총 시간 2시간 20분 맞았습니다. --> 결국 배열의 범위문제였다.
#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;
int n;

char s[9];
int c_num[10];

int visited[11];
int id=1;
long long answer = INT64_MIN;


bool check(int start,int num){
    if(start+num-1>((n+1)/2)-1)
        return false;
    else
        return true;
}

void go(int start,int num){
    for(int i=start;i<=start+num-1;i++){
        visited[i] = id;
    }
}

void print_v(){
    for(int i=0;i<((n+1)/2);i++){
        printf("%d ",visited[i]);
    }
    printf("\n");
}

int convert(int a,int b,char c){
    if(c == '+'){
        return a+b;
    }else if(c == '*')
        return a*b;
    else if(c == '-')
        return a-b;
    else
        return -1;
}

int calc(){
    int s_cnt = 0;
    int temp[10] ={0,};
    char s_temp[10];
    int cnt = 0;
    int result = c_num[0];
    for(int i=0;i<((n+1)/2);i++){
        
        if(visited[i] == visited[i+1]){
            result = convert(result, c_num[i+1], s[s_cnt]);
            s_cnt++;
        }else if(visited[i] != visited[i+1]){
            temp[cnt] = result;
            result = c_num[i+1];
            s_temp[cnt] = s[s_cnt];
            s_cnt++;
            cnt++;
            
        }
    }
    int sum = temp[0];
    for(int i=1;i<cnt;i++){
        sum = convert(sum, temp[i], s_temp[i-1]);
    }
    
    return sum;

}



void dfs(int depth){
   
    if(depth == ((n+1)/2)){
        //계산함수
        
        if(depth == 1){
            answer = c_num[0];
            return;
        }
        int result = calc();
        if(answer < result)
            answer = result;
        return;
    }
    int t_visited[11] = {0,};
    memcpy(t_visited, visited, sizeof(visited));
    
    for(int i=1;i<=2;i++){
        if(check(depth, i)){
            go(depth,i);
            id++;
            dfs(depth+i);
            memcpy(visited, t_visited, sizeof(visited));
            id--;
        }else
            break;
    }
    
    

}


int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    string temp;
    cin>>temp;
    int n_cnt=0;
    int s_cnt=0;
    for(int i=0;i<n;i++){
        if(temp[i] >= '0' && temp[i] <= '9'){
            c_num[n_cnt] = temp[i] - '0';
            n_cnt++;
        }else{
            s[s_cnt] = temp[i];
            s_cnt++;
        }
            
    
    }
   
    
    dfs(0);
    cout<<answer<<endl;
    
    
    
    return 0;
}
