#include <iostream>
#include <stack>
using namespace std;


void sortStack(stack<int> &input) {
    
    stack<int> temp;
    
    if(input.empty()) {
        printf("stack is empty!!");
    }
    
    //sort from input to temp stack
    //until input stack is empty
    while(!input.empty()) {
        
        //temp stack이 비어있거나 input의 top이 temp의 top보다 클 경우 input의 값을 temp로 옮긴다.
        if(temp.empty()||temp.top() < input.top()) {
            int topOfInput = input.top();
            input.pop();
            temp.push(topOfInput);
            
        }else { //그게 아니라면 input의 값을 빼놓고 temp의 값이 input의 값보다 작은 값이 나올때 까지 temp의 값을
            //뽑아서 input으로 옮긴다.
            int  popValue = input.top();
            input.pop();
            while(!temp.empty()) {//pop을 하게 될 경우 항상 stack이 비게 되는 경우를 생각하자 빈 상태에서 top을 보려고하면
                //오류가 발생한다.
                if(temp.top() > popValue) {
                    input.push(temp.top());
                    temp.pop();
                } else {
                    break;
                }
            }
            temp.push(popValue);
            
        }
        
        
    }
    
    
    
    while(!temp.empty()) {
        input.push(temp.top());
        temp.pop();
    }
    
    
    return;
    
}


int main() {
    
    
    
    stack<int> stack1;
    
    
    stack1.push(4);
    stack1.push(3);
    stack1.push(7);
    stack1.push(10);
    
    
    
    
    sortStack(stack1);
    
    while(!stack1.empty()) {
        cout<<stack1.top()<<endl;
        stack1.pop();
    }
    
    
    
    
    
}
