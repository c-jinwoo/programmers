#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int hp) {
    int answer = 0;
    int power[3] = {5, 3, 1};
    
    for(int i = 0;i < 3;i++){
        int cnt = hp / power[i];
        hp -= cnt * power[i];
        answer += cnt;
    }
    
    return answer;
}