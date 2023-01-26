#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    
    for(int i = 0;i < n;i++){
        answer++;
        
        if(answer % 3 == 0){
            answer++;                       // 3의 배수면 하나 더 증가
        }
        
        int answer_cpy = answer;            // 3이 자리수에 있는지 확인하기 위해 임시 저장
        
        while(answer_cpy){
            if(answer_cpy % 10 == 3){
                answer++;
                
                if(answer % 3 == 0){
                    answer++;               // 증가 후 다시 3의 배수면 하나 더 증가
                }
                
                answer_cpy = answer;
                continue;
            }
            
            answer_cpy /= 10;
        }        
    }
    
    return answer;
}