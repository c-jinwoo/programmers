#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int fact(int n){
    if(n <= 1){
        return 1;
    }
    
    return n * fact(n - 1);
}

int solution(int n) {
    int answer = 1;
    
    while(fact(answer) <= n){
        answer++;
    }    
    
    answer -= 1;
    
    return answer;
}