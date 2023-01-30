#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define ALPHABET_NUM 26

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = strlen(s);
    int* answer = (int*)malloc(len * sizeof(int));
    int record[ALPHABET_NUM];               // 가장 최근 출현 인덱스 기록용
    
    memset(record, -1, sizeof(record));     // 초기화
        
    for(int i = 0;i < len;i++){
        // 기록에 값이 있으면 차이만큼, 없으면 -1
        answer[i] = (record[s[i] - 97] == -1) ? -1 : i - record[s[i] - 97];
        
        // 최근 기록 저장
        record[s[i] - 97] = i;
    }
    
    return answer;
}