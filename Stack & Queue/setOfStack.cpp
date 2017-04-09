#include "setOfStack.h"
#include <iostream>

SetOfStack::SetOfStack() {
  this->entireTop = NULL;
}

SetOfStack::push(int data) {
  if(this->entireTop == NULL) {
    this->entireTop = new Node();
    this->entireTop -> data = data;
  } else if() { 
    Node*temp = new Node();
    temp->data = data;
    temp->prevNode = this->entireTop;
    this->entireTop = temp;    
  } 





}
