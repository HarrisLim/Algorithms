/* 1040: [기초-산술연산] 정수 1개 입력받아 부호 바꿔 출력하기

  - 문제: 입력된 정수의 부호를 바꿔 출력해보자.
         단, -2147483647 ~ +2147483647 범위의 정수가 입력된다.

         참고
         단항 연산자인 -(negative)를 변수 앞에 붙이면 부호가 반대로 바뀌어 계산된다.

         예시
         int a;
         scanf("%d", &a);
         printf("%d", -a);

  - 입력: 정수 1개가 입력된다.

  - 출력: 부호를 바꿔 출력한다.

  - 내 의견:
 
 */
#include <stdio.h>

int main(int argc, const char * argv[]) {
    long long a;
    scanf("%lld", &a);
    printf("%lld", -a);
    return 0;
}

