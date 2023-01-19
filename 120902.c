#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* my_string) {
    int answer = 0;
    int calc_type = 1;                      // 1 : 더하기, 2 : 빼기
    char *ptr = strtok(my_string, " ");     // 띄어쓰기 토큰화
    
    while(ptr != NULL){
        if(!strcmp(ptr, "+")){
            calc_type = 1;
        }
        else if(!strcmp(ptr, "-")){
            calc_type = 2;
        }
        else{
            int len = strlen(ptr);
            int powers = 1;
            int idx = 0;
            int result = 0;
            
            // 토큰화된 문자열을 숫자로 변환
            while(idx < len){
                result += (ptr[len - idx - 1] - 48) * powers;
                powers *= 10;
                idx++;
            }        
            
            // 연산자에 따라 결과반영
            if(calc_type == 1){
                answer += result;
            }
            else if(calc_type == 2){
                answer -= result;
            }            
        }
        ptr = strtok(NULL, " ");
    }
    
    return answer;
}