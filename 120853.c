#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200
#define NUM_OFFSET 48

int nums[MAX] = {0};

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 0;
    int idx = 0;
    char* ptr = strtok(s, " ");
    
    while(ptr != NULL){
        if(!strcmp(ptr, "Z")){
            nums[--idx] = 0;            // nums 에서 기록 삭제
        }
        else{
            int result = 0;
            int powers = 1;
            int len = strlen(ptr);
            
            // 숫자로 변환
            for(int i = 0;i < len;i++){
                if(ptr[len - 1 - i] != '-'){
                    result += (ptr[len - 1 - i] - NUM_OFFSET) * powers;
                    powers *= 10;
                }   
            }
            
            if(ptr[0] == '-'){
                result *= -1;
            }
            
            nums[idx++] = result;         // nums 에 결과값 기록
        }
        ptr = strtok(NULL, " ");
    }
    
    for(int i = 0;i < idx + 1;i++){
        answer += nums[i];
    }
    
    return answer;
}