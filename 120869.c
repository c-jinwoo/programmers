#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define ALPHABET_CNT 26
#define ALPHABET_OFFSET 97

int nums[ALPHABET_CNT] = {0};       // 출현 알파벳 기록용

// spell_len은 배열 spell의 길이입니다.
// dic_len은 배열 dic의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* spell[], size_t spell_len, const char* dic[], size_t dic_len) {
    int answer = 2;
        
    for(int i = 0;i < dic_len;i++){
        int result = 0;
        
        // spell에 출현한 알파벳 기록
        for(int i = 0;i < spell_len;i++){
            nums[spell[i][0] - ALPHABET_OFFSET] = 1;        
        }
        
        for(int j = 0;j < strlen(dic[i]);j++){
            if(nums[dic[i][j] - ALPHABET_OFFSET]){
                result++;                               // spell에 있던 단어면 결과값 증가
                nums[dic[i][j] - ALPHABET_OFFSET] = 0;  // 중복 방지용 초기화
            }
        }
        
        // 갯수가 같으면 결과 = 2
        if(result == spell_len){
            answer = 1;
            break;
        }
    }    
    
    return answer;
}