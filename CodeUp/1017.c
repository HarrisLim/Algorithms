/* 1017: [기초-입출력] 정수 1개 입력받아 3번 출력하기(설명)

   - 문제: int형 정수 1개를 입력받아 공백을 사이에 두고 3번 출력해보자.
 
          참고
          printf("%d %d %d", a, a, a);
          와 같은 방법으로 출력할 수 있다.
 
    - 입력: 정수 1개가 입력된다.

    - 출력: 입력받은 정수를 공백으로 구분해 3번 출력한다.

    - 내 의견:
 
 */
#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a;
    scanf("%d", &a);
    printf("%d %d %d", a, a, a);
    return 0;
}

