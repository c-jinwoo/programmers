#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int i, int j, int k) {
    int answer = 0;
    
    for(int n = i;n <= j;n++){
        int num = n;                    // 현재 숫자 복사
        
        while(num){                     // num이 0이 아닐 때 까지
            if(num % 10 == k){          // 1의 자리 수 확인
                answer++;               // 같으면 answer 증가
            }
            num /= 10;                  // 현재 숫자 오른쪽 1자리 이동
        }
    }   
    
    return answer;
}