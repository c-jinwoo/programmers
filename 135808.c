#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// score_len은 배열 score의 길이입니다.
int solution(int k, int m, int score[], size_t score_len) {
    int answer = 0;
    int score_arr[10] = {0};
    int score_max = 0;
    
    // score 기록
    for(int i = 0;i < score_len;i++){
        score_arr[score[i]]++;
        
        if(score_max < score[i]){
            score_max = score[i];
        }
    }
    
    // score 내림차순
    int* score_rev = (int*)malloc(score_len * sizeof(int));
    int idx = 0;
    
    for(int i = 9;i > 0;i--){
        for(int j = 0;j < score_arr[i];j++){
            score_rev[idx++] = i;
        }
    }
    
    // m개 마다 가격 계산
    for(int i = 0;i < score_len;i++){
        if((i + 1) % m == 0){
            answer += score_rev[i] * m;
        }
    }
    
    free(score_rev);
    
    return answer;
}