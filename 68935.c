#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    
    // 1. 3진법으로
    int n_cpy = n;
    long long n_3arith = 0;
    long long powers = 1;
    
    while(n_cpy / 3){
        n_3arith += (n_cpy % 3) * powers;
        powers *= 10;
        n_cpy /= 3;
    }
    n_3arith += n_cpy * powers;         // 마지막 최고자리수
    
    // 2. 3진법 뒤집기
    long long n_3arith_rev = 0;
    while(n_3arith){
        n_3arith_rev += powers * (n_3arith % 10);
        n_3arith /= 10;
        powers /= 10;
    }
    
    // 3. 10진법으로 표현
    int powers3 = 1;
    while(n_3arith_rev){
        answer += (n_3arith_rev % 10) * powers3;
        n_3arith_rev /= 10;
        powers3 *= 3;
    }    
    
    return answer;
}