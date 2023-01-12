#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// common_len은 배열 common의 길이입니다.
int solution(int common[], size_t common_len) {
    int answer = 0;
    int diff1 = common[2] - common[1];
    int diff2 = common[1] - common[0];
        
    if(diff1 == diff2){             // 등차
        answer = common[common_len - 1] + diff1;
    }
    else{                           // 등비
        answer = common[common_len - 1] * common[2] / common[1];       
    }    
    
    return answer;
}