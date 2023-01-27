#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// number_len은 배열 number의 길이입니다.
int solution(int number[], size_t number_len) {
    int answer = 0;
    int first = 0, second = 0, third = 0;
    
    for(first = 0;first < number_len - 2;first++){
        for(second = first + 1;second < number_len - 1;second++){
            for(third = second + 1;third < number_len;third++){
                if(number[first] + number[second] + number[third] == 0){
                    answer++;  
                }
            }
        }
    }
    
    return answer;
}