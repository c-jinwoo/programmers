#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int gap(int array_val, int n){
    return (array_val - n >= 0) ? array_val - n : n - array_val;
}

// array_len은 배열 array의 길이입니다.
int solution(int array[], size_t array_len, int n) {
    int min = 0;
    
    if(array_len == 1){
        return array[min];
    }
        
    for(int i = 1;i < array_len;i++){
        if(gap(array[min], n) > gap(array[i], n)){
            min = i;
        }
        else if(gap(array[min], n) == gap(array[i], n)){
            min = (array[min] > array[i]) ? i : min;
        }
    }
    
    return array[min];
}