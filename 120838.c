#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char get_morse(char* str){
    char result;
    if(!strcmp(str, ".-")){
        result = 'a';
    }
    else if(!strcmp(str, "-...")){
        result = 'b';
    }
    else if(!strcmp(str, "-.-.")){
        result = 'c';
    }
    else if(!strcmp(str, "-..")){
        result = 'd';
    }
    else if(!strcmp(str, ".")){
        result = 'e';
    }
    else if(!strcmp(str, "..-.")){
        result = 'f';
    }
    else if(!strcmp(str, "--.")){
        result = 'g';
    }
    else if(!strcmp(str, "....")){
        result = 'h';
    }
    else if(!strcmp(str, "..")){
        result = 'i';
    }
    else if(!strcmp(str, ".---")){
        result = 'j';
    }
    else if(!strcmp(str, "-.-")){
        result = 'k';
    }
    else if(!strcmp(str, ".-..")){
        result = 'l';
    }
    else if(!strcmp(str, "--")){
        result = 'm';
    }
    else if(!strcmp(str, "-.")){
        result = 'n';
    }
    else if(!strcmp(str, "---")){
        result = 'o';
    }
    else if(!strcmp(str, ".--.")){
        result = 'p';
    }
    else if(!strcmp(str, "--.-")){
        result = 'q';
    }
    else if(!strcmp(str, ".-.")){
        result = 'r';
    }
    else if(!strcmp(str, "...")){
        result = 's';
    }
    else if(!strcmp(str, "-")){
        result = 't';
    }
    else if(!strcmp(str, "..-")){
        result = 'u';
    }
    else if(!strcmp(str, "...-")){
        result = 'v';
    }
    else if(!strcmp(str, ".--")){
        result = 'w';
    }
    else if(!strcmp(str, "-..-")){
        result = 'x';
    }
    else if(!strcmp(str, "-.--")){
        result = 'y';
    }
    else if(!strcmp(str, "--..")){
        result = 'z';
    }
    
    return result;
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* letter) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int space_cnt = 0;
    int idx = 0;
    
    // 공백으로 결과자리수 계산
    for(int i = 0;i < strlen(letter);i++){
        if(letter[i] == ' '){
            space_cnt++;
        }
    }
    
    // strtok로 모스부호 : 문자 맵핑
    char* answer = (char*)malloc(space_cnt + 2);    
    char* ptr = strtok(letter, " ");
    while (ptr != NULL){
        answer[idx++] = get_morse(ptr); 
        ptr = strtok(NULL, " ");
    }
    
    answer[space_cnt + 1] = '\0';
    
    return answer;
}