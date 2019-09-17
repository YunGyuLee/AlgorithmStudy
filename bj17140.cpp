//
//  main.cpp
//  bj17140
//
//  Created by new_mac on 2019. 7. 30..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//1시간 18분 풀이 완료.
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;


const int MAX_N = 100;
int r,c,k;
int A[MAX_N][MAX_N];
int Answer;
int r_length =3;
int c_length =3;

bool comp(pair<int,int> a, pair<int,int> b){
    if(a.second < b.second){
        return true;
    }else if(a.second == b.second){
        if(a.first < b.first){
            return true;
        }else
            return false;
    }else
        return false;

}




int sorting(int d,int num){
    int length = 0;
    int visited[101] = {0,};
    
    if(d == 0){//행이면
        vector<pair<int,int>> list;
        
        for(int i=0;i<MAX_N;i++){
            int value = A[num][i];
            if(value == 0)
                continue;
            visited[value]++;
        }
        for(int i=1;i<=100;i++){
            if(visited[i] != 0){
                list.push_back(make_pair(i,visited[i]));
            }
        }
        
        for(int i=0;i<MAX_N;i++){
            A[num][i] = 0;
        }
        
        sort(list.begin(),list.end(),comp);
        length = 2*list.size();
        if(length>100)
            length = 100;
        for(int i=0;i<list.size();i++){
            if(2*i>99){
                break;
            }
            A[num][2*i] = list[i].first;
            A[num][2*i+1] = list[i].second;
        }
        
        
        
    }else{//열이면
        vector<pair<int,int>> list;
        
        for(int i=0;i<MAX_N;i++){
            int value = A[i][num];
            if(value == 0)
                continue;
            visited[value]++;
        }
        for(int i=1;i<=100;i++){
            if(visited[i] != 0){
                list.push_back(make_pair(i,visited[i]));
            }
        }
        
        for(int i=0;i<MAX_N;i++){
            A[i][num] = 0;
        }
        
        sort(list.begin(),list.end(),comp);
        length = 2*list.size();
        if(length>100)
            length = 100;
        for(int i=0;i<list.size();i++){
            if(2*i>99){
                break;
            }
            A[2*i][num] = list[i].first;
            A[2*i+1][num] = list[i].second;
        }
        

    
    }
    
    return length;

}

void calcul(){
    if(c_length >= r_length){
        int result = -1;
        for(int i=0;i<c_length;i++){
           int temp = sorting(0, i);
            if(temp > result)
                result = temp;
        }
        r_length = result;
        
    }else{
        int result = -1;
        for(int i=0;i<r_length;i++){
            int temp = sorting(1, i);
            if(temp > result)
                result = temp;
        }
        c_length = result;
    }
}


void print_m(){
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    
    
}



void simul(){
    
    
    for(int i=0;i<=100;i++){
        if(A[r-1][c-1] == k){
            Answer = i;
            return;
        }
      //  print_m();
        
        calcul();
        
    }
    
    Answer = -1;

}




int main(int argc, const char * argv[]) {
    scanf("%d %d %d",&r,&c,&k);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&A[i][j]);
        }
    }
    simul();
    printf("%d\n",Answer);
    
    
    return 0;
}
