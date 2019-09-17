//
//  main.cpp
//  bj5373
//
//  Created by new_mac on 2019. 8. 5..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//다른 획기적인 풀이법이 떠오르지가 않는다... 하드코딩이 답인것인가...
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
int n;

char Up[3][3];
char Down[3][3];
char Front[3][3];
char Back[3][3];
char Left[3][3];
char Right[3][3];

void init_c(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            Up[i][j] = 'w';
            Down[i][j] = 'y';
            Front[i][j] = 'r';
            Back[i][j] = 'o';
            Left[i][j] = 'g';
            Right[i][j] = 'b';
        }
    }

}

void turn(int num,int dir){
    


}



int main(int argc, const char * argv[]) {
    int T = 0;
    scanf("%d",&T);
    for(int testcase = 1 ; testcase<=T;testcase++){
        scanf("%d",&n);
        init_c();
        
        for(int i=0;i<n;i++){
            string temp;
            cin>>temp;
            //여기에 회전함수
            
        }
        
        
    }
    
    return 0;
}
