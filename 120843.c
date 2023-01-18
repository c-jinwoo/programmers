#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int solution(int numbers[], size_t numbers_len, int k) {
    int answer = 0;
    int cnt = 1;
    int next = 1;
    
    while(cnt != k){
        next = (next + 2) % numbers_len;
        cnt++;
    }
    
    answer = next;
    
    return answer;
}