#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numlist_len은 배열 numlist의 길이입니다.
int* solution(int numlist[], size_t numlist_len, int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(numlist_len * sizeof(int));
    int idx = 0, num_high = 0, num_low = 0, idx_high = 0, idx_low = 0;
    
    // n 기준 갯수 카운트
    for(int i = 0;i < numlist_len;i++){
        if(numlist[i] > n){
            num_high++;
        }
        else if(numlist[i] < n){
            num_low++;
        }
        else{
            answer[idx++] = n;      // 같은 숫자가 있으면 처음에 위치
        }
    }
    
    // n 기준 배열 생성
    int* arr_high = (int*)malloc(num_high * sizeof(int));
    int* arr_low = (int*)malloc(num_low * sizeof(int));
    
    for(int i = 0;i < numlist_len;i++){
        if(numlist[i] > n){
            arr_high[idx_high++] = numlist[i];
        }
        if(numlist[i] < n){
            arr_low[idx_low++] = numlist[i];
        }
    }
    
    // n보다 큰 배열의 오름차순 정렬
    int min = 0;
    for(int i = 0;i < num_high - 1;i++){
        min = i;
        for(int j = i + 1;j < num_high;j++){
            if(arr_high[min] > arr_high[j]){
                min = j;
            }
        }
        
        int temp = arr_high[i];
        arr_high[i] = arr_high[min];
        arr_high[min] = temp;
    }   
       
    // n보다 작은 배열의 내림차순 정렬
    int max = 0;
    for(int i = 0;i < num_low - 1;i++){
        max = i;
        for(int j = i + 1;j < num_low;j++){
            if(arr_low[max] < arr_low[j]){
                max = j;
            }
        }
        
        int temp = arr_low[i];
        arr_low[i] = arr_low[max];
        arr_low[max] = temp;
    }
    
    // 원소 삽입
    int idx_h = 0, idx_l = 0;
    for(int i = idx;i < numlist_len;i++){
        if(idx_h == num_high){
            answer[i] = arr_low[idx_l++];           // 큰 쪽이 모두 들어간 경우 나머지는 낮은 쪽
        }
        else if(idx_l == num_low){
            answer[i] = arr_high[idx_h++];          // 낮은 쪽이 모두 들어간 경우 나머지는 큰 쪽
        }
        else{
            int gap_h = arr_high[idx_h] - n;
            int gap_l = n - arr_low[idx_l];

            if(gap_h <= gap_l){
                answer[i] = arr_high[idx_h++];      // 거리가 같거나 작은 경우 큰 수가 옴
            }
            else{
                answer[i] = arr_low[idx_l++];       // 거리가 작은 애가 옴
            }
        }
    }
    
    free(arr_high);
    free(arr_low);
    
    return answer;
}