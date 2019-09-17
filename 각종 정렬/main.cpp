//
//  main.cpp
//  exercise
//
//  Created by new_mac on 2019. 6. 7..
//  Copyright © 2019년 new_mac. All rights reserved.
//

#include <iostream>

int sorted[100];



void print_arr(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void up_heapify(int array[],int size,int i){//힙의 구성방식이 상향식(아래에서 위로진행)
    int root = 0;
    root = (i-1)/2;
    if(root < 0)
        return;
    if(array[root] < array[i]){
        int temp = array[i];
        array[i] = array[root];
        array[root] = temp;
        up_heapify(array, size, root);
    }else
        return;
    
}

void down_heapify(int array[],int size,int i){//힙의 구성이 하향식 구현방식(위에서 아래로 진행)
    int c = 2*i + 1;
    if(c >= size)
        return;
    if(c + 1 < size && array[c] < array[c+1]){//하향식일때는 자식들중 큰 녀석과 비교하면 되므로
        c++;
    }
    if(array[i] < array[c]){
        int temp = array[i];
        array[i] = array[c];
        array[c] = temp;
        down_heapify(array,size,c);
    }else{
        return;
    }
   
    

}

//상향식,하향식 모두 0번째 원소를뒤로 보내고는 하향식 heapify!!!! --> 평균적인 시간복잡도 nlogn
void heap_Sort1(int array[],int size){
    for(int i=size/2 - 1;i>=0;i--){//처음에 힙 구성을 하향식으로
        down_heapify(array, size, i);
    }
    for(int i=1;i<=size;i++){
      //  print_arr(array, size);
        int temp = array[size-i];
        array[size- i] = array[0];
        array[0] = temp;
        //0번째 원소에 대해 하향식으로 heapify 진행
        down_heapify(array, size-i, 0);
        
        
    }
    
}

void heap_Sort2(int array[],int size){
    for(int i = 0;i<size;i++){//처음에 힙구성을 상향식으로
        up_heapify(array, size, i);
    }
    for(int i=1;i<size;i++){
     //   print_arr(array, size);
        int temp = array[size -i];
        array[size-i] = array[0];
        array[0] = temp;
        //0번째 원소에 대해 하향식으로 heapify 진행
        down_heapify(array, size-i, 0);
        
    }

}



//오름차순 퀵소트!
void quick_sort(int array[],int start,int end){//pivot의 위치를 정하는 방식의 분할정복을 이용한 정렬 기법
    
    if(start>=end)
        return;
    int pivot = array[start];//*****pivot의 위치를 어떻게 정하느냐에 따라 알고리즘의 성능이 달라진다!!! *****
    int i = start + 1;
    int j = end;
    while(i<=j){//pivot을 기준으로 왼쪽은 pivot보다 작은값으로 오른쪽은 pivot보다 큰값으로 양분하는 과정.
        
    
        while(i<=end && array[i] < pivot){//왼쪽부터 탐색을 시작하며 pivot보다 큰값을 만나면 멈춤.
            i++;
        }
        
        while(j>start && array[j] > pivot){//오른쪽부터 탐색을 시작하며 pivot보다 작은값을 만나면 멈춤.
            j--;
        }
            
        
        
        if(i>j){//두개의 커서가 교차하면 작은값과 pivot값을 교환해준다.
            int temp = array[start];
            array[start] = array[j];
            array[j] = temp;
        }else{//두개의 커서가 교차하지 않았으면 두 커서가 가리키는 값을 바꾸어준다.
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
        
        
    }
    
    quick_sort(array,start,j-1);//pivot은 j에 안착.
    quick_sort(array,j+1,end);
    return;

}

//내림 차순 정렬
void quick_sort2(int arr[],int start,int end){
    if(start>=end)
        return;
    int pivot = arr[start];
    int i = start + 1;
    int j = end;
    while(i<=j){
        while(i<=end && arr[i] > pivot){
            i++;
        }
        while(j>start && arr[j] < pivot){
            j--;
        }
        
        if(i>j){
            int temp = pivot;
            arr[start] = arr[j];
            arr[j] = temp;
        }else{
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        
    
    }
    quick_sort2(arr, start, j-1);
    quick_sort2(arr, j+1, end);
    return;
    
    
}



void selection_sort(int array[],int size){
    int min = INT_MAX;
    int index = 0;
    int temp = 0;
    for(int i=0;i<size;i++){
        min  = INT_MAX;
        for(int j=i;j<size;j++){
            if(array[j] < min){
                min = array[j];
                index = j;
            }
                
        }
        temp  = array[index];
        array[index] = array[i];
        array[i] = temp;
    }



}



void insert_sort(int array[],int size){
    
    for(int i=0;i<size;i++){//오른쪽에 있는 정렬되지 않은 수를 하나 선택한다. 그 후 그 수를 왼쪽에 정렬된 배열에 맞는 자리를 찾아준다.
        int j= i;
        while(j>0 && array[j-1] > array[j]){//왼쪽은 정렬이 되어있다고 가정한다.
            int temp = array[j];
            array[j] = array[j-1];
            array[j-1] = temp;
            j--;
        }
        
    }
    

}

void bubble_sort(int array[],int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size-1-i;j++){//for문을 한번 수행하고 나면 가장 큰값이 맨 뒤에 존재한다.
            if(array[j] > array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

}


void merge(int array[],int start,int middle,int end){
    int i= start;
    int j= middle + 1;
    int k = start;
    while(1){
        
        if(i>middle)
            break;
        if(j>end)
            break;
        
        if(array[i] < array[j]){
            sorted[k] = array[i];
            k++;
            i++;
        }else{
            sorted[k] = array[j];
            k++;
            j++;
        }
    
    }
    
    if(i>middle){
        for(int t=j;t<=end;t++){
            sorted[k] = array[t];
            k++;
        }
    }else if(j>end){
        for(int t=i;t<=middle;t++){
            sorted[k] = array[t];
            k++;
        }
    }
    
    for(int t=start;t<=end;t++){
        array[t] = sorted[t];
    }
    
}

void merge_Sort(int array[],int start,int end){
    if(start < end){
        int middle = (start + end)/2;//배열의 크기가 1개가 될때까지 계속 쪼갠다.
        merge_Sort(array, start, middle);
        merge_Sort(array, middle+1, end);
        merge(array, start, middle, end);//쪼개진 배열을 합치면서 정렬한다.
        
    }

}




int main(int argc, const char * argv[]) {
    int a[10] = {10,2,51,4,3,9,20,21,46,55};
  
    print_arr(a, 10);
    heap_Sort2(a, 10);
    print_arr(a, 10);
    return 0;
}
