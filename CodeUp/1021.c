/* 1021: [기초-입출력] 단어 1개 입력받아 그대로 출력하기

    - 문제: 1개의 단어를 입력받아 그대로 출력해보자.
 
    - 입력: 한 단어가 입력된다.(단, 단어의 길이는 50자 이하이다.)
 
          문자를 50개 저장하기 위해서는 char data[51] 로 선언하면 된다.

          char data[51]="";
          scanf("%s", data);

          를 실행하면, data[51] 에 한 단어가 저장된다.

    - 출력: 입력된 단어를 그대로 출력한다.

    - 내 의견: 문자열은 이미 포인터로 주소값을 가르키기 떄문에, scanf에서 &data로 주소값을 가르키지 않아도 된다.
 
 */
#include <stdio.h>

int main(int argc, const char * argv[]) {
    char data[50+1];
    scanf("%s", data);
    printf("%s", data);
    return 0;
}

