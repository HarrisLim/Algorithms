package baekjoon;

/*
	[파도반 수열]
	
	문제: 오른쪽 그림과 같이 삼각형이 나선 모양으로 놓여져 있다. 첫 삼각형은 정삼각형으로 변의 길이는 1이다.
		그 다음에는 다음과 같은 과정으로 정삼각형을 계속 추가한다.
		나선에서 가장 긴 변의 길이를 k라 했을 때, 그 변에 길이가 k인 정삼각형을 추가한다.
		파도반 수열 P(N)은 나선에 있는 정삼각형의 변의 길이이다.
		P(1)부터 P(10)까지 첫 10개 숫자는 1, 1, 1, 2, 2, 3, 4, 5, 7, 9이다.
		N이 주어졌을 때, P(N)을 구하는 프로그램을 작성하시오.
		(* 그림은 백준사이트 참고)
	
	입력: 첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, N이 주어진다. (1 ≤ N ≤ 100)
	
	출력: 각 테스트 케이스 마다 P(N)을 출력한다.
*/

import java.io.*;

class Padoban {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int t, n;
	long dp[] = new long[101];

	Padoban(){
		try{
			t = Integer.parseInt(br.readLine());
		}catch(IOException ie){}
	}
	void input(){
		try{
			n = Integer.parseInt(br.readLine());
			for(int i=1; i<dp.length; i++) {
				if(i<4) dp[i]=1;
				if(i>=4&&i<6) dp[i]=2;
				if(i==6) dp[i]=3;
				if(i==7) dp[i]=4;
				if(i==8) dp[i]=5;
				if(i==9) dp[i]=7;
				if(i==10) dp[i]=9;
			}
		}catch(IOException ie){}
	}
	long loop(){
		if(n<=10) return dp[n];
		else if (dp[n]!=0) return dp[n];
		else {
			for(int i=11; i<=n; i++) {
				dp[i] = dp[i-5]+dp[i-1];
				if(i==n) break;
			}
		}
		return dp[n];
	}
	void play() {
		while(t-->0){
			input();
			System.out.println(loop()); 
		}
	}
}

class Main {
	public static void main(String[] args) {
		Padoban main = new Padoban();
		main.play();
	}
}

/*		
		한 줄 정리
	문제에 주어진대로 10까지 먼저 입력을 하고, 해당 dp[index-4] + [index-1]하면 값을 구할 수 있다.
	이게 bottom-up 방식인가 ?
*/