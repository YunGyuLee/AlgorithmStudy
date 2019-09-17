/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;
// float b = 1.0, c = 2.0;
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////


//이문제는 STL queue를 사용하면 시간초과가 뜰 확률이 높다. 기본적으로 queue에 담기는 내용물의 수가 많기때문이다.
//배열로 queue를 구현하였더니 통과하였다.!!
//크기가 큰 문제를 풀때는 배열로 직접 큐를 구현하자!


#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
using namespace std;
const int MAX_X = 4005;
const int MAX_A = 1001;
//int map[MAX_X][MAX_X];
int visited[MAX_X][MAX_X];
int n;
struct info{
    int y;
    int x;
    int d;
    int K;
    
};

int dir_y[4] = {1,-1,0,0};
int dir_x[4] = {0,0,-1,1};
int Answer = 0;

info q[MAX_A];
int head;
int rear;
int q_size;
bool empty(){
    if(head == rear)
        return true;
    else
        return false;
}

bool full(){
    if((rear+1)%MAX_A == head)
        return true;
    else
        return false;
}

bool push(info a){
    if(full())
        return false;
    else{
        q[rear] = a;
        q_size++;
        rear = (rear+1)%MAX_A;
        return true;
    }
}

info front(){
    info a = {0,0,0,0};
    if(empty())
        return a;
    else{
        a = q[head];
        return a;
    }
        

}


bool pop(){
    if(empty())
        return false;
    else{
        head = (head+1)%MAX_A;
        q_size--;
        return true;
    }
}

void go(){
    
    while(!empty()){
        
        
        //    vector<pair<int,int>> clean;
        int size = q_size;
        for(int i=0;i<size;i++){
            info now = front();
            pop();
            int next_y = now.y + dir_y[now.d];
            int next_x = now.x + dir_x[now.d];
            
            if(next_y<0 || next_y > MAX_X-1 || next_x<0 || next_x>MAX_X-1)
                continue;
            
            //   cout<<next_y<<" "<<next_x<<endl;
            if(visited[next_y][next_x] == 0){
                visited[next_y][next_x] = now.K;
                push(info{next_y,next_x,now.d,now.K});
            }else{
                visited[next_y][next_x] += now.K;
            }
            
            
            
            
            
            
        }
        size = q_size;
        for(int i=0;i<size;i++){
            info now = front();
            pop();
            if(visited[now.y][now.x] == now.K){//충돌하지 않았음.
                push(info{now.y,now.x,now.d,now.K});
                visited[now.y][now.x] = 0;
            }else{
                Answer += visited[now.y][now.x];
                visited[now.y][now.x] = 0;
            }
            
            
        }
        
        
        
        
        
    }
    
    
}


int main(int argc, const char * argv[]) {
    int T = 0;
    scanf("%d",&T);
    for(int testcase = 1;testcase<=T;testcase++){
        scanf("%d",&n);
        Answer = 0;
        for(int i=0;i<n;i++){
            int x,y,d,K;
            scanf("%d %d %d %d",&x,&y,&d,&K);
            y = 2*(y+1000);
            x = 2*(x+1000);
            push(info{y,x,d,K});
            //    map[y][x] = K;
            
        }
        
        go();
        printf("#%d %d\n",testcase,Answer);
        
        
        
    }
    
    
    return 0;
}
