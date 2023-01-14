#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int slice, int n) {
    int answer = 0;
    
    // 피자판수 * 피자조각수 >= 사람수
    answer = n / slice;
    
    if(n % slice){
        answer++;
    }
    
    return answer;
}