/* 1010 : [기초-입출력] 정수 1개 입력받아 그대로 출력하기(설명)

   - 문제: 정수형(int)으로 변수를 선언하고, 변수에 정수값을 저장한 후
          변수에 저장되어 있는 값을 그대로 출력해보자.

          예시
          int main()
          {
              int n;
              scanf("%d", &n);
              printf("%d", n);

              return 0;
          }
          와 같은 형태로 가능하다.
 
    - 입력: 정수 1개가 입력된다.
 
    - 출력: 입력된 정수를 그대로 출력한다.
 
 */
#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a;
    scanf("%d", &a);
    printf("%d", a);
    return 0;
}
