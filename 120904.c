#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num, int k) {
    int answer = -1;
    int powers = 1;
    int result = 0;
    int digit = 1;
    
    while(num / powers >= 10){
        powers *= 10;
        digit++;
    }
    
    int* answer_arr = (int*)malloc(digit * sizeof(int));
    
    for(int i = 0;i < digit;i++){
        answer_arr[i] = num / powers;
        num -= answer_arr[i] * powers;
        powers /= 10;
        
        if(answer_arr[i] == k){
            answer = i + 1;
            break;
        }
    }
    
    free(answer_arr);
    
    return answer;
}