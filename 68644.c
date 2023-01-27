#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int* solution(int numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int nums[201] = {0};        // 더해서 나오는 모든 값의 배열
    int count = 0;
    
    // 더한 모든 인덱스의 값을 1로
    for(int i = 0;i < numbers_len - 1;i++){
        for(int j = i + 1;j < numbers_len;j++){
            int result = numbers[i] + numbers[j];
            if(!nums[result]){
                count++;            // 없던 값이면 갯수 세기
            }
            nums[result] = 1;
        }
    }
    
    // 결과 배열 생성
    int* answer = (int*)malloc(count * sizeof(int));
    int idx = 0;
    
    for(int i = 0;i < 201;i++){
        if(nums[i]){
            answer[idx++] = i;
        }
    }
    
    return answer;
}