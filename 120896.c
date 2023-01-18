#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define ALPHABET_CNT 26
#define ALPHABET_OFFSET 97

int words[ALPHABET_CNT] = {0};      // 단어 빈도 체크용

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = strlen(s);
    int cnt = 0;
    int idx = 0;
    
    // 단어 출현 횟수 
    for(int i = 0;i < len;i++){
        if(words[s[i] - ALPHABET_OFFSET] == 0){
            cnt++;                                  // 1번만 등장하는 단어갯수 카운트
        }
        words[s[i] - ALPHABET_OFFSET]++;
    }
    
    char* answer = (char*)malloc(cnt + 1);
    
    for(int i = 0;i < ALPHABET_CNT;i++){
        if(words[i] == 1){
            answer[idx++] = i + ALPHABET_OFFSET;    // 1번만 등장하는 단어 삽입        
        }
    }
    
    answer[idx] = '\0';
    
    return answer;
}