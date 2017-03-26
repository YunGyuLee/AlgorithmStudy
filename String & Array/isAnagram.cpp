
#include <iostream>
#include <unordered_set>
using namespace std;


//method that decide if two string are anagram or not
bool isAnagram(string str1, string str2){
    bool result = false;
    unordered_set<char> buffer;

    if(str1.length() != str2.length())
        return  result;


    transform(str1.begin(),str1.end(),str1.begin(),::toupper);
    transform(str2.begin(),str2.end(),str2.begin(),::toupper);

    for(int i=0;i<str1.length();i++)
        buffer.insert(str1[i]);

    for(int i=0;i<str2.length();i++){


        if(buffer.find(str2[i])==buffer.end())
            return result;


    }

    result = true;

    return  result;


}

int main() {

    string str1 = "usage";
    string str2 = "asgue";
    
    cout<< "Is "+str1+" and "+str2+" are anagram?"<<endl;
    
    if(isAnagram(str1,str2)){
        
        cout<<"YES!!"<<endl;
        
    }else{
        
        cout<<"NO..."<<endl;
        
    }
    return 0;

}
