#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int getGCD(int a, int b){
    int c;
    
	while(b){
		c = a % b;
		a = b;
		b = c;
	}
    
    return a;
}

int* solution(int numer1, int denom1, int numer2, int denom2) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(2 * sizeof(int));
    
    int gcd = getGCD(denom1, denom2);
    int new_denom = denom1 * denom2 / gcd;
    int new_numer = numer1 * new_denom / denom1 + numer2 * new_denom / denom2;    
    int new_gcd = getGCD(new_numer, new_denom);
    
    answer[0] = new_numer / new_gcd;
    answer[1] = new_denom / new_gcd;
    
    return answer;
}