/* 1025: [기초-입출력] 정수 1개 입력받아 나누어 출력하기

  - 문제: 다섯 자리의 정수 1개를 입력받아 각 자리별로 나누어 출력한다.
 
         참고
         scanf("%1d%1d%1d%1d%1d", &a, &b, &c, &d, &e);
         를 사용하면 1개의 숫자로 각각 구분되어 저장된다.

         예시
         읽어들인 값을 적당히 바꿔 출력하기 위해서

         printf("[%d]", a*10000);

         과 같은 방법도 가능하다.

  - 입력: 다섯 자리로 이루어진 1개의 정수를 입력받는다.
         (단, 10,000 <= 입력받는 수 <= 99,999 )
 
  - 출력: 각 자리의 숫자를 분리해 한 줄에 하나씩 [ ]속에 넣어 출력한다.

  - 내 의견: 재밌다..
 
 */
#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    char str[5+1];
    int a, b, leng;
    b = 0;
    scanf("%d", &a);
    sprintf(str, "%d", a);
    leng = (int)strlen(str);
    
    for(int i = leng; i > 0; i--)
    {
        printf("[%c", str[b]);
        for(int j = i; j > 1; j--)
            printf("%c", '0');
        b++;
        printf("]\n");
    }
    return 0;
}

