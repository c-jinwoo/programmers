#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* polynomial) {    
    char* ptr = strtok(polynomial, " ");
    int coeff_x = 0;        // x 계수
    int coeff_num = 0;      // 상수 계수
    
    while(ptr != NULL){
        // 띄어쓰기 토큰 중 + 기호는 제외
        if(strcmp(ptr, "+")){
            int num = 0;
            int powers = 1;
            int len = strlen(ptr);
            bool isX = (ptr[len - 1] == 'x') ? true : false;
            
            // x항이면서 1이 생략된 항은 별도 처리
            if(isX && (len == 1)){
                coeff_x++;
            }
            else{            
                if(isX){
                    len--;
                }
                
                // 계수 계산
                for(int i = 0;i < len;i++){
                    if(isX){
                        coeff_x += (ptr[len - 1 - i] - 48) * powers;
                    }
                    else{
                        coeff_num += (ptr[len - 1 - i] - 48) * powers;
                    }
                    powers *= 10;
                }
            }
        }        
        ptr = strtok(NULL, " ");
    }
    
    // 자리수 계산    
    int coeff_x_cpy = coeff_x;
    int coeff_num_cpy = coeff_num;
    int coeff_x_digit = 0;
    int coeff_num_digit = 0;
    
    if(coeff_x_cpy){
        while(coeff_x_cpy / 10){
            coeff_x_digit++;
            coeff_x_cpy /= 10;
        }
        coeff_x_digit++;                // 1의 자리수
    }
    if(coeff_num_cpy){
        while(coeff_num_cpy / 10){
            coeff_num_digit++;
            coeff_num_cpy /= 10;
        }
        coeff_num_digit++;              // 1의 자리수
    }
    
    /*** 문자화 ***/
    // 동적할당 길이 : x항 계수자리수 + x + 상수항 계수 자리수 + 널문자
    int new_len = coeff_x_digit + 1 + coeff_num_digit + 1;  
    if(coeff_x && coeff_num){
        new_len += 3;                   // 계수 두가지 모두 1이상이면 띄어쓰기 및 + 기호 필요
    }
    
    char* answer = (char*)malloc(new_len);         
    memset(answer, 0, new_len);                     // 동적할당 초기화
    
    if(coeff_x){        
        if(coeff_x == 1){
            strcat(answer, "x");                    // x항 계수가 1인 경우 별도 처리
        }
        else{
            char* coeff_x_str = (char*)malloc(coeff_x_digit + 1);        
            sprintf(coeff_x_str, "%dx", coeff_x);   // x항 문자화
            strcat(answer, coeff_x_str);            // answer에 붙히기
            free(coeff_x_str);      
        }
    }
    
    if(coeff_x && coeff_num){
        char op[] = " + ";                          // x항과 상수항의 계수가 모두 0이 아닌 경우 '+'
        strcat(answer, op);
    }
    
    if(coeff_num){
        char* coeff_num_str = (char*)malloc(coeff_num_digit);
        sprintf(coeff_num_str, "%d", coeff_num);    // 상수항 문자화
        strcat(answer, coeff_num_str);              // answer에 붙히기
        free(coeff_num_str);
    }
    
    return answer;
}