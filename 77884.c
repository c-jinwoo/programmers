#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int left, int right) {
    int answer = 0;
    
    for(int i = left;i <= right;i++){
        int count = 0;
        
        // 약수 홀수 여부 확인
        for(int j = 1;j <= i;j++){
            if(i % j == 0){
                count++;
            }
        }
        
        // 짝수면 더하고 홀수면 빼기
        answer += ((count % 2) ? -1 * i : i);
    }
    
    return answer;
}