#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// dot_len은 배열 dot의 길이입니다.
int solution(int dot[], size_t dot_len) {
    int answer = 0;
    
    if(dot[0] * dot[1] > 0){
        answer = (dot[0] < 0) ? 3 : 1;
    }
    else{
        answer = (dot[0] < 0) ? 2 : 4;
    }
        
    return answer;
}