#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* my_string) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = strlen(my_string);
    int cnt = 0;
    int idx = 0;
    
    // 0~9 카운트
    for(int i = 0;i < len;i++){
        if(48 <= my_string[i] && my_string[i] <= 57){
            cnt++;        
        }
    }
    
    int* answer = (int*)malloc(cnt * sizeof(int));
    
    for(int i = 0;i < len;i++){
        if(48 <= my_string[i] && my_string[i] <= 57){
            answer[idx] = my_string[i] - 48;
            idx++;
        }
    }
    
    // 오름차순 정렬
    for(int i = 0;i < cnt - 1;i++){
        int min = i;
        
        for(int j = i + 1;j < cnt;j++){
            if(answer[min] >= answer[j]){
                min = j;
            }
        }
        
        int temp = answer[i];
        answer[i] = answer[min];
        answer[min] = temp;        
    }
    
    return answer;
}