//
//  main.cpp
//  string_sort
//
//  Created by new_mac on 2019. 6. 20..
//  Copyright © 2019년 new_mac. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(string a,string b){
    
    
    if(a.size() < b.size()){
        return true;
    }else if(a.size() > b.size()){
        return false;
    }else{
        return a < b;
    }
    
}

int main(int argc, const char * argv[]) {
    
    int n;
    
    
    cin>>n;
    vector<string> data(n);
    for(int i=0;i<n;i++){
        cin>>data[i];
    }
    
    sort(data.begin(),data.end(),comp);
    
    int size = data.size();
    
    string tmp_word;
    for(int i=0;i<size;i++){
        if (tmp_word == data[i])
            continue;
        cout << data[i] << "\n";
        // 비교하기 위해 변수에 저장
        tmp_word = data[i];
    }
    
    
    
    
    return 0;
}
