#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// food_len은 배열 food의 길이입니다.
char* solution(int food[], size_t food_len) {
    // 음식 + 물 양
    int len = 0;    
    for(int i = 1;i < food_len;i++){
        len += food[i] / 2;        
    }
    
    // 문자열 동적할당   
    int idx = 0;
    char* answer = (char*)malloc(len * 2 + 2);
    answer[len * 2 + 1] = '\0';
    answer[(len * 2 + 1) / 2] = '0';
    
    // 값 대입
    for(int i = 1;i < food_len;i++){
        for(int j = 0;j < food[i] / 2;j++){
            answer[idx++] = i + 48;
        }
    }
    
    // 대칭
    for(int i = 0;i < len;i++){
        answer[len * 2 - i] = answer[i];
    }
    
    return answer;
}