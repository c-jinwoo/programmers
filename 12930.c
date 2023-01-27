#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int sent_idx = 0;
    int word_idx = 0;
    int len = strlen(s);
    char* answer = (char*)malloc(len + 1);
    
    for(int i = 0;i < len;i++){
        if(s[i] == ' '){
            answer[sent_idx++] = ' ';
            word_idx = 0;
        }
        else{
            if(word_idx % 2){                       // 홀수일 경우 대문자면 소문자로
                answer[sent_idx] = (65 <= s[sent_idx] && s[sent_idx] <= 90) ? s[sent_idx] + 32 : s[sent_idx];
            }
            else{                                   // 짝수일 경우 소문자면 대문자로
                answer[sent_idx] = (97 <= s[sent_idx] && s[sent_idx] <= 122) ? s[sent_idx] - 32 : s[sent_idx];
            }
            sent_idx++;
            word_idx++;
        }
    }
    
    answer[sent_idx] = '\0';   
    
    return answer;
}