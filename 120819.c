#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define PRICE 5500

int* solution(int money) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(2 * sizeof(int));
    
    // 잔 수
    answer[0] = money / PRICE;
    
    // 남은 돈
    answer[1] = money % PRICE;
    
    return answer;
}