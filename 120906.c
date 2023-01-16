#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    int deno = 1;
    
    while(n / deno != 0){
        int value = n % (deno * 10);
        int digit_num = value / deno;
        
        n -= value;
        answer += digit_num;
        deno *= 10;
    }
    
    return answer;
}