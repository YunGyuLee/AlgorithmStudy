//
//  main.cpp
//  sam2382
//
//  Created by new_mac on 2019. 8. 6..
//  Copyright © 2019년 new_mac. All rights reserved.
//

//48분만에 풀이완료.

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAX_N = 102;
int n,m,k;
int dir_y[4] = {-1,1,0,0};//상,하,좌,우
int dir_x[4] = {0,0,-1,1};

struct info{
    int num;
    int dir;
    int max_n;
};

info map[MAX_N][MAX_N];


void print_m(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",map[i][j].num);
        }
        printf("\n");
    }
    printf("\n");

}

int re_d(int dir){
    if(dir == 0)
        return 1;
    else if(dir == 1)
        return 0;
    else if(dir == 2)
        return 3;
    else if(dir == 3)
        return 2;
    else
        return -1;
}

void move(){
    
    info temp[MAX_N][MAX_N] = {0,};
    memset(temp, 0, sizeof(temp));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j].num != 0){
                int next_d = map[i][j].dir-1;
                int next_y = i + dir_y[next_d];
                int next_x = j + dir_x[next_d];
                if(next_y==0||next_y==n-1||next_x==0||next_x==n-1){//약품구역
                    temp[next_y][next_x].num = map[i][j].num/2;
                  //  cout<<temp[next_y][next_x].num<<endl;
                    temp[next_y][next_x].dir = re_d(next_d) + 1;
                  //  cout<<temp[next_y][next_x].dir<<endl;
                    continue;
                }
                if(temp[next_y][next_x].num !=0){
                    temp[next_y][next_x].num += map[i][j].num;
                    if(temp[next_y][next_x].max_n < map[i][j].num){
                        temp[next_y][next_x].max_n = map[i][j].num;
                        temp[next_y][next_x].dir = map[i][j].dir;
                    }
                }else{
                    temp[next_y][next_x].num += map[i][j].num;
                    temp[next_y][next_x].max_n = map[i][j].num;
                    temp[next_y][next_x].dir = map[i][j].dir;
                }
                
                
            }
        }
    }
    
    memcpy(map, temp, sizeof(map));
    


}

int simul(){
    int result = 0;
    print_m();
    for(int i=0;i<m;i++){
        move();
    }
    
    
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j].num !=0)
                result += map[i][j].num;
        }
    }
    
    return result;
}



int main(int argc, const char * argv[]) {
    int T = 0;
    scanf("%d",&T);
    for(int testcase = 1 ;testcase<=T;testcase++){
        scanf("%d %d %d",&n,&m,&k);
        memset(map,0,sizeof(map));
        for(int i=0;i<k;i++){
            int x,y,num,dir;
            scanf("%d %d %d %d",&y,&x,&num,&dir);
            map[y][x].num = num;
            map[y][x].dir = dir;
            map[y][x].max_n = num;
            //이동방향 - 1
            
            
            
        }
        
        printf("#%d %d\n",testcase,simul());
    
    }
    return 0;
}
