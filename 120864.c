#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* my_string) {
    int answer = 0;
    int len = strlen(my_string);
    int temp = 0;
    
    for(int i = 0;i < len;i++){
        if(48 <= my_string[i] && my_string[i] <= 57){
            temp += my_string[i] - 48;
            
            // 마지막 단어일 경우
            if(i == len - 1){
                answer += temp;
                break;
            }
            
            // 다음 문자를 확인하여 숫자일 경우 10배 증가, 숫자가 아니면 값 저장 후 임시값 초기화           
            if(48 <= my_string[i + 1] && my_string[i + 1] <= 57){
                temp *= 10;
            }
            else{
                answer += temp;
                temp = 0;
            }
        }
    }
    
    return answer;
}