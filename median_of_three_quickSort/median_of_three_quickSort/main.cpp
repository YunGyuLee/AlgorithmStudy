//
//  main.cpp
//  median_of_three_quickSort
//
//  Created by new_mac on 2019. 8. 18..
//  Copyright © 2019년 new_mac. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;


void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

void three_sort(int array[],int start,int end){
    //시작,중간,끝 값들을 오름차순으로 정렬
    int mid = (start+end)/2;
    if(array[start] > array[mid]){
        swap(array[start],array[mid]);
    }
    if(array[mid] > array[end]){
        swap(array[mid],array[end]);
    }
    if(array[start] > array[mid]){
        swap(array[start],array[mid]);
    }
    
}


void quick_sort(int array[],int start,int end){
    int mid = (start+end)/2;
    three_sort(array, start, end);
    if(end-start+1>3){//정렬하려는 배열의 길이가 3보다 크면 재귀적으로 수행. 3보다 작거나 같으면 three_sort로 정렬끝.
        swap(array[mid], array[start+1]);
        int pivot = start+1;
        int i = start+2;
        int j = end-1;
        while(i<=j){
            while(i<=end-1 && array[i] < array[pivot]){
                i++;
            }
            while(j>start && array[j] > array[pivot]){
                j--;
            }
            if(i>j){
                swap(array[pivot],array[j]);
                pivot = j;
            }else{
                swap(array[i], array[j]);
            }
            
        }
        quick_sort(array, start, pivot-1);
        quick_sort(array, pivot+1, end);
        
        
        
        
    }

}





int main(int argc, const char * argv[]) {
    
    int A[10] = {0,1,50,2,40,20,10,25,60,70};
    quick_sort(A, 0, 9);
    int a = 10;
    int b = 20;
    swap(a, b);
    cout<<a<<" "<<b<<endl;
    for(int i =0;i<10;i++){
        printf("%d ",A[i]);
    }
    
    
    return 0;
}
