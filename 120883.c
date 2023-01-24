#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// id_pw_len은 배열 id_pw의 길이입니다.
// db_rows는 2차원 배열 db의 행 길이, db_cols는 2차원 배열 db의 열 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* id_pw[], size_t id_pw_len, const char*** db, size_t db_rows, size_t db_cols) {
    bool id_check = false;
    bool pw_check = false;
    int return_len = 0; 
    char* answer;
    char* result[3] = {"login", "wrong pw", "fail"};
    
    for(int i = 0;i < db_rows;i++){
        if(!strcmp(id_pw[0], db[i][0])){        // 아이디 같을 시 비밀번호 일치 유무 확인
            id_check = true;
            pw_check = (!strcmp(id_pw[1], db[i][1])) ? true : false;
            break;
        }        
    }
    
    // 결과값 복사
    if(id_check){
        if(pw_check){
            answer = (char*)malloc(6);
            strcpy(answer, result[0]);
        }
        else{
            answer = (char*)malloc(9);
            strcpy(answer, result[1]);
        }        
    }
    else{
        answer = (char*)malloc(5);
        strcpy(answer, result[2]);
    }
    
    return answer;
}