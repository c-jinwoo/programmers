#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 1000

// array_len은 배열 array의 길이입니다.
int solution(int array[], size_t array_len) {
    int answer = 0;
    int nums[MAX] = {0};
    int max = 0;
    
    // 빈도 수 체크
    for(int i = 0;i < array_len;i++){
        nums[array[i]]++;
    }
    
    // 최빈값 구하기
    for(int i = 1;i < MAX;i++){
        if(nums[max] < nums[i]){
            max = i;
            answer = 0;             // 최빈값이 여러개가 아니므로 임시로 0
        }
        else if(nums[max] == nums[i]){
            answer = -1;            // 최빈값이 여러개이므로 -1
        }
    }
    
    if(answer != -1){
        answer = max;               // 최빈값이 여러개가 아닐 경우에만 값 할당
    }
        
    return answer;
}