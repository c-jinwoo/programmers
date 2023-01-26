#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define LEN 200
// lines_rows는 2차원 배열 lines의 행 길이, lines_cols는 2차원 배열 lines의 열 길이입니다.
int solution(int** lines, size_t lines_rows, size_t lines_cols) {
    int answer = 0;
    int bar[LEN] = {0};                         // 수직선 배열
    
    for(int i = 0;i < lines_rows;i++){
        for(int j = 0;j < lines_cols;j++){
            lines[i][j] += 100;                 // 범위에 맞게 평행이동
        }
        for(int k = lines[i][0];k < lines[i][1];k++){
            bar[k]++;                           // 각 선분 별로 위치한 곳에 1씩 증가
        }
    }
    for(int i = 0;i < LEN;i++){
        if(bar[i] > 1){
            answer++;                           // 1보다 큰 곳은 겹친 부분이므로 갯수 증가
        }
    }    
    
    return answer;
}