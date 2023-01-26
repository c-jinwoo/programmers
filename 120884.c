#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int chicken) {
    int answer = 0;
    int coupon = chicken;
    int service = 0;
    
    while(coupon / 10){
        service = coupon / 10;              // 10장 당 1마리 서비스
        coupon = coupon % 10 + service;     // 현재 남은 쿠폰은 사용전 1자리수 + 서비스 치킨 수
        answer += service;                  // 서비스로 받은 치킨 수 기록
    }
    
    return answer;
}