package baekjoon;
/*
	[가장 긴 증가하는 부분 수열]
	
	문제: 수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
		예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에
		가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

	입력: 첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.
		둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

	출력: 첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.
*/

import java.io.*;
import java.util.*;

class TheLongestSequence {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int n;
	int max;
	int[] a;
	int memo[];
	
	TheLongestSequence(){
		try {
			n = Integer.parseInt(br.readLine());
			String line = br.readLine();
			StringTokenizer st = new StringTokenizer(line, " ");
			a = new int[n];
			memo = new int[n];
			for(int i=0; i<n; i++) {
				a[i] = Integer.parseInt(st.nextToken());
				memo[i] = 1;
			}
		}catch(IOException ie) {}
	}
	void loop() {
		for(int i=1; i<n; i++)
			for(int j=0; j<i; j++)
				if(a[i] > a[j] && memo[i] < memo[j] + 1)
					memo[i] = memo[j]+1;
	}
	void play() {
		loop();
		for(int z: memo)
			max = Math.max(max, z);
		System.out.println(max);

	}
}

class Main{
	public static void main(String[] args) {
	  new TheLongestSequence().play();
	}
}

/*
		한 줄 정리
	가장 큰 증가부분수열을 풀면서 lis에 대해 알아보고 나서 공식으로 푸니까 술술 풀린다. 
	
	먼저, dp배열을 하나 만들어서 입력받은 수열을 저장하는 a[]처럼 memo[]에도 값을 똑같이 저장을 한다.
	그리고 이중 for문을 돌리는데, 밑에 처럼 돌린다. 밑에 처럼 돌리면 어떤식으로 검사를 할 수 있는지 밑을 확인하자. 
		for i=1 < n
			for j=0 < i
				if a[i] > a[j] && memo[i] < memo[j] + 1
					memo[i] = memo[j] + 1
	10 20 10 30 20 50을 입력받고 위의 코드를 돌리면 
	
	      idx     |  1  |  2  |  3  |  4  |  5  |  6  |
	      a[i]    |  10 |  20 |  10 |  30 |  20 |  50 | 
	  초기 memo[i] |   1 |   1 |   1 |   1 |   1 |   1 |
	  최종 memo[i] |   1 |   2 |   1 |   2 |   2 |   3 |
	                                    3           4    
	위와 같이 값이 최종 memo[i]에 저장된다. 
	현재까지 구한 수가 이전에 구했던 값보다 크다면 memo[i]를 갱신하면서 큰 수를 찾는다. 
*/