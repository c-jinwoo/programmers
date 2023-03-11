#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define ALPHABET_NUM 26
#define ALPHABET_OFFSET 97
#define ALPHABET_MAX 122

char* solution(const char* s, const char* skip, int index) {
    int skip_arr[ALPHABET_NUM] = {0};           // skip에 해당하는 문자 저장용
    int len = strlen(s);                        // 문자열 s의 길이
    char* answer = (char*)malloc(len + 1);      // answer 동적할당
    answer[len] = '\0';
    
    for(int i = 0; i < strlen(skip); i++){
        skip_arr[skip[i] - ALPHABET_OFFSET]++;
    }
    
    for(int i = 0; i < len; i++){
        int incr = 0;
        answer[i] = s[i];
        
        while(incr < index){
            answer[i]++;
            
            if(answer[i] > ALPHABET_MAX){
                answer[i] = ALPHABET_OFFSET;    // z 넘어가면 다시 a로
            }
            
            if(!skip_arr[answer[i] - ALPHABET_OFFSET]){
                incr++;                         // skip에 해당 안 될 경우만 incr 증가
            }
        }
    }
        
    return answer;
}