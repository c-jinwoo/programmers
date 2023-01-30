#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// lottos_len은 배열 lottos의 길이입니다.
// win_nums_len은 배열 win_nums의 길이입니다.
int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(2 * sizeof(int));
    int nums[45] = {0};
    int hit = 0;            // 일치 갯수
    int zeros = 0;          // 0 갯수
    
    // 로또 번호 메모
    for(int i = 0;i < win_nums_len;i++){
        nums[win_nums[i] - 1] = 1;
    }
    
    // 로또 카운트
    for(int i = 0;i < lottos_len;i++){
        if(nums[lottos[i] - 1]){
            hit++;              // 맞춘 갯수 카운트
        }        
        if(lottos[i] == 0){
            zeros++;            // 0 갯수 카운트
        }
    }
    
    answer[0] = (hit + zeros == 0) ? 6 : 7 - (hit + zeros);  // 최고 등수
    answer[1] = (hit == 0) ? 6 : 7 - hit;                   // 최저 등수
    
    return answer;
}