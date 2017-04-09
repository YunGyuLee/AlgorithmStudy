<각 문제별 접근 방법>

문제 3.1)
 하나의 배열로 세개의 stack을 구현하는 문제이다. 여러가지 방법이 있겠지만 3개의 stack을 0,1,2라고 보았을 때 전체 배열에서 각 stack의 Top을 가리키는 pointer를 3개를 만든다. 그리고 전체 배열을 3등분 하여 각 조각을 하나의 stack으로 생각한다. 그 후 각 stack의 push와 pop을 진행한다.(각 stack의 Top들을 이동시켜줌)


문제 3.2)
 각 노드마다 data 값 이외에 현재까지의 minvalue를 저장하는 값을 추가한다. 이를 통해 push할때 넣으려고 하는 data와 Top의 minValue를 비교하여 더 작은값을 새로운 node에 넣는다.이렇게 구현하면 top에 가장 작은 원소가 있는 상태에서 pop 을 해도 어차피 Top에 있는 minvalue값을 읽어오면 전체 stack의 minvalue를 알 수 있기 때문에 findmin을 하는데 O(1) 시간이 걸린다.

문제 3.3)
 이건 디자인의 문제. threshold를 넘을때 마다 동적 배열에 추가로 topstack 포인터를 넣는다. 그리고 popAt() 연산시 해당 스택이 비어버리면 동적 배열에서도 해당 stack 포인터를 삭제. 전체 stack의 pop진행은 동적배열의 맨 뒷부분 부터 뽑으면 된다!

문제 3.4)
 
문제 3.5)
 두개의 stack을 가지고 queue를 구현하는 문제. enqueue 연산은 1번 stack에 넣는 것으로 한다. dequeue 연산은 1번 stack에 있는 data들을 2번 stack으로 옮기고 pop을 한다. 그후 다시 1번 stack으로 옮긴다. 이렇게 구현하면 enqueue는 O(1) ,dequeue는 O(n)이 걸리게 된다.

문제 3.6)
 두개의 stack을 가지고 정렬 알고리즘을 구현. 오름차순으로 정렬한다고 하자.  하나의 stack에서 정렬된 stack으로 옮길때 정렬된 stack에서 top의 값과 정렬할 stack의 top의 값을 비교한다. 두 값을 비교하여 정렬할 stack의 값이 더 크면 pop하여 정렬된 stack에 쌓는다. 정렬할 stack의 값이 더 작으면 그 값을 pop해 놓고 해당 값보다 작은 값이 나올때 까지 정렬된 stack의 data를 뽑아 정렬할 stack에 쌓는다. 해당 값보다 작은 값이 나왔을 때 그위에 처음에 뽑은 값을 올리고 위의 과정을 다시 반복한다. 정렬할 stack이 empty가 되면 정렬된 stack을 정렬된 stack으로 push한 후 결과를 반환한다. 

 
