//
//  main.cpp
//  binary_tree
//
//  Created by new_mac on 2019. 6. 24..
//  Copyright © 2019년 new_mac. All rights reserved.
//

#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct node* treePointer;

typedef struct node{
    int data;
    treePointer left,right;

}node;


void preorder(treePointer ptr){
    if(ptr){
        cout << ptr->data <<endl;
        preorder(ptr->left);
        preorder(ptr->right);
    }
}




int main(int argc, const char * argv[]) {
    
    
    
    
    return 0;
}
