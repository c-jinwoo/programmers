#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define TYPENUM 8

// survey_len은 배열 survey의 길이입니다.
// choices_len은 배열 choices의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.

char int2Type(int idx){
    char result = 0;
    
    switch(idx){
        case 0:
            result = 'R';
            break;
        case 1:
            result = 'T';
            break;
        case 2:
            result = 'C';
            break;
        case 3:
            result = 'F';
            break;
        case 4:
            result = 'J';
            break;
        case 5:
            result = 'M';
            break;
        case 6:
            result = 'A';
            break;
        case 7:
            result = 'N';
            break;
    }
    
    return result;
}

int type2Int(char type){
    int result = 0;
    
    switch(type){
        case 'R':
            result = 0;
            break;
        case 'T':
            result = 1;
            break;
        case 'C':
            result = 2;
            break;
        case 'F':
            result = 3;
            break;
        case 'J':
            result = 4;
            break;
        case 'M':
            result = 5;
            break;
        case 'A':
            result = 6;
            break;;
        case 'N':
            result = 7;
            break;
    }
    
    return result;
}


char* solution(const char* survey[], size_t survey_len, int choices[], size_t choices_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(5);
    int type[TYPENUM] = {0};           // 8개 유형에 따른 점수표(R, T, C, F, J, M, A, N 순)
    answer[4] = '\0';
    
    // 각 결과별로 점수 계산
    for(int i = 0;i < survey_len;i++){
        int score = 4 - choices[i];
        
        if(score > 0){
            type[type2Int(survey[i][0])] += score;
        }
        else if(score < 0){
            type[type2Int(survey[i][1])] += (-1 * score);
        }
    }
    
    // 각 점수별로 유형 선정
    for(int i = 0;i < TYPENUM;i++){        
        if(i % 2 == 1){
            if(type[i - 1] >= type[i]){
                answer[i / 2] = int2Type(i - 1);
            }
            else{
                answer[i / 2] = int2Type(i);
            }
        }
    }
        
    return answer;
}