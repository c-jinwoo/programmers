#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// nums_len은 배열 nums의 길이입니다.
int solution(int nums[], size_t nums_len) {
    int answer = 0;
    
    for(int i = 0;i < nums_len - 2;i++){
        for(int j = i + 1;j < nums_len - 1;j++){
            for(int k = j + 1;k < nums_len;k++){
                int sum = nums[i] + nums[j] + nums[k];
                bool isPrime = true;
                
                for(int l = 2;l <= sum / 2;l++){
                    if(sum % l == 0){
                        isPrime = false;
                        break;
                    }
                }
                
                if(isPrime){
                    answer++;
                }
            }
        }
    }
    
    
    return answer;
}