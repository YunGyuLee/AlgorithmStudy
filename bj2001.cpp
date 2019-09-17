//
//  main.cpp
//  bj2001
//
//  Created by new_mac on 2019. 8. 8..
//  Copyright © 2019년 new_mac. All rights reserved.
//
//흠... 풀릴듯하면서 안풀린다...
//우선 실패...
#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;
const int MAX_N = 101;
int n,m,k;
int br[MAX_N][MAX_N];
int visited[MAX_N][15];//섬에 방문할때 가진 보석의 개수
struct info{
    int trea;
    int cn_cnt;
    int connect[MAX_N];
};
info map[MAX_N];
int limit=  -1;
int answer = -1;
stack<int> s;
void dfs(int cnt,int depth,int num){
//    s.push(num);
    
    if(depth != 0 && num == 1){
         // cout<<"보석: "<<cnt<<endl;
        if(cnt>answer)
            answer = cnt;
        return;
    }
    
    if(limit < cnt)
        return;

    
    if(map[num].cn_cnt != 0){
        for(int i=0;i<map[num].cn_cnt;i++){
            int next =  map[num].connect[i];
            if(cnt>br[num][next])
                continue;
            if(map[next].trea == 1){//다음 섬에 보석이 있는 경우
                for(int i=0;i<2;i++){
                    if(i==0){//보석을 선택안하는경우
                        if(visited[next][cnt]==1)
                            continue;
                        visited[next][cnt] = 1;
                        dfs(cnt, depth+1, next);
                        visited[next][cnt] = 0;
                    }else{//보석을 선택하는 경우
                        if(visited[next][cnt+1] == 1)
                            continue;
                        
                     //   cout<<"선택: "<<next<<endl;
                     //   cout<<"현재: "<<cnt<<" 다음: "<<cnt+1<<endl;
                        visited[next][cnt+1] = 1;
                        map[next].trea = 0;
                        dfs(cnt+1, depth+1, next);
                        visited[next][cnt+1] = 0;
                        map[next].trea = 1;
                    }
                }
                
                
            }else{
                if(visited[next][cnt]==1)
                    continue;
                visited[next][cnt] = 1;
                dfs(cnt, depth+1, next);
                visited[next][cnt] = 0;
            
            }
            
            
        
            
            
            
            
        }
        
        
        
        
        
    }else{
        if(map[num].trea==1)
            answer = 1;
        else
            answer = 0;
        return;
    }
    
    

}

void simul(){
    
      //  visited[1][0] = 1;
        dfs(0, 0, 1);
     //   visited[1][0] = 0;
    

}


int main(int argc, const char * argv[]) {
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<k;i++){
        int temp = 0;
        scanf("%d",&temp);
        map[temp].trea = 1;
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        if(a==1 || b==1){
            if(limit < c)
                limit = c;
        }
        int index = map[a].cn_cnt;
        map[a].connect[index] = b;
        map[a].cn_cnt++;
        index = map[b].cn_cnt;
        map[b].connect[index] = a;
        map[b].cn_cnt++;
        br[a][b] = c;
        br[b][a] = c;
    }
   // cout<<limit<<endl;
    simul();
    cout<<answer<<endl;
    
    
    return 0;
}
