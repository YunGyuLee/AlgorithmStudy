//
//  main.cpp
//  sam4014
//
//  Created by new_mac on 2019. 8. 4..
//  Copyright © 2019년 new_mac. All rights reserved.
//

//첫 제출 56분만에 --> 실패....(테스트 케이스는 다 맞았음)
//1시간 20분만에 정답!! --> 시험장에서 만날수있는 최악의 케이스인듯하다. 테스트 케이스에는 걸리지않았지만 정답이 틀린경우였다...
//경사로를 설치할 수 있는 구간을 세는 변수를 초기화를 잘못해주어서 틀렸다.... 좀더 집중해서 코딩하는 것이 필요한듯 하다!

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const int MAX_N = 21;
int map[MAX_N][MAX_N];
int n,x;


bool is_make_r(int num){
  //  cout<<num<<" 행"<<endl;
    bool result = true;
    int same_cnt =1;
    for(int i=0;i<n-1;i++){
        
        
        if(map[num][i] == map[num][i+1]){
            same_cnt++;
        }else if(map[num][i] < map[num][i+1]){
            if(map[num][i+1] - map[num][i] > 1){
                return false;
            }else{
                if(same_cnt < x){
                    return false;
                }else{
                    same_cnt = 1;
                }
            }
        }else{
            if(map[num][i] - map[num][i+1] > 1){
                return false;
            }else{
                int now_y = num;
                int now_x = i+1;
                int cnt = 1;
                while(1){
           //         cout<<"현재: "<<now_x<<endl;
                    if(cnt == x){
                        i = now_x-1;
                        same_cnt = 0;
                        break;
                    }
                    int t_y = now_y;
                    int t_x = now_x;
                    now_y  = now_y;
                    now_x = now_x + 1;
                    if(now_x>n-1){
           //             cout<<"범위 아웃: "<<now_x<<endl;
                        return false;
                    }
                    if(map[now_y][now_x] == map[t_y][t_x]){
                        ++cnt;
                    }else{
                        return false;
                    }
                    
                }
                
                
            }
        }
        
        
    }
    return result;
    
}

bool is_make_c(int num){
    //  cout<<num<<" 행"<<endl;
    bool result = true;
    int same_cnt =1;
    for(int i=0;i<n-1;i++){
        if(map[i][num] == map[i+1][num]){
            same_cnt++;
        }else if(map[i][num] < map[i+1][num]){
            if(map[i+1][num] - map[i][num] > 1){
                return false;
            }else{
                if(same_cnt < x){
                    return false;
                }else{
                    same_cnt = 1;
                }
            }
        }else{
            if(map[i][num] - map[i+1][num] > 1){
                return false;
            }else{
                int now_y = i+1;
                int now_x = num;
                int cnt = 1;
                while(1){
                    //         cout<<"현재: "<<now_x<<endl;
                    if(cnt == x){
                        i = now_y-1;
                        same_cnt = 0;
                        break;
                    }
                    int t_y = now_y;
                    int t_x = now_x;
                    now_y  = now_y +1;
                    now_x = now_x;
                    if(now_y>n-1){
                        //             cout<<"범위 아웃: "<<now_x<<endl;
                        return false;
                    }
                    if(map[now_y][now_x] == map[t_y][t_x]){
                        ++cnt;
                    }else{
                        return false;
                    }
                    
                }
                
                
            }
        }
        
        
    }
    return result;
    
}


int simul(){
    int result = 0;
    for(int i=0;i<n;i++){
        if(is_make_r(i)){
            result++;
        }
        if(is_make_c(i)){
            result++;
        }
    }
    
    return result;
    
}



int main(int argc, const char * argv[]) {
    int T = 0;
    scanf("%d",&T);
    for(int testcase = 1; testcase<=T;testcase++){
        scanf("%d %d",&n,&x);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&map[i][j]);
            }
            
        }
        printf("#%d %d\n",testcase,simul());
        
    }
    
    
    return 0;
}
