#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int dupl[53] = {0};     // 중복 체크용 배열

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = strlen(my_string);
    int cnt = 0;
    int idx = 0;
    
    for(int i = 0;i < len;i++){
        if(my_string[i] == 32){
            // 공백 체크
            if(!dupl[0]){
                dupl[0] = 1;
                cnt++;
            }
        }
        else if(65 <= my_string[i] && my_string[i] <= 90){
            // 대문자 체크
            if(!dupl[my_string[i] - 64]){
                dupl[my_string[i] - 64] = 1;
                cnt++;
            }
        }
        else{
            // 소문자 체크
            if(!dupl[my_string[i] - 70]){
                dupl[my_string[i] - 70] = 1;
                cnt++;
            }
        }
    }
    
    char* answer = (char*)malloc(cnt + 1);
    
    // 각 경우마다 dupl이 1인 것들만 복사하고 dupl을 0으로 변경시킴
    for(int i = 0;i < len;i++){
        if(my_string[i] == 32){
            if(dupl[0]){
                dupl[0] = 0;
                answer[idx++] = my_string[i];
            }
        }
        else if(65 <= my_string[i] && my_string[i] <= 90){
            if(dupl[my_string[i] - 64]){
                dupl[my_string[i] - 64] = 0;
                answer[idx++] = my_string[i];
            }
        }
        else{
            if(dupl[my_string[i] - 70]){
                dupl[my_string[i] - 70] = 0;
                answer[idx++] = my_string[i];
            }
        }     
    }
    
    answer[cnt] = '\0';
    
    return answer;
}