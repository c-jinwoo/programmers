#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    char* answer = (char*)malloc(n + 1);
    answer[n] = '\0';
    
    // 홀수면 박, 짝수면 수
    for(int i = 0;i < n;i++){
        answer[i] = (i % 2) ? '박' : '수';
    }
    
    return answer;
}