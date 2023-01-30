#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 0;
    int idx_init = 0;
    int cnt_same = 0;
    int cnt_diff = 0;
    
    for(int i = 0;i < strlen(s);i++){  
        // 기준문자와 같으면 cnt_same, 다르면 cnt_diff 증가
        if(s[i] == s[idx_init]){
            cnt_same++;
        }
        else{
            cnt_diff++;
        }
        
        // 두 개가 같아진 경우 answer증가, 기준문자를 다음 문자로, 나머지 초기화
        if(cnt_same == cnt_diff){
            answer++;
            cnt_same = 0;
            cnt_diff = 0;
            idx_init = i + 1;
        }
        else{
            if(i == strlen(s) -1){
                answer++;           // 마지막 문자에서 잔여 문자열의 경우 answer 증가
            }
        }
    }
    
    return answer;
}