//
//  main.cpp
//  serial_code
//
//  Created by new_mac on 2019. 6. 20..
//  Copyright © 2019년 new_mac. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(string a,string b){
    if(a.size() == b.size()){
        int a_sum = 0;
        int b_sum = 0;
        for(int i=0;i<a.size();i++){
            if(a[i] >= '0' && a[i] <= '9')
                a_sum = a_sum + a[i]-48;
            if(b[i] >= '0' && b[i] <= '9')
                b_sum = b_sum + b[i]-48;
        }
        if(a_sum < b_sum)
            return true;
        else if(a_sum > b_sum)
            return false;
        else
            return a < b;
    }else
        return a.size() < b.size();
    
}

int main(int argc, const char * argv[]) {

    int n=0;
    scanf("%d",&n);
    vector<string> data;
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        data.push_back(temp);
    }
    
    sort(data.begin(),data.end(),comp);
    for(int i=0;i<n;i++){
        cout<<data[i]<<'\n';
    }
    
    return 0;
}
