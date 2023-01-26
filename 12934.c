#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(long long n) {
    long long answer = -1;
    
    for(long long i = 1;i <= n;i++){
        if(n == i * i){
            answer = (i + 1) * (i + 1);
            break;
        }
    }
    
    return answer;
}