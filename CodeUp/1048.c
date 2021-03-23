/* 1048: [기초-비트시프트연산] 한 번에 2의 거듭제곱 배로 출력하기

  - 문제: 정수 2개(a, b)를 입력받아 a를 2b배 곱한 값으로 출력해보자.
         0 <= a <= 10, 0 <= b <= 10

         참고
         예를 들어 1 3 이 입력되면 1을 23(8)배 하여 출력한다.

         예시
         int a=1, b=10;
         printf("%d", a << b); //210 = 1024 가 출력된다.

  - 입력: 정수 2개가 공백을 두고 입력된다.
         0 <= a, b <= 10

  - 출력: a 를 2b배 만큼 곱한 값을 출력한다.

  - 내 의견:
 
 */
#include <stdio.h>

int main(int argc, const char * argv[]) {
    long a, b;
    scanf("%ld %ld", &a, &b);
    printf("%ld", a<<b);
    return 0;
}
