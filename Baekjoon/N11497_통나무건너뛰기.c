/* 11497: 통나무 건너뛰기

  - 문제: 남규는 통나무를 세워 놓고 건너뛰기를 좋아한다. 그래서 N개의 통나무를 원형으로 세워 놓고 뛰어놀려고 한다. 남규는 원형으로 인접한 옆 통나무로 건너뛰는데, 이때 각 인접한 통나무의 높이 차가 최소가 되게 하려 한다.
         통나무 건너뛰기의 난이도는 인접한 두 통나무 간의 높이의 차의 최댓값으로 결정된다. 높이가 {2, 4, 5, 7, 9}인 통나무들을 세우려 한다고 가정하자. 이를 [2, 9, 7, 4, 5]의 순서로 세웠다면, 가장 첫 통나무와 가장 마지막 통나무 역시 인접해 있다. 즉, 높이가 2인 것과 높이가 5인 것도 서로 인접해 있다. 배열 [2, 9, 7, 4, 5]의 난이도는 |2-9| = 7이다. 우리는 더 나은 배열 [2, 5, 9, 7, 4]를 만들 수 있으며 이 배열의 난이도는 |5-9| = 4이다. 이 배열보다 난이도가 낮은 배열은 만들 수 없으므로 이 배열이 남규가 찾는 답이 된다.
 
  - 입력: 입력은 T개의 테스트 케이스로 이루어져 있다. 첫 줄에 T가 주어진다.
 
         이어지는 각 줄마다 첫 줄에 통나무의 개수를 나타내는 정수 N(5 ≤ N ≤ 10,000), 둘째 줄에 각 통나무의 높이를 나타내는 정수 Li가 주어진다. (1 ≤ Li ≤ 100,000)

  - 출력: 각 테스트 케이스마다 한 줄에 주어진 통나무들로 만들 수 있는 최소 난이도를 출력하시오.
  
  - 내 의견: 몇 날 며칠을 해서 드디어 풀었다. 성취감이 아주 좋군하 ㅎㅎ
           성공률 59%라고 만만히 봤는데, 내 실력이 만만했다..
           규칙 파악이 중요하다. 센스있게 많이 풀다보면 실력이 늘 것이다 !!!
 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a ,const void *b);

int main(int argc, const char * argv[]) {
    int T, N, cnt;
    int Li[100000] = {};
    int tmpLi[100000] = {};
    int max[10000] = {};
    cnt = 0;
    scanf("%d", &T);
    
    while(T--)
    {
        int level=1;
        memset(Li, 0x00, sizeof(Li));
        memset(tmpLi, 0x00, sizeof(tmpLi));
        scanf("%d", &N);
        
        for(int i=0; i<N; i++)
            scanf("%d", &Li[i]);
        
        qsort(Li, N+1 / sizeof(int), sizeof(int), compare);
        
        for(int i=0; i<=N/2; i++)
        {
            if (i==0)
                tmpLi[N/2] = Li[N-1];
            else
            {
                tmpLi[(N/2)-i] = Li[N-(i+level)];
                level++;
                tmpLi[(N/2)+i] = Li[N-(i+level)];
            }
        }
        
        int temp=0;
        for(int i=0; i<N; i++)
        {
            if(i==N-1)
            {
                if ( abs(tmpLi[i] - tmpLi[0]) > temp)
                    temp = abs(tmpLi[i] - tmpLi[0]);
            }
            else
            {
                if ( abs(tmpLi[i] - tmpLi[i+1]) > temp)
                {
                    temp = abs(tmpLi[i] - tmpLi[i+1]);
                }
            }
        }
        
        max[cnt] = temp;
        cnt++;
    }
    
    for(int i=0; i<cnt; i++)
        printf("%d\n",max[i]);
        
    return 0;
}

int compare(const void *a ,const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    
    if(num1 < num2)
        return -1;
    
    if(num1 > num2)
        return 1;
    
    return 0; // num == num1은 0 리턴
}
