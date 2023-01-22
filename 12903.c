#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = (strlen(s) % 2) ? 1 : 2;      // s 길이가 홀수면 1개, 짝수면 2개 삽입
    char* answer = (char*)malloc(len + 1);
    answer[len] = '\0';
    
    if(strlen(s) % 2){                      // s 길이가 홀수일 경우
        int mid = strlen(s) / 2;        
        answer[0] = s[mid];
    }    
    else{                                   // s 길이가 짝수일 경우
        int mid = strlen(s) / 2 - 1;
        answer[0] = s[mid];
        answer[1] = s[mid + 1];
    }
    
    return answer;
}