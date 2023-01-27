#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int price, int money, int count) {
    long long answer = 0;
    long long total = 0;
    
    for(int i = 0;i < count;i++){
        total += price * (i + 1);
    }
    
    answer = total - (long long)money;
    
    if(answer < 0){
        answer = 0;
    }
        
    return answer;
}