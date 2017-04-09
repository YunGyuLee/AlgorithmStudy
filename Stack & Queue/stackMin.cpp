#include "stackMin.h"
#include <math.h>
using namespace std;

Stack::Stack() {
  this->Top = NULL;
}

void Stack::push(int data) {

   if(this->Top == NULL) {
      this->Top = new Node();
      this->Top -> data = data;
      this->Top -> currentMin = data;;
      cout<<data<<endl;
  } else {
      Node * temp = new Node();
      temp->data = data;
      temp->currentMin = min(this->Top -> currentMin , data);
      temp->prevNode =this ->Top;
      this->Top = temp;
      cout<<data<<endl; 
  }

  return; 
}

int Stack::pop() {
  if(this->Top  == NULL) {
      printf("Stack is Empty!!");
      return -999;
  } else {
      int result;
      result = this->Top -> data;
      Node* temp = this->Top;
      this->Top = this->Top->prevNode;
      delete temp;;
     
      return result;
  }
}

int Stack::findMin() {
    
    if(this->Top == NULL) {
    
    printf("Stack is Empty");
    return -9999999;

    } else {
   
      
    return this->Top -> currentMin; 
    
    
    } 


}
