/* 1045: [기초-산술연산] 정수 2개 입력받아 자동 계산하기

  - 문제: 정수 2개(a, b)를 입력받아 합, 차, 곱, 몫, 나머지, 나눈 값을 자동으로 계산해보자.
         단 0 <= a, b <= 2147483647, b는 0이 아니다.

  - 입력: 정수 2개가 공백을 두고 입력된다.

  - 출력: 첫 줄에 합
         둘째 줄에 차,
         셋째 줄에 곱,
         넷째 줄에 몫,
         다섯째 줄에 나머지,
         여섯째 줄에 나눈 값을 순서대로 출력한다.
         (실수, 소수점 이하 셋째 자리에서 반올림해 둘째 자리까지 출력)

  - 내 의견:
 
 */
#include <stdio.h>

int main(int argc, const char * argv[]) {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    printf("%lld\n%lld\n%lld\n%lld\n%lld\n%.2f", a + b
                       , a - b
                       , a * b
                       , a / b
                       , a % b
                       , (float)a / (float)b);
    return 0;
}
