/* 1031: [기초-출력변환] 10진 정수 1개 입력받아 8진수로 출력하기

  - 문제: 10진수를 입력받아 8진수(octal)로 출력해보자.
 
         참고
         %d(10진수 형태)로 입력받고,
         %o를 사용해 출력하면 8진수(octal)로 출력된다.

  - 입력: 10진수 1개가 입력된다.
         단, 입력되는 정수는 int 범위이다.

  - 출력: 8진수로 출력한다.

  - 내 의견:
 
 */
#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a;
    scanf("%d", &a);
    
    printf("%o", a);
    return 0;
}

