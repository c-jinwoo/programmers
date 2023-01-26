#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// quiz_len은 배열 quiz의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* quiz[], size_t quiz_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char** answer = (char**)malloc(quiz_len * sizeof(char*));
    
    for(int i = 0;i < quiz_len;i++){
        int nums[3] = {0};
        int idx = 0;
        char op;
        char* ptr = strtok(quiz[i], " ");
                
        while(ptr != NULL){               
            if(idx % 2 == 0){   // 짝수번째 토큰마다 숫자 추출                         
                int value = 0;
                int powers = 1;
                
                // 문자열 수치화
                for(int i = 0;i < strlen(ptr);i++){
                    if(ptr[strlen(ptr) - i - 1] != '-'){
                        value += ((ptr[strlen(ptr) - i - 1] - 48) * powers);
                    }
                    powers *= 10;
                }
                
                // 맨 앞자리가 -면 음수화
                if(ptr[0] == '-'){
                    value *= -1;
                }
                
                // 배열에 저장
                nums[idx / 2] = value;
            }
            
            // 연산자 정보 저장
            if(idx == 1){
                op = ptr[0];
            }
                   
            idx++;
            ptr = strtok(NULL, " ");    
        }
        
        // 결과 저장
        answer[i] = (char*)malloc(1);
        
        if(op == '+'){
            (nums[0] + nums[1] == nums[2]) ? strcpy(answer[i], "O") : strcpy(answer[i], "X");
        }
        else{
            (nums[0] - nums[1] == nums[2]) ? strcpy(answer[i], "O") : strcpy(answer[i], "X");
        }
    }
    
    return answer;
}