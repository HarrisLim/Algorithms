package baekjoon;

/*
	[이항 계수2]
	
	문제: 자연수 N과 정수 K가 주어졌을 때 이항 계수 nCk를 10,007구하는 프로그램을 작성하시오.
	
	입력: 첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ K ≤ N)
	
	출력: nCk를 10,007로 나눈 나머지를 출력한다.
*/

import java.util.*;
import java.io.*;

class Binomial2 {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int n, k;
	int dp[][] = new int[1001][1001];
	
	Binomial2() {
		try {
			String line = br.readLine();
			StringTokenizer st = new StringTokenizer(line, " ");
			n = Integer.parseInt(st.nextToken());
			k = Integer.parseInt(st.nextToken());
		}catch(IOException ie) {}
	}
	int loop(int a, int b){
		if(a==b || b==0) return 1;
		if(dp[a][b]!=0) return dp[a][b];
		else dp[a][b] = (loop(a-1, b)%10007 + loop(a-1, b-1)%10007)%10007;
		return dp[a][b];
	}
	void play() {
		System.out.println(loop(n, k));
	}
}

class Main {
	public static void main(String[] args) {
		Binomial2 main = new Binomial2();
		main.play();
	}
}

/*		
		한 줄 정리
	이항계수는 nCk일 때, n개 중에서 k개를 선택할 수 있는 경우의 수를 구하는 것이다. 
	처음에 그냥 play()에서 loop()값에 %10007을 했는데, 틀렸다.
	찾아봤더니, loop(a-1, b)에 %10007을 해주고 loop(a-1, b-1)에도 %10007을 해주고, 
	그 둘을 더한 값에도 %10007을 해줘야한다.
	
	위의 문제의 출력을 보면 nCk를 10,007로 나눈 나머지를 출력하라고 하는데, 
	맨 마지막에 play()에서 구해진 값이 nCk가 아니고, loop()내에서 loop()가 return된 값을 말하는 것 같다. 
*/