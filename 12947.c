#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(int x) {
    bool answer = true;
    int powers = 1;
    int sum = 0;
    int x_cpy = x;
    
    while(x_cpy){
        sum += x_cpy % 10;
        x_cpy /= 10;
    }
    
    answer = (x % sum) ? false : true;
        
    return answer;
}