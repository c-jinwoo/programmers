#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
bool solution(const char* s) {
    bool answer = true;
    int len = 0;
    
    // 문자열 길이 체크
    while(s[len] != '\0'){
        len++;
    }
    
    if(len != 4 && len != 6){
        answer = false;
    }
    
    // 숫자로만 구성되어있는지 확인
    for(int i = 0;i < len;i++){
        if(s[i] < 48 || s[i] > 57){
            answer = false;
        }
    }
    
    return answer;
}