#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define DATE_OFFSET_IDX 5       // 1/1 금요일 인덱스 5

char* solution(int a, int b) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    char* day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    char* answer = (char*)malloc(3);
    int date[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // 총 날짜 계산
    int total = 0;
    int day_idx = 0;
    
    for(int i = 0;i < a - 1;i++){
        total += date[i];           // 이전 달까지 날짜더하기
    }    
    total += b - 1;                 // 현재 달의 날짜까지 더하기
    
    day_idx = (DATE_OFFSET_IDX + total % 7)  % 7;   // 1/1 기본 인덱스까지 고려해서 % 7
    
    strcpy(answer, day[day_idx]);
    
    return answer;
}