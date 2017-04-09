#include <stdio.h>
#include <iostream>
#include <vector>
class SetOfStack {

  private : 
      class Node {      
        int data;
        Node * prevNode;
      };

      vector<Node *> TopList; 
      Node * entireTop;
  public :
      SetOfStack();
      void push(int data);
      int pop();
      int popAt(int index);

};
