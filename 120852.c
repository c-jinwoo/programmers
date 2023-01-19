#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 10000

int nums[MAX] = {0};

int* solution(int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int cnt = 0;
    int idx = 0;
    
    // 소인수 갯수파악
    for(int i = 2;i <= n;i++){
        while(n % i == 0){
            nums[i]++;
            n /= i;
            
            if(nums[i] == 1){
                cnt++;
            }
        }
    }
    
    int* answer = (int*)malloc(cnt * sizeof(int));
    
    // 오름차순으로 배열에 삽입
    for(int i = 2;i <= MAX;i++){
        if(nums[i]){
            answer[idx++] = i;
        }
    }
    
    return answer;
}