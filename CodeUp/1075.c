/* 1075: [기초-반복실행구조] 정수 1개 입력받아 카운트다운 출력하기2

  - 문제: 정수(1 ~ 100) 1개가 입력되었을 때 카운트다운을 출력해보자.
 
     예시
     int n;
     scanf("%d", &n);
     while(n!=0)
     {
       n=n-1; //n--; 와 같다.
       printf("%d", n);
     }

  - 입력: 정수 1개가 입력된다.
         (1 ~ 100)

  - 출력: 1씩 줄이면서 한 줄에 하나씩 0이 될 때까지 출력한다.

  - 내 의견:
 
 */
#include <stdio.h>

int main(int argc, const char * argv[]) {
    long n;
    scanf("%ld", &n);
    while(n!=0)
    {
        printf("%ld\n", --n);
    }
    
    return 0;
}
