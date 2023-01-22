#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int a, int b) {
    long long answer = 0;
    
    if(a == b){
        return a;
    }
    
    int big = (a > b) ? a : b;
    int small = (a > b) ? b : a;
    
    for(int i = small;i <= big;i++){
        answer += i;
    }
    
    return answer;
}