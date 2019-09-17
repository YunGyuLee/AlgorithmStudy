//
//  main.cpp
//  sam2383_re
//
//  Created by new_mac on 2019. 9. 4..
//  Copyright © 2019년 new_mac. All rights reserved.
//
// 1시간 19분 풀이완료. 바로 정답.
#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;
int n;
struct info{
    int y;
    int x;
    int length;
};
info stair[2];
vector<pair<int,int>> P;


bool cmp(int a,int b){
    if(a >b)
        return true;
    else
        return false;
}


int move(vector<pair<int,int>> people,int num){//num은 계단 번호
    int result = 0;
    int dis[11] = {0,};
    int ent[11] = {0,};
    int Stair[4] = {0,};
    for(int i=0;i<people.size();i++){
        int d = abs(people[i].first - stair[num].y) + abs(people[i].second - stair[num].x);
        dis[dis[0]+1] = d;
        dis[0]++;
    }
    sort(dis+1,dis+dis[0]+1,cmp);
    
    while(1){
        result++;
        //계단을 내려감.
        int size = Stair[0];
        for(int i=1;i<=size;i++){
            Stair[i] -= 1;
            if(Stair[i] == 0){
                Stair[0]--;
            }
            
        }
        sort(Stair+1, Stair+size+1, cmp);
        
        
        //계단 입구에서 계단으로 이동
        size = ent[0];
        for(int i=1;i<=size;i++){
            int s_size = Stair[0];
            if(s_size != 3){
                Stair[s_size+1] = ent[i];
                Stair[0]++;
                ent[i] = 0;
                ent[0]--;
            }
            
        }
        sort(ent+1,ent+size+1,cmp);
        
        
        
        //입구까지 이동
        size = dis[0];
        for(int i=1;i<=size;i++){
            dis[i] -= 1;
            if(dis[i] == 0){
                ent[ent[0]+1] = stair[num].length;
                ent[0]++;
                dis[0]--;
            }
            
        }
        sort(dis+1,dis+size+1,cmp);
        
        if(ent[0] == 0 && dis[0] == 0 && Stair[0] == 0)
            break;
        
        
        
    }
    
    return result;
    
    
}



int simul(){
    int answer = 1000;
    for(int i=0;i<=P.size();i++){
        vector<int> select;
        for(int j=0;j<P.size();j++){
            if(j<i){
                select.push_back(1);
            }else
                select.push_back(0);
        }
        
        sort(select.begin(),select.end());
        do{
            vector<pair<int,int>> A;
            vector<pair<int,int>> B;
            for(int i=0;i<select.size();i++){
                if(select[i] == 1){
                    A.push_back(P[i]);
                }else
                    B.push_back(P[i]);
            }
            int result = max(move(A,0),move(B,1));
            if(result < answer)
                answer = result;
            A.clear();
            B.clear();
        
        }while(next_permutation(select.begin(), select.end()));
        
        select.clear();
        
        
    }
    
    return answer;

}




int main(int argc, const char * argv[]) {
    int T = 0;
    scanf("%d",&T);
    for(int testcase = 1;testcase<=T;testcase++){
        scanf("%d",&n);
        P.clear();
        memset(stair,0,sizeof(stair));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int temp = 0;
                scanf("%d",&temp);
                if(temp >1 && temp <=10){
                    if(stair[0].length == 0){
                        stair[0] = info{i,j,temp};
                    }else{
                        stair[1] = info{i,j,temp};
                    }
                }else if(temp == 1){
                    
                   P.push_back(make_pair(i,j));
                }
        
            }
        }
        
        
        printf("#%d %d\n",testcase,simul());
        
        
        
    }
    return 0;
}
