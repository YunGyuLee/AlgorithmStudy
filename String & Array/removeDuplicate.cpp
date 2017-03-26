#include <iostream>

using namespace std;

//time complexity O(N^2) , extra buffer X
//using inner buffer of str
//    |
// abcdc
//   | (tail) --> cursor of array which contain non duplicate char
void removeDuplicateVer1(char str[]){
	
	int tail = 1;
	for(int i=1; i<strlen(str);i++){

		int j=0;
		for(j=0;j<tail;j++){
		if(str[i]==str[j]){
		break;

		}
		}	
		if(tail==j){
		str[tail] = str[i];
		++tail;

		}	
	
}

	str[tail] = '\0';



}

//time complexity O(N) , extra buffer X;
//using bitwise operation
void removeDuplicateVer2(char str[]){
	
	int sum = 1<<(str[0]-'a');
	for(int i=1;i<strlen(str);i++){
	int shiftedChar = 1<<(str[i]-'a');
		if(sum & shiftedChar){
		str[i] = '_';
		}else{
		
		sum += shiftedChar;

		}	
	
	
	}	
	
	int startOfEmpty = 0;
	while(1){
	
	if(str[startOfEmpty] == '_'){
	break; 
	}
	
	startOfEmpty++;
	
	}	

	for(int i=startOfEmpty;i<strlen(str);i++){

		if(str[i] !='_'){
			str[startOfEmpty] = str[i];
			startOfEmpty++;

		} 


	}	
	
	str[startOfEmpty]= '\0';

}

int main(){

 char temp[] = "aaabcded";
 cout<<temp<<endl;
 
 removeDuplicateVer1(temp);
 
 cout<<"ver1 result"<<endl; 
 cout<<temp<<endl;

 char temp2[] = "aaabcded";
 removeDuplicateVer2(temp2);
 cout<<"ver2 result"<<endl;
 cout<<temp2<<endl;
 return 0;


}
