#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n) {
    int size = n / 2;
    
    if(n % 2){
        size++;
    }    
    
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(size * sizeof(int));
    
    for(int i = 0;i < size;i++){
        answer[i] = i * 2 + 1;
    }
    
    return answer;
}