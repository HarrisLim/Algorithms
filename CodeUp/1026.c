/* 1026: [기초-입출력] 시분초 입력받아 분만 출력하기

  - 문제: 입력되는 시:분:초 에서 분만 출력해보자.
 
         참고
         int h, m, s;
         scanf("%d:%d:%d", &h, &m, &s);

         를 실행하면 콜론을 사이에 둔 형식으로 입력되어, h, m, s에 각각 정수값만 저장된다.

  - 입력: 시 분 초가
         시:분:초 형식으로 입력된다.
 
  - 출력: 분만 출력한다.

  - 내 의견:
 
 */
#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    int h,m,s;
    scanf("%d:%d:%d", &h,&m,&s);
    
    printf("%d", m);
    return 0;
}

