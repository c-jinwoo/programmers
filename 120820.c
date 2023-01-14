#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define CURRENT_YEAR 2022

int solution(int age) {
    int answer = CURRENT_YEAR - age + 1;
    return answer;
}