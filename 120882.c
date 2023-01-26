#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// score_rows는 2차원 배열 score의 행 길이, score_cols는 2차원 배열 score의 열 길이입니다.
int* solution(int** score, size_t score_rows, size_t score_cols) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(score_rows * sizeof(int));
    int* sum = (int*)malloc(score_rows * sizeof(int));      // 합 배열
    int rank = 1;                                           // 순위
    
    for(int i = 0;i < score_rows;i++){
        sum[i] = score[i][0] + score[i][1];
    }
    
    for(int i = 200;i >= 0;i--){
        int tie = 0;
        
        for(int j = 0;j < score_rows;j++){
            if(sum[j] == i){
                answer[j] = rank;
                tie++;                  // 중복 갯수 저장
            }
        }
        
        rank += tie;                    // 중복 갯수만큼 순위 증가
    }
    
    free(sum);
       
    return answer;
}