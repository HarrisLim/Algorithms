package baekjoon;
/*
	[가장 큰 증가 부분 수열]
	
	문제: 수열 A가 주어졌을 때, 그 수열의 증가 부분 수열 중에서 합이 가장 큰 것을 구하는 프로그램을 작성하시오.
		예를 들어, 수열 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 인 경우에
		합이 가장 큰 증가 부분 수열은 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 이고, 합은 113이다.

	입력: 첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.
		둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

	출력: 첫째 줄에 수열 A의 합이 가장 큰 증가 부분 수열의 합을 출력한다.
*/

import java.io.*;
import java.util.*;

class TheBiggestSequence {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int n;
	int max;
	int[] a;
	int memo[];
	
	TheBiggestSequence(){
		try {
			n = Integer.parseInt(br.readLine());
			String line = br.readLine();
			StringTokenizer st = new StringTokenizer(line, " ");
			a = new int[n];
			memo = new int[n];
			for(int i=0; i<n; i++) {
				a[i] = Integer.parseInt(st.nextToken());
				memo[i] = a[i];
			}
			// memo = a; // 이렇게 배열을 복사하면 해당 주소값이 복사되어 a[3] =99; 로 수정하면 memo[3]의 값도 99가 된다. 주의하자. 
		}catch(IOException ie) {}
	}
	void loop() {
		for(int i=1; i<n; i++)
			for(int j=0; j<i; j++)
				if(a[i] > a[j] && memo[i] < memo[j] + a[i])
					memo[i] = memo[j] + a[i];
	}
	void play() {
		// 시간검사 코드 
//		long startTime = System.currentTimeMillis();
		
		loop();
		for(int z: memo)
			max = Math.max(max, z);
		System.out.println(max);

		// 시간검사 코드 
//		long endTime = System.currentTimeMillis();
//		long lTime = endTime - startTime;
//		System.out.println("TIME : " + lTime + "(ms)");
	}
}

class Main{
	public static void main(String[] args) {
	  new TheBiggestSequence().play();
	}
}

/*
		한 줄 정리
	수열에 관한 것은 LCS만 있는 줄 알았는데, LIS(Longest Increasing Subsequence)도 있다. 배우자 ! 
	시간초과가 난 코드로 푼 것은 제공해주는 테스트케이스를 입력했을 때 약 10(ms)가 나왔는데, lis 공식대로 푸니까 1(ms)가 나온다.. 
	
	먼저, dp배열을 하나 만들어서 입력받은 수열을 저장하는 a[]처럼 memo[]에도 값을 똑같이 저장을 한다.
	그리고 이중 for문을 돌리는데, 밑에 처럼 돌린다. 밑에 처럼 돌리면 어떤식으로 검사를 할 수 있는지 밑을 확인하자. 
		for i=1 < n
			for j=0 < i
				if a[i] > a[j] && memo[i] < memo[j] + a[i]
					memo[i] = memo[j] + a[i]
	10 20 10 30 20 50을 입력받고 위의 코드를 돌리면 
	
	      idx     |  1  |  2  |  3  |  4  |  5  |  6  |
	      a[i]    |  10 |  20 |  10 |  30 |  20 |  50 | 
	  초기 memo[i] |  10 |  20 |  10 |  30 |  20 |  50 |
	  최종 memo[i] |  10 |  30 |  10 |  40 |  30 |  60 |
	                                   60          80    
	                                              110
	위와 같이 값이 최종 memo[i]에 저장된다. 
	현재까지 더한 값이 이전에 구했던 값보다 크다면 memo[i]를 갱신하면서 큰 값을 찾는다. 

/*
		시간초과 나온 내 코드
	밑에 처럼 하면 수열의 갯수 만큼 돌아서 O(!수열의 개수)가 된다고 한다. 아직 배울것이 한참 많다. 
	
	void loop(int s, int ri) { // s: 큰 값이 나오면 변경되는 idx(수열일 때), ri: 시작 idx 
		if(a[s]==a[n-2]) return;
		for(int i=s; i<a.length; i++) {
			memo[i] = 1;
			if(a[s] < a[i]) {
				max+=a[i];
				loop(i, ri);
			}
		}
		king = Math.max(max, king);
		max=a[ri];
	}
	
	void play(){
		for(int i=0; i<a.length; i++) { // 0 ~ n-1까지 돌면서 한 칸씩 오른 쪽으로 밀면서 검사.   
			max=a[i];
			loop(i, i);
		}
	}
*/