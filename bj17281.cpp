//
//  main.cpp
//  bj17281
//
//  Created by new_mac on 2019. 9. 12..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//아... 시발.... 우선 시간내에 못푼 이유 --> memset에서 사이즈를 0으로 넣어줘서 초기화가 제대로 안되고 있었던것...
//나머지 구현들은 정확했다...



#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const int MAX_N = 51;
int n;
int ining[MAX_N][9];
int seq[9] = {0,0,0,1,0,0,0,0,0};//1~9까지의 값들을 저장
int visited[10];

int start;

int out;
int map[4];
int answer;
int Answer = -1;


void print_m(){
    for(int i=0;i<4;i++){
        printf("%d ",map[i]);
    
    }
    printf("\n");
}

void print_s(){
    for(int i=0;i<9;i++){
        printf("%d ",seq[i]);
        
    }
    printf("\n");
}

int move(int num){
    int temp[4] = {0,};
    int result = 0;
    map[0] = 1;
    for(int i=0;i<4;i++){
        if(i+num>3){
            if(map[i] == 1){
                result++;
            }
            continue;
        }
        
        temp[i+num] = map[i];
    }
    memcpy(map, temp, sizeof(map));
    
    return result;
    
    
}

void go_one(int i_num){
    int index = start;
    
    int now_num = seq[index];
    
    int result = ining[i_num][now_num-1];
    
    
    while(1){
        
        
        if(result == 0){
            out++;
            if(out == 3)
                break;
        }else if(result == 2){
            answer += move(2);
        }else if(result == 3){
            answer += move(3);
        }else if(result == 4){
            answer += move(4);
        }else if(result == 1){
            answer += move(1);
        }
        
      //  printf("타자: %d, 결과: %d,점수: %d\n",now_num,result,answer);
      //  print_m();
        index = (index+1)%9;
        now_num = seq[index];
        result = ining[i_num][now_num-1];
    
    }
  
    start = (index+1)%9;
    out = 0;
    memset(map,0,sizeof(map));

}


void t_go_one(int i_num){
    int index = start;
    
    int now_num = seq[index];
    
    int result = ining[i_num][now_num-1];
    
    
    while(1){
        
        
        if(result == 0){
            out++;
            if(out == 3)
                break;
        }else if(result == 2){
            answer += move(2);
        }else if(result == 3){
            answer += move(3);
        }else if(result == 4){
            answer += move(4);
        }else if(result == 1){
            answer += move(1);
        }
        
        printf("타자: %d, 결과: %d,점수: %d\n",now_num,result,answer);
        print_m();
        index = (index+1)%9;
        now_num = seq[index];
        result = ining[i_num][now_num-1];
        
    }
    cout<<"이닝 끝"<<endl;
    start = (index+1)%9;
    out = 0;
    memset(map,0,sizeof(map));
    
}

void t_game(){
    for(int i=0;i<n;i++){
        t_go_one(i);
    }
}

void game(){
   
    for(int i=0;i<n;i++){
        
        go_one(i);
        
    }

}

void dfs(int depth){
    
    if(depth == 9){
        
        start = 0;
        memset(map,0,sizeof(map));
        out = 0;
        answer = 0;
        game();
        
    
        if(Answer < answer)
            Answer = answer;
        return;
    }
        
    
    if(depth == 3){
        dfs(depth+1);
        return;
    }
    
    for(int i=2;i<=9;i++){
        if(visited[i] == 0){
            visited[i] = 1;
            seq[depth] = i;
            dfs(depth+1);
            seq[depth] = 0;
            visited[i] = 0;
        }
    }

}



int main(int argc, const char * argv[]) {
    
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<9;j++){
            scanf("%d",&ining[i][j]);
        }
    }
    
    dfs(0);
    printf("%d\n",Answer);
    
    return 0;
}
