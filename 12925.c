#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define NUMBER_OFFSET 48

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 0;
    int powers = 1;
    int len = strlen(s);
    
    for(int i = 0;i < len;i++){
        int idx = len - 1 - i;
        
        if(s[idx] != '+' && s[idx] != '-'){
            answer += ((s[idx] - NUMBER_OFFSET) * powers);
            powers *= 10;
        }
    }
    
    if(s[0] == '-'){
        answer *= -1;
    }
        
    return answer;
}