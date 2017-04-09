#include "stackMin.h"
#include <iostream>
using namespace std;

int main(){

 Stack temp; 

 temp.push(4);
 temp.push(5);
 temp.push(6);
 temp.push(10);
 temp.push(1);
 cout<<"Current Min value: " <<temp.findMin()<<endl;
 
 temp.pop();
 cout<<"Current Min value: "<<temp.findMin()<<endl;

 cout<<temp.pop()<<endl;
 cout<<temp.pop()<<endl;
 cout<<temp.pop()<<endl;
 cout<<temp.pop()<<endl;





}
