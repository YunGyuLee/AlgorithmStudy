#include <iostream>
using namespace std;

//method that decide if str2 is substring of str1
bool isSubstring(string str1,string str2){

    bool result =false;

    if(str1.length() < str2.length()){
        string temp;
        temp = str1;
        str1 = str2;
        str2 = temp;

    }

    for(int i=0;i<str1.length();i++){
        string temp;
        temp.append(str1,i,str2.length());
        if(!temp.compare(str2)) {
            result = true;
            break;
        }
    }

    return  result;




}


// 같이 생각해볼것
bool isRotation(string str1,string str2){

    bool result =false;
    string temp ;



    if(str1.length() != str2.length())
        return result;

    temp = str1 + str1;

    if(isSubstring(temp,str2)){

        result = true;

    }


    return result;


}


int main() {

    bool result;
    result = isRotation("waterbottle","terbottlewa");
    cout<< "waterbottle and terbottlewa"<<endl;
    if(result){

        cout<<"two words are rotation."<<endl;

    }else{

        cout<<"Not rotation"<<endl;
    }

    return 0;

}
