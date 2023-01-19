#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(int num) {
    // 리턴할 값은 메모리를 동적 할당해주세요
    char* str_odd = "Odd";
    char* str_even = "Even";
    int len = (num % 2) ? 3 : 4;
    char* answer = (char*)malloc(len + 1);
    
    for(int i = 0;i < len;i++){
        answer[i] = (num % 2) ? str_odd[i] : str_even[i];
    }
    answer[len] = '\0';
    
    return answer;
}