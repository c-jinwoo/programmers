#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* X, const char* Y) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int nums_X[10] = {0};    
    int nums_Y[10] = {0};
    int common = 0;                     // 공통 숫자 갯수
    bool isOnlyZero = true;             // 0만 있는지 여부
    char* answer;
    
    // 각 문자열 별로 숫자 횟수 기록
    for(int i = 0;i < strlen(X);i++){
        nums_X[X[i] - 48]++;
    }
    for(int i = 0;i < strlen(Y);i++){
        nums_Y[Y[i] - 48]++;
    }
    
    // 공통 숫자 갯수 카운트
    for(int i = 0;i < 10;i++){
        if(nums_X[i] && nums_Y[i]){
            if(i != 0){
                isOnlyZero = false;     // 1이상이 하나라도 있으면 거짓
            }
            
            // 각 숫자별로 작은 빈도만큼이 공통 출현 횟수
            common += (nums_X[i] > nums_Y[i]) ? nums_Y[i] : nums_X[i];
        }
    }
        
    if(common == 0){
        return "-1";        // 공통횟수가 없다면 "-1" 리턴
    }
    else if(isOnlyZero){        
        return "0";         // 공통 숫자가 0밖에없으면 "0" 리턴
    }
    else{
        answer = (char*)malloc(common + 1);
        answer[common] = '\0';
    }
    
    int idx = 0;
    int common_idx = 9;
    
    // 9부터 차례로 삽입
    while(common_idx != -1){
        if(nums_X[common_idx] && nums_Y[common_idx]){
            nums_X[common_idx]--;
            nums_Y[common_idx]--;
            answer[idx++] = common_idx + 48;
        }
        else{
            common_idx--;
        }
    }
    
    return answer;
}