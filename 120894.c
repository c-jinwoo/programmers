#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
long long solution(const char* numbers) {
    long long answer = 0;
    int idx = 0;                // 문자열 내 현재 기준 인덱스
    char* num2str[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    while(idx < strlen(numbers)){        
        for(int i = 0;i < 10;i++){
            bool isNum = true;
            
            for(int j = 0;j < strlen(num2str[i]);j++){
                if(numbers[idx + j] != num2str[i][j]){
                    isNum = false;              // zero~nine 매칭이 안될 경우 다음 숫자 찾기
                    break;
                }
            }
            
            if(isNum){
                idx += strlen(num2str[i]);      // 찾은 숫자 문자열 길이만큼 인덱스 이동
                answer *= 10;                   // 현재 숫자 자리수 이동
                answer += i;                    // 새로운 숫자 더하기
                break;
            }
        }
    }
    
    return answer;
}