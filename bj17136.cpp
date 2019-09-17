//
//  main.cpp
//  bj17136
//
//  Created by new_mac on 2019. 8. 28..
//  Copyright © 2019년 new_mac. All rights reserved.
//

//첫 55분 제출시 틀렸습니다..!!
//30분 동안 더 고민해봤는데 도저히 무엇이 문제인지 모르겠음..
//백트레킹 문제였다.... --> 재귀함수의 시간복잡도를 계산하는 방법 숙지할것!
//-->백트레킹인데... --> 좀더 연습하자..
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const int MAX_N = 10;
int map[MAX_N][MAX_N];

int answer;
int total;
int chance[5] = {5,5,5,5,5};
int Answer = 100;

void print_m(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool find_area(int y,int x,int num){
    if(y+num-1>9 || x+num-1>9)
        return false;
    //범위 확인
    
    
    for(int i=y;i<y+num;i++){
        for(int j=x;j<x+num;j++){
            if(map[i][j] == 0)
                return false;
            //겹치는거 확인
        }
    }
    
    return true;


}



void draw_area(int y,int x,int num){
    
    answer++;
    for(int i=y;i<y+num;i++){
        for(int j=x;j<x+num;j++){
            map[i][j] = 0;
        }
    }
    total -= num*num;
    
    
}





void dfs(int y,int x,int num){
    
    if(answer > Answer)
        return;
    
    int t_map[MAX_N][MAX_N];
    memcpy(t_map, map, sizeof(map));
    
    if(total == 0){
        if(Answer > answer)
            Answer = answer;
        return;
    }
    
    
    for(int i=0;i<10;i++){
        
        for(int j=0;j<10;j++){
            
            if(map[i][j] == 0)
                continue;
           
            for(int k=5;k>=1;k--){
                if(chance[k-1] == 0)
                    continue;
                
                if(find_area(i, j,k)){
                    int temp = answer;
                    int t_total = total;
                    draw_area(i, j,k);
                    --chance[k-1];
                    dfs(i, j, k);
                    ++chance[k-1];
                    answer = temp;
                    total = t_total;
                    memcpy(map, t_map, sizeof(map));
                
                }
            }
            
            return;
        }
        
    }
    
    
    

}



void go(){
    
    int num = 5;
    while(1){
        print_m();
        if(total == 0)
            break;
        if(num == 0){
            answer = -1;
            break;
        }

        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(map[i][j] == 0)
                    continue;
                if(find_area(i, j, num)){
                    draw_area(i, j, num);
                    --chance[num-1];
                    if(chance[num-1] == 0)
                        break;
                }
            }
            if(chance[num-1] == 0)
                break;
        }
        
        num--;
        
    
    }
    

}




int main(int argc, const char * argv[]) {
    
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            int temp = 0;
            scanf("%d",&temp);
            map[i][j] = temp;
            if(temp == 1)
                total++;//색종이 수
        }
    }
    
    dfs(0, 0, 5);
    if(Answer == 100)
        Answer = -1;
    printf("%d",Answer);
    
    
    return 0;
}


//1이 적힌 칸에 대해서만 색종이를 덮을지 여부 판별.
