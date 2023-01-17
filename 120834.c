#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int age) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int digit = 1;
    int powers = 1;
    int age_cpy = age;
    
    while(age_cpy >= 10){
        age_cpy /= 10;
        powers *= 10;
        digit++;
    }
    
    char* answer = (char*)malloc(digit + 1);
    
    for(int i = 0;i < digit;i++){
        answer[i] = age / powers + 97;
        age -= (answer[i] - 97) * powers;
        powers /= 10;
    }
    
    answer[digit] = '\0';
    
    return answer;
}