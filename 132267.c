#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int a, int b, int n) {
    int answer = 0;
    
    while(n >= a){
        int num_exchange = b * n / a;
        int num_remainder = n % a;
        
        n = num_exchange + num_remainder;
        answer += num_exchange;
    }
    
    return answer;
}