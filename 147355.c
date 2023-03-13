#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* t, const char* p) {
    int answer = 0;
    long long num_p = 0;
    int powers = 1;
    
    // p 숫자화
    for(int i = 0;i < strlen(p);i++){
        num_p *= 10;
        num_p += powers * (p[i] - 48);
    }
    
    // 부분문자열 돌아가며 계산
    for(int i = 0;i <= strlen(t) - strlen(p);i++){
        long long num_portion = 0;
        powers = 1;
        
        for(int j = i;j < i + strlen(p);j++){
            num_portion *= 10;
            num_portion += powers * (t[j] - 48);
        }
                
        if(num_portion <= num_p){
            answer++;
        }
    }
    
    return answer;
}