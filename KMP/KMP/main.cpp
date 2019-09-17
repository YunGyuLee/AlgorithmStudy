//
//  main.cpp
//  KMP
//
//  Created by new_mac on 2019. 7. 12..
//  Copyright © 2019년 new_mac. All rights reserved.
//

//공백이 포함된 문자열을 자르지 않고 입력받고 싶을때!! --> getline(cin,변수) 이런식으로 입력을 받으면 된다.


#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;


vector<int> make_table(string pattern){
    int pattern_size = pattern.size();
    int j=0;
    vector<int> table(pattern_size,0);
    
    for(int i=1;i<pattern_size;i++){
        while(j>0 && pattern[i] != pattern[j]){
            j = table[j-1];
        }
        if(pattern[i] == pattern[j]){
            table[i] = ++j;
        }
    }
    
    return table;

}

void KMP(string input,string pattern){
    int pattern_size = pattern.size();
    int input_size = input.size();
    int j=0;
    vector<int> result;
    vector<int> table = make_table(pattern);
    for(int i=0;i<input_size;i++){
        while(j>0 && input[i] != pattern[j]){
            j = table[j-1];
        }
        if(input[i] == pattern[j]){
            if(j == pattern_size-1){
                result.push_back(i-pattern_size+2);
                j = table[j];
            }else{
                j++;
            }
        }
        
    }
    
    cout<<result.size()<<endl;
    for(int i=0;i<result.size();i++){
        printf("%d\n",result[i]);
    }
    
    
    
    
}


int main(int argc, const char * argv[]) {
    string input;
    string pattern;
    getline(cin,input);
    getline(cin,pattern);
    
    KMP(input,pattern);
    
    
    return 0;
}
