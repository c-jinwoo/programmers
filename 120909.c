#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 2;
    
    if(n == 1){
        return 1;
    }
    
    for(int i = 2;i <= 1000;i++){        
        if((n / i == i) && (n % i == 0)){
            answer = 1;
            break;
        }
    }
    
    return answer;
}