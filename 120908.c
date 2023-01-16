#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* str1, const char* str2) {
    int answer = 2;
    int str1_len = strlen(str1);
    int str2_len = strlen(str2);
    
    for(int i = 0;i < str1_len - str2_len + 1;i++){
        char* cpy = (char*)malloc(str2_len);
        
        for(int j = 0;j < str2_len;j++){
            cpy[j] = str1[i + j];
        }
        
        cpy[str2_len] = '\0';
        
        if(!strcmp(cpy, str2)){
            answer = 1;
            break;
        }
        
        free(cpy);
    }
        
    return answer;
}