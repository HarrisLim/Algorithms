/* 1097: [기초-2차원배열] 바둑알 십자 뒤집기

  - 문제: 부모님을 기다리던 영일이는 검정/흰 색 바둑알을 바둑판에 꽉 채워 깔아 놓고 놀다가...
 
         "십(+)자 뒤집기를 해볼까?"하고 생각했다.

         바둑판(19 * 19)에 흰 돌(1) 또는 검정 돌(0)이 모두 꽉 채워져 놓여있을 때,
         n개의 좌표를 입력받아 십(+)자 뒤집기한 결과를 출력하는 프로그램을 작성해보자.

  - 입력: 바둑알이 깔려 있는 상황이 19 * 19 크기의 정수값으로 입력된다.
         십자 뒤집기 횟수(n)가 입력된다.
         십자 뒤집기 좌표가 횟수(n) 만큼 입력된다. 단, n은 10이하의 자연수이다.

  - 출력: 십자 뒤집기 결과를 출력한다.
 
  - 내 의견: 투입하는 입력값을 작게 생각난 후, 크게 생각하자
 
 */
#include <stdio.h>

int main(int argc, const char * argv[]) {
    long n, x, y;
    int stone;
    
    long arr[19+1][19+1] = {};
    
    for(int i=0; i < 19; i++)
    {
        for(int j=0; j < 19; j++)
        {
            scanf("%d", &stone);
            arr[i][j] = stone;
        }
    }
    
    scanf("%ld", &n);
    
    for(int i=0; i<n; i++)
    {
        scanf("%ld %ld", &x, &y);
        x--;
        y--;
        
        for(int j=0; j<19; j++)
        {
            if(arr[x][j] == 0) arr[x][j] = 1;
            else arr[x][j] = 0;
            
            if(arr[j][y] == 0) arr[j][y] = 1;
            else arr[j][y] = 0;
        }
    }
    
    for(int i=0 ; i < 19 ; i++)
    {
        for(int j=0; j < 19; j++)
        {
            printf("%ld ", arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
