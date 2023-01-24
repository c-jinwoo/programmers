#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* A, const char* B) {
    int answer = -1;
    int len = strlen(A);
    char* cpy;              // A를 민 결과를 복사할 배열
    
    for(int i = 0;i < len;i++){
        cpy = (char*)malloc(len + 1);
        cpy[len] = '\0';
        
        // A 밀어서 복사
        for(int j = 0;j < len;j++){
            cpy[(i + j) % len] = A[j];
        }
        
        // 같으면 answer에 민 횟수 저장
        if(!strcmp(cpy, B)){
            answer = i;
            break;
        }
        
        free(cpy);
        cpy = NULL;
    }
    
    return answer;
}