//
//  main.cpp
//  sam5650
//
//  Created by new_mac on 2019. 8. 1..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//1시간 21분만에 풀이완료.
//시간을 잡아먹었던 부분
//1. 블록하나의 진행방향을 잘못 입력했음.
//2. 벽을 만날때에 이동방향만 바꿔주고 진행한 좌표는 그대로 두었어야 했는데 이전좌표로 조정해서 오류가남.

#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int n;
const int MAX_N = 102;
int map[MAX_N][MAX_N];
int dir_y[4] = {0,0,1,-1};
int dir_x[4] = {1,-1,0,0};

struct cord{
    int y1;
    int x1;
    int y2;
    int x2;
};

struct cor{
    int y;
    int x;
};

cord worm[5];


cor finf_hall(int w,int y,int x){
    int index = w - 6;
    if(worm[index].y1 == y && worm[index].x1 == x){
        return cor{worm[index].y2,worm[index].x2};
    }else{
        return cor{worm[index].y1,worm[index].x1};
    }
    
}

int re_d(int d){
    if(d == 0){
        return 1;
    }else if(d == 1){
        return 0;
    }else if(d == 2){
        return 3;
    }else if(d == 3)
        return 2;
    
    return -1;
}

int go(int y,int x,int d){
 //   cout<<"시작 "<<y<<" "<<x<<endl;
 //   cout<<"방향 "<<d<<endl;
    int result = 0;
    int now_y = y;
    int now_x = x;
    int now_d = d;
    
    while(1){
        now_y = now_y + dir_y[now_d];
        now_x = now_x + dir_x[now_d];
    //    cout<<now_y<<" "<<now_x<<endl;
        if(now_y<0||now_y>n-1||now_x<0||now_x>n-1||map[now_y][now_x] == 5){
         //   cout<<"벽"<<endl;
            result++;
         //   now_y = t_y;
         //   now_x = t_x;
            now_d = re_d(now_d);

        }else if(map[now_y][now_x] == 1){
            result++;
            if(now_d == 1){
                now_d = 3;
            }else if(now_d == 2){
                now_d = 0;
            }else{
           //     now_y = t_y;
           //     now_x = t_x;
                now_d = re_d(now_d);
            }
        }else if(map[now_y][now_x] == 2){
            result++;
            if(now_d == 1){
                now_d = 2;
            }else if(now_d == 3){
                now_d = 0;
            }else{
          //      now_y = t_y;
          //      now_x = t_x;
                now_d = re_d(now_d);
            }
            
            
        }else if(map[now_y][now_x] == 3){
            result++;
            if(now_d == 0)
                now_d = 2;
            else if(now_d == 3)
                now_d = 1;
            else{
         //       now_y = t_y;
         //       now_x = t_x;
                now_d = re_d(now_d);
            }
        }else if(map[now_y][now_x] == 4){
            result++;
            if(now_d == 2)
                now_d = 1;
            else if(now_d == 0)
                now_d = 3;
            else{
         //       now_y = t_y;
         //       now_x = t_x;
                now_d = re_d(now_d);
            }
        }else if(map[now_y][now_x] >=6 && map[now_y][now_x] <= 10){
      //      cout<<"웜홀"<<endl;
       //     cout<<now_d<<endl;
            cor next = finf_hall(map[now_y][now_x], now_y, now_x);
            now_y = next.y;
            now_x = next.x;
    //        cout<<now_y<<" "<<now_x<<endl;
    //        cout<<now_d<<endl;
        }
        
        if(map[now_y][now_x] == -1 || (now_y == y && now_x == x)){
      //      cout<<"탈출"<<endl;
            break;
        }
        
        
        
        
        
    }
    
    return result;
    
}

int simul(){
    int result = -1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j] ==0){
                int temp = 0;
                for(int k=0;k<4;k++){
                   temp = go(i, j, k);
                 //   cout<<temp<<endl;
                    if(temp > result)
                        result = temp;
                }
            }
        }
    }
    
    return result;
}



int main(int argc, const char * argv[]) {
    int T = 0;
    scanf("%d",&T);
    for(int testcase = 1;testcase<=T;testcase++){
        scanf("%d",&n);
        memset(worm,-1,sizeof(worm));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int temp = 0;
                scanf("%d",&temp);
                map[i][j] = temp;
                if(temp>=6 && temp <=10){
                    int index = temp-6;
                    if(worm[index].y1 == -1){
                        worm[index].y1 = i;
                        worm[index].x1 = j;
                    }else{
                        worm[index].y2 = i;
                        worm[index].x2 = j;
                    }
                    
                }
                
            }
        }
       
       
        printf("#%d %d\n",testcase,simul());
        
        
        
    }
    
    
    
    return 0;
}
