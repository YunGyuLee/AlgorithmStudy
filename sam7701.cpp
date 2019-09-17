#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int n;

bool comp(string a, string b){
    if(a.size() < b.size())
        return true;
    else if(a.size() == b.size()){
        if(a<b)
            return true;
        else
            return false;
        
    }else
        return false;
    
}
int main(int argc, const char * argv[]) {
    
    int T = 0;
    scanf("%d",&T);
    
    for(int testcase= 1 ;testcase<=T;testcase++){
        scanf("%d",&n);
        set<string> s;
        vector<string> result;
        for(int i=0;i<n;i++){
            string temp;
            cin>> temp;
            if(s.insert(temp).second){
                result.push_back(temp);
            }
            
        }
        sort(result.begin(), result.end(), comp);
        printf("#%d\n",testcase);
        for(int i=0;i<result.size();i++){
            cout<<result[i]<<'\n';
        }
        result.clear();
        s.clear();
    }
    
    
    
    return 0;
}
