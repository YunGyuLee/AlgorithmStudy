//
//  main.cpp
//  bj15686
//
//  Created by new_mac on 2019. 8. 5..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//33분 만에 풀이완료!!
#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int n,m;
vector<pair<int,int>> chi;
vector<pair<int,int>> house;


int cal_chi(vector<int> select){
    int result = 0;
    for(int i=0;i<house.size();i++){
        int min_d = INT32_MAX;
        for(int j=0;j<chi.size();j++){
            if(select[j] == 0)
                continue;
            int temp = abs(house[i].first - chi[j].first) + abs(house[i].second - chi[j].second);
            if(temp < min_d)
                min_d = temp;
        }
        result += min_d;
        
    }
    
    return result;
    
    
}


int simul(int num){
    int result = INT32_MAX;
    vector<int> select;
    for(int i=0;i<chi.size();i++){
        if(i<num)
            select.push_back(1);
        else
            select.push_back(0);
    }
    sort(select.begin(),select.end());
    
    do{
        int temp = cal_chi(select);
        if(result > temp)
            result = temp;
        
    
    }while(next_permutation(select.begin(), select.end()));
    select.clear();
    
    return result;

}

int go(){
    int result = INT32_MAX;
    for(int i=1;i<=m;i++){
        int temp = simul(i);
        if(result > temp)
            result= temp;
    }
    return result;

}






int main(int argc, const char * argv[]) {
    scanf("%d %d",&n,&m);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int temp = 0;
            scanf("%d",&temp);
            if(temp == 2){
                chi.push_back(make_pair(i,j));
            }else if(temp == 1){
                house.push_back(make_pair(i,j));
            }
        }
    }
    
    printf("%d\n",go());
    
    
    
    
    return 0;
}
