#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// dots_rows는 2차원 배열 dots의 행 길이, dots_cols는 2차원 배열 dots의 열 길이입니다.
int solution(int** dots, size_t dots_rows, size_t dots_cols) {
    int answer = 0;
    
    // 기울기가 같다 == x증가량1 : y증가량1 = x증가량2 : y증가량2
    int x_diff1, x_diff2, y_diff1, y_diff2;
    
    // (1,2),(3,4)
    x_diff1 = dots[1][0] - dots[0][0];
    y_diff1 = dots[1][1] - dots[0][1];
    x_diff2 = dots[3][0] - dots[2][0];
    y_diff2 = dots[3][1] - dots[2][1];
    
    if(x_diff1 * y_diff2 == y_diff1 * x_diff2){
        answer = 1;
    }
    
    // (1,3),(2,4)
    x_diff1 = dots[2][0] - dots[0][0];
    y_diff1 = dots[2][1] - dots[0][1];
    x_diff2 = dots[3][0] - dots[1][0];
    y_diff2 = dots[3][1] - dots[1][1];
    
    if(x_diff1 * y_diff2 == y_diff1 * x_diff2){
        answer = 1;
    }
    
    // (1,4),(2,3)
    x_diff1 = dots[3][0] - dots[0][0];
    y_diff1 = dots[3][1] - dots[0][1];
    x_diff2 = dots[2][0] - dots[1][0];
    y_diff2 = dots[2][1] - dots[1][1];
    
    if(x_diff1 * y_diff2 == y_diff1 * x_diff2){
        answer = 1;
    }
     
    return answer;    
}