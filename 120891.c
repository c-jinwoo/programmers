#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int order) {
    int answer = 0;
    int powers = 1;
    
    // 자리수 계산
    while(order / powers >= 10){
        powers *= 10;
    }
    
    // 역순으로 자리수 체크
    while(order){
        int digit = order / powers;
        
        if(digit == 3 || digit == 6 || digit == 9){
            answer++;
        }
        
        order -= digit * powers;
        powers /= 10;        
    }
        
    return answer;
}