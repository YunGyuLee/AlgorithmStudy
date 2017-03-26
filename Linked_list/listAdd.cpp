#include <list>
#include <stdio.h>
#include <iostream>

using namespace std;


void printList(list<int> input){
	list<int>::iterator it;
	it = input.begin();
	for(it;it!=input.end();it++){
		
		printf("%d ",*it);
	
	}
	printf("\n");
	return;

}


list<int> addList(list<int> list1, list<int> list2){
	
	list<int> result;
	if(list1.size() != list2.size()){
	printf("The length of Lists are different!!");
	return result;
	}

	list<int>::iterator list1_it;
	list1_it = list1.begin();
	list<int>::iterator list2_it;
	list2_it = list2.begin();
	
	int carry =0;

	while(list1_it != list1.end() && list2_it != list2.end()){
		int temp =*list1_it + *list2_it + carry;
		int digit = temp%10;
		carry = temp/10;
		
		result.push_back(digit);
		list1_it++;
		list2_it++;
	
	}

	if(carry !=0){
	
	result.push_back(carry);
	}


	return result;

}




int main(){

	list<int> list1;
	list<int> list2;

	list1.push_back(2); list1.push_back(9); list1.push_back(9);
	printList(list1);
	
	list2.push_back(4); list2.push_back(8); list2.push_back(4);
	printList(list2);

	printList(addList(list1,list2));

	return 0;





}
