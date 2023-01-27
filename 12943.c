#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num) {
    if(num == 1){
        return 0;
    }
    
    int cnt = 0;
    long long num_cpy = num;            // 값 범위 초과하는 경우 발생
    
    while(num_cpy != 1 && cnt < 500){
        if(num_cpy % 2){
            num_cpy = num_cpy * 3 + 1;
        }       
        else{
            num_cpy /= 2;
        }
        cnt++;        
    }
    
    if(cnt >= 500){
        return -1;
    }
    
    return cnt;
}