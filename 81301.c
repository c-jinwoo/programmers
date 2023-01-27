#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 0;
    int len = strlen(s);
    int idx = 0;
    int digit = 0;
    int powers = 1;
    char* nums[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    // 문자끝까지 반복
    while(s[idx] != '\0'){        
        if(48 <= s[idx] && s[idx] <= 57){       // 숫자면 바로 대입
            digit = s[idx] - 48;
            idx++;
        }
        else{
            for(int i = 0;i < 10;i++){           // 문자면 숫자문자열과 비교 후 대입
                bool isNumMatch = false;
                int matchCnt = 0;

                for(int j = 0;j < strlen(nums[i]);j++){
                    if(s[idx] == nums[i][j]){
                        idx++;
                        matchCnt++;
                    }
                    else{
                        idx -= j;                   // 매칭실패시 검색한 인덱스만큼 감소 후 재진행
                        break;
                    }

                    if(matchCnt == strlen(nums[i])){
                        isNumMatch = true;
                    }
                }

                if(isNumMatch){
                    digit = i;
                    break;
                }
            }   
        }
        
        answer *= 10;
        answer += digit;
    }
    
    return answer;
}