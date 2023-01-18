#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define ALPHABET_CNT 26
#define ALPHABET_SMALL_OFFSET 97

int before_cnt[ALPHABET_CNT] = {0};
int after_cnt[ALPHABET_CNT] = {0};

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* before, const char* after) {
    int answer = 1;
    int len = strlen(before);
    
    for(int i = 0;i < len;i++){
        before_cnt[before[i] - ALPHABET_SMALL_OFFSET]++;
        after_cnt[after[i] - ALPHABET_SMALL_OFFSET]++;
    }
    
    for(int i = 0;i < ALPHABET_CNT;i++){
        if(before_cnt[i] != after_cnt[i]){
            answer = 0;
            break;
        }
    }    
    
    return answer;
}