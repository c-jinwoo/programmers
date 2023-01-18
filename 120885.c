#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int bin2int(char* str){
    int len = strlen(str);
    int result = 0;
    int powers = 1;    
    
    for(int i = 0;i < len;i++){
        if(str[len - 1 - i] == '1'){
            result += powers;
        }
        powers *= 2;
    }
    
    return result;
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* bin1, const char* bin2) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.    
    int int_bin1 = bin2int(bin1);
    int int_bin2 = bin2int(bin2);
    int int_result = int_bin1 + int_bin2;       // 숫자로 변경하고 더한 값
    int int_result_cpy = int_result;            // 자리수 계산을 위해 값 복사
    int len = 1;
    
    while(int_result_cpy > 1){
        int_result_cpy /= 2;
        len++;
    }
    
    char* answer = (char*)malloc(len + 1);
    answer[len] = '\0';
    
    for(int i = 0;i < len - 1;i++){
        answer[len - 1 - i] = (int_result % 2) ? '1' : '0';
        int_result /= 2;                        // 나머지가 1,0에 따라 '1','0' 삽입 후 나누기 2
    }
    
    answer[0] = int_result ? '1' : '0';         // 첫 자리는 남은 값에 따라 '1' 또는 '0'
        
    return answer;
}