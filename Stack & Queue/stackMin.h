#include <iostream>

using namespace std;

class Stack {

    private: 
        class Node{
            public: 
                int data;
                int currentMin;//각 노드마다 현재까지의 minvalue를 저장
                Node * prevNode;
        };

        
        Node * Top;

    public:
        Stack();

        void push(int data);
        int pop();
        int findMin();

}; 

