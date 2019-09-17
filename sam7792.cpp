//
//  main.cpp
//  sam7792
//
//  Created by new_mac on 2019. 8. 5..
//  Copyright © 2019년 new_mac. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int n;


int cnt_differ(string s){
    set<char> cnt;
    for(int i=0;i<s.size();i++){
        if(s[i]==' ')
            continue;
        cnt.insert(s[i]);
    }
    int result  = cnt.size();
    cnt.clear();
    return result;
}


bool comp(string a, string b){
    if(cnt_differ(a) > cnt_differ(b))
        return true;
    else if(cnt_differ(a) == cnt_differ(b)){
        return a<b;
    }else
        return false;

}


int main(int argc, const char * argv[]) {
    int T= 0;
    scanf("%d",&T);
    for(int testcase = 1;testcase<=T;testcase++){
        scanf("%d",&n);
        vector<string> name;
        for(int i=0;i<n+1;i++){
            char temp[20];
            cin.getline(temp,20,'\n');
          //  getline(cin,temp);
            if(i!=0)
                name.push_back(temp);
        }
        sort(name.begin(), name.end(), comp);
        cout<<"#"<<testcase<<" "<<name[0]<<endl;
        name.clear();
        
    }
    
    
    
    return 0;
}
