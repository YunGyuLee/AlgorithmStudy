#include <iostream>
#include <list>

using namespace std;






void removeDuplicateFromList(list<char> &input){

        list<char>::iterator it;
        it = input.begin();

        int sum = 1<<(*it - 'a');
        it++;

        while(it !=input.end()){

            int temp = 1<<(*it - 'a');

            if(sum & temp){


                    it = input.erase(it);



            }else{

                sum += temp;
                it++;

            }





        }




}


int main() {

    list<char> temp = {'d','c','a','b','b','a','c'};
    removeDuplicateFromList(temp);
    
    

    list<char>::iterator it = temp.begin();
    for(it;it!=temp.end();it++){
            cout<<*it<<endl;


    }

}
