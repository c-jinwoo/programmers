#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// array_len은 배열 array의 길이입니다.
int solution(int array[], size_t array_len) {
    int answer = 0;
    
    for(int i = 0;i < array_len - 1;i++){
        int min = i;
        
        for(int j = i + 1;j < array_len;j++){
            if(array[min] > array[j]){
                min = j;
            }
        }
        
        if(min != i){
            int temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }
    
    answer = array[array_len / 2];
    
    return answer;
}