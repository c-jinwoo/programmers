#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 2000

int nums[MAX] = {0}; 

// sides_len은 배열 sides의 길이입니다.
int solution(int sides[], size_t sides_len) {
    int answer = 0;
    
    for(int i = 1;i < MAX;i++){                     // 나머지 한 변 : i        
        if(i > sides[0] && i > sides[1]){           // 나머지 한 변이 가장 긴 변일 경우
            if(i < sides[0] + sides[1]){
                nums[i] = 1;
            }
        }
        else{                                       // sides[] 중에 가장 긴 변이 있는 경우
            if(sides[0] >= sides[1]){
                if(i > sides[0] - sides[1]){
                    nums[i] = 1;
                }
            }
            else{
                if(i > sides[1] - sides[0]){
                    nums[i] = 1;
                }
            }
        }
    }
    
    // 갯수 카운트
    for(int i = 0;i < MAX;i++){
        if(nums[i]){
            answer++;        
        }
    }
    
    return answer;
}