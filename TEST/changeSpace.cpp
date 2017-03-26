#include <iostream>

using namespace std;
//function that replace space(" ") in string into "%20"

string changeSpace(string inputString){

    const char * token  = strtok(&inputString[0]," ");

    string result = token;

    while((token = strtok(NULL," ")) != NULL)
        result = result + "%20" + token;

    return  result;

}


int main() {

    string temp = "my father is good father." ;
    cout<<temp<<endl;
    cout<<changeSpace(temp)<<endl;
    return 0;

}
