/* 1066: [기초-조건/선택실행구조] 정수 3개 입력받아 짝/홀 출력하기

  - 문제: 세 정수 a, b, c가 입력되었을 때, 짝(even)/홀(odd)을 출력해보자.
 
         참고
         if(조건)
         { //코드블록1 시작
           ... 실행...;
           ...
         }
         else
         { //코드블록2 시작
           ... 다른실행...;
           ...
         }
         의 조건/선택 실행구조는 주어진 “조건”을 검사해 참인 경우에는 코드블록1을 실행하고,
         거짓인 경우에는 코드블록2를 실행한다.

         예시
         if(a%2==0)
         {
           printf(“%s”, “even”);
         }
         else
         {
           printf(“%s”, “odd”);
         }

         ** else는 if 없이 혼자 사용되지 않는다. 또한, else 다음에 조건이 없는 이유는?
         참이 아니면 거짓이고, 거짓이 아니면 참이기 때문에...
         즉 if문의 조건식의 판별 결과는 2가지 경우(참 또는 거짓)로 계산되는데,
         else 부분은 if문의 조건식의 결과가 거짓인 경우에 해당하기 때문이다.

         ** 실행해야 할 명령들이 여러 개일 때 코드블록 기호 { }로 묶어 주는데,
         코드블록의 내용이 논리적으로 1개 단위라면 코드블록 기호를 생략할 수 있다.

         if(a%2==0) printf("%s", "even");
         else printf("%s", "odd");

  - 입력: 세 정수 a, b, c 가 공백을 두고 입력된다.
         0 <= a, b, c <= +2147483647

  - 출력: 입력된 순서대로 짝(even)/홀(odd)을 줄을 바꿔 출력한다.

  - 내 의견:
 
 */
#include <stdio.h>

int main(int argc, const char * argv[]) {
    long a, b, c;
    scanf("%ld %ld %ld", &a, &b, &c);
        
    if (a % 2 == 0)
        printf("even\n");
    else
        printf("odd\n");
    
    if (b % 2 == 0)
        printf("even\n");
    else
        printf("odd\n");
        
    if (c % 2 == 0)
        printf("even\n");
    else
        printf("odd\n");
    
    return 0;
}
