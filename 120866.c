#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// board_rows는 2차원 배열 board의 행 길이, board_cols는 2차원 배열 board의 열 길이입니다.
int solution(int** board, size_t board_rows, size_t board_cols) {
    int answer = 0;
    
    // 폭탄 주변 정보 저장용 
    int** board_cpy = (int**)malloc(board_rows * sizeof(int*));
    for(int i = 0;i < board_rows;i++){
        board_cpy[i] = (int*)malloc(board_cols * sizeof(int));
        
        for(int j = 0;j < board_cols;j++){
            board_cpy[i][j] = 0;
        }
    }
    
    // 폭탄 위치 및 8방향으로 위험지역 표시
    for(int i = 0;i < board_rows;i++){
        for(int j = 0;j < board_cols;j++){
            if(board[i][j]){
                for(int k = i - 1;k < i + 2;k++){
                    for(int l = j - 1;l < j + 2;l++){
                        if((k >= 0) && (k < board_rows) && (l >= 0) && (l < board_cols)){
                            board_cpy[k][l] = 1;
                        }
                    }
                }
            }
        }
    }
    
    // 안전지대 갯수 체크
    for(int i = 0;i < board_rows;i++){
        for(int j = 0;j < board_cols;j++){
            if(!board_cpy[i][j]){
                answer++;
            }
        }
    }
    
    free(board_cpy);
    
    return answer;
}