#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// sides_len은 배열 sides의 길이입니다.
int solution(int sides[], size_t sides_len) {
    int answer = 0;
    int max = sides[0];
    int rest = 0;
    
    for(int i = 1;i < sides_len;i++){
        if(max < sides[i]){
            rest += max;
            max = sides[i];
        }
        else{
            rest += sides[i];
        }
    }
    
    answer = (rest > max) ? 1 : 2;
    
    return answer;
}