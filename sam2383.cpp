//
//  main.cpp
//  sam2383
//
//  Created by new_mac on 2019. 8. 5..
//  Copyright © 2019년 new_mac. All rights reserved.
//

//2시간 10분만에 풀이완료 --> 바로 정답.
//세부 구현이 까다로운 문제이긴 하였으나 시간을 잡아먹은 부분은 문제의 조건을 정확하게 읽지않아 계단의 길이가 1보다 크다는 것을 계단이 2를
//나타내는 것으로 잘못 파악하여 초기 계단의 좌표입력을 잘못받고있었음.
//comp함수를 구현해놓고 실수로 sort시에 적용하지않아서 이상한 값들이 출력되엇음.

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;
int n;
const int MAX_N = 11;
int map[MAX_N][MAX_N];
int st1_y=-1,st1_x=-1;
int st2_y=-1,st2_x=-1;
vector<pair<int,int>> A;
vector<pair<int,int>> B;


bool comp(int a,int b){
    if(a>b)
        return true;
    else
        return false;
}

int calcul_time(){
    vector<int> A_t;
    vector<int> B_t;
    for(int i=0;i<A.size();i++){//계단까지 이동하는 시간저장
        int t = abs(A[i].first - st1_y) + abs(A[i].second - st1_x);
        A_t.push_back(t);
      //  cout<<t<<endl;
    }
    for(int i=0;i<B.size();i++){
        int t = abs(B[i].first - st2_y) + abs(B[i].second - st2_x);
        B_t.push_back(t);
      //  cout<<t<<endl;
    }
    
    int result = 0;
    int wait1 = 0;
    int wait2 = 0;
    int stair1[4] = {0,};
    int stair2[4] = {0,};
    //A_t,B_t와. stair가 모두 비었으면 끝!
    while(1){
        
        
        
//        cout<<result<<"초"<<endl;
        
        //A,B가 계단에 도착하는지
        for(int i=0;i<A_t.size();i++){
            if(A_t[i] == 0){
                A_t[i] = -1;
                wait1++;
            }
        }
 //       cout<<wait1<<endl;
        
        for(int i=0;i<B_t.size();i++){
            if(B_t[i] == 0){
                B_t[i] = -1;
                wait2++;
            }
        }
//        cout<<wait2<<endl;
        //계단을 내려감.
        
 /*       for(int i=0;i<4;i++){
            printf("%d ",stair1[i]);
        }printf("\n");
        
        for(int i=0;i<4;i++){
            printf("%d ",stair2[i]);
        }printf("\n");
  */

        int size = stair1[0];
        for(int i=1;i<=size;i++){//계단을 내려감
            if(stair1[i] > 0){
                --stair1[i];
                if(stair1[i] == 0)
                    --stair1[0];
            }
        }
        sort(stair1+1,stair1+4,comp);
 //       cout<<stair1[0]<<endl;
        size = stair2[0];
        for(int i=1;i<=size;i++){//계단을 내려감
            if(stair2[i] > 0){
                --stair2[i];
                if(stair2[i] == 0)
                    --stair2[0];
            }
        }
        sort(stair2+1,stair2+4,comp);
        
   //     cout<<stair2[0]<<endl;
        
        
        //입구에서 계단으로 이동
        size = wait1;
        for(int i=0;i<size;i++){
            if(stair1[0]<3){//계단에 오를수 있음.
                int cnt = stair1[0];
                stair1[0]++;
                stair1[cnt+1] = map[st1_y][st1_x];//계단길이
                wait1--;
            }else
                break;

        }
        size = wait2;
        for(int i=0;i<size;i++){
            if(stair2[0]<3){//계단에 오를수 있음.
                int cnt = stair2[0];
                stair2[0]++;
                stair2[cnt+1] = map[st2_y][st2_x];//계단길이
                wait2--;
            }else{
                break;
            }

        
        
        }
        int A_cnt=0;
        int B_cnt=0;
        
        for(int i=0;i<A_t.size();i++){
            --A_t[i];
            if(A_t[i]<0)
                A_cnt++;
                
        }
        
        
        for(int i=0;i<B_t.size();i++){
            --B_t[i];
            if(B_t[i]<0)
                B_cnt++;
        }

        if(A_cnt == A_t.size() && B_cnt == B_t.size() && stair1[0] == 0 && stair2[0] == 0)
            break;
        
        result++;
        
        
    
    
    }
    
    
    A_t.clear();
    B_t.clear();
    
    return result+1;
    

}





int make_team(int num,vector<pair<int,int>> p){
    int result = INT32_MAX;
    vector<int> select;
    for(int i=0;i<p.size();i++){
        if(i<num){
            select.push_back(1);
        }else
            select.push_back(0);
    }
    sort(select.begin(), select.end());
    do{
        A.clear();
        B.clear();
        for(int i=0;i<select.size();i++){
            if(select[i] == 0)
                A.push_back(make_pair(p[i].first,p[i].second));
            else
                B.push_back(make_pair(p[i].first,p[i].second));
        }
        
        int temp = calcul_time();
        if(temp < result)
            result = temp;
        
    
    
    }while(next_permutation(select.begin(), select.end()));
    select.clear();
    
    return result;
    
    

}




int main(int argc, const char * argv[]) {
    int T = 0;
    scanf("%d",&T);
    for(int testcase = 1;testcase<=T;testcase++){
        scanf("%d",&n);
        vector<pair<int,int>> p;
        st1_y=-1,st1_x=-1;
        st2_y=-1,st2_x=-1;
        int answer = INT32_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int temp = 0;
                scanf("%d",&temp);
                map[i][j] = temp;
                if(temp == 1){
                    p.push_back(make_pair(i,j));
                }else if(temp > 1 ){
                    if(st1_y == -1){
                        st1_y = i;
                        st1_x = j;
                    }else{
                        st2_y = i;
                        st2_x = j;
                    }
                    
                    
                    
                    
                
                }
                
                
            }
        }
        
  /*      A.push_back(make_pair(0,2));
        A.push_back(make_pair(0,3));
        A.push_back(make_pair(1, 2));
        A.push_back(make_pair(2, 3));
        B.push_back(make_pair(4, 0));
        B.push_back(make_pair(3, 1));
  */
        for(int i=0;i<=p.size();i++){
            int temp = make_team(i, p);
            if(temp < answer)
                answer = temp;
        }
        printf("#%d %d",testcase,answer);
    
    }
    return 0;
}
