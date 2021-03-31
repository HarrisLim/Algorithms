/* 1014: [기초-입출력] 문자 2개 입력받아 순서 바꿔 출력하기(설명)

   - 문제: 2개의 문자(ASCII CODE)를 입력받아서 순서를 바꿔 출력해보자.
 
          참고
          char x, y;
          scanf("%c %c", &x, &y);
          printf("%c %c", y, x); //출력되는 순서를 작성
          와 같은 방법으로 해결할 수 있다.

 
    - 입력: 2개의 문자가 공백으로 구분되어 입력된다.

 
    - 출력: 두 문자의 순서를 바꿔 출력한다.
 
    - 내 의견: 정수는 scanf에서 %d%d 이렇게 붙여서 써도 되지만, 문자는 %c %c 처럼 중간에 공백을 주어야 한다.
 
 */
#include <stdio.h>

int main(int argc, const char * argv[]) {
    char a, b;
    scanf("%c %c", &a, &b);
    printf("%c %c", b, a);
    return 0;
}

