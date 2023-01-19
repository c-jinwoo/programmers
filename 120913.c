#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* my_str, int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = strlen(my_str);               // 전체 문자열 길이
    int result_cnt = len / n + 1;           // 서브 문자열 갯수
    
    char** answer = (char**)malloc(result_cnt * sizeof(char*));

    // 서브 문자열 동적할당 및 널문자
    for(int i = 0;i < result_cnt - 1;i++){
        answer[i] = (char*)malloc(n + 1);
        answer[i][n] = '\0';
    }
    answer[result_cnt - 1] = (char*)malloc(len % n + 1);
    answer[result_cnt - 1][len % n] = '\0';
    
    // 서브 문자열 길이만큼 복사
    for(int i = 0;i < result_cnt;i++){
        int sub_len = (i < result_cnt - 1) ? n : len % n;
        
        for(int j = 0;j < sub_len;j++){
            answer[i][j] = my_str[i * n + j];
        }
    }    
    
    return answer;
}