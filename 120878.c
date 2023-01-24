#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int a, int b) {
    int answer = 0;
    
    // 기약분수 만들기
    for(int i = 2;i <= a;i++){
        if((a % i == 0) && (b % i == 0)){
            a /= i;
            b /= i;
        }
    }
    
    // 분모 소인수 2,5 판별
    while(b % 2 == 0){
        b /= 2;
    }
    
    while(b % 5 == 0){
        b /= 5;
    }
    
    // 결과 저장
    answer = (b == 1) ? 1 : 2;
    
    return answer;
}