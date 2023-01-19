#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(long long n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    int n_cpy = n;
    int digit = 1;
    
    // 자리수 계산
    while(n_cpy){
        n_cpy /= 10;
        digit += 1;
    }
    
    int* answer = (int*)malloc(digit * sizeof(int));
    
    for(int i = 0;i < digit;i++){
        answer[i] = n % 10;
        n /= 10;
    }
    
    return answer;
}