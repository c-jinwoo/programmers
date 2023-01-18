#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = strlen(my_string);
    char* answer = (char*)malloc(len + 1);
    
    for(int i = 0;i < len;i++){
        answer[i] = my_string[i];
        
        // 소문자화
        if(answer[i] <= 90){
            answer[i] += 32;
        }
    }
    answer[len] = '\0';
    
    for(int i = 0;i < len - 1;i++){
        int min = i;
        
        for(int j = i + 1;j < len;j++){
            if(answer[min] > answer[j]){
                min = j;
            }    
        }
        
        char tmp = answer[i];
        answer[i] = answer[min];
        answer[min] = tmp;
    }
    
    return answer;
}