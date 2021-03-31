package baekjoon;
/*
	[RGB거리]
	
	문제: RGB거리에 사는 사람들은 집을 빨강, 초록, 파랑중에 하나로 칠하려고 한다. 또한, 그들은 모든 이웃은 같은 색으로 칠할 수 없다는 규칙도 정했다.
		집 i의 이웃은 집 i-1과 집 i+1이다. 처음 집과 마지막 집은 이웃이 아니다.
		각 집	을 빨강으로 칠할 때 드는 비용, 초록으로 칠할 때 드는 비용, 파랑으로 드는 비용이 주어질 때,
		모든 집을 칠할 때 드는 비용의 최솟값을 구하는 프로그램을 작성하시오.
		
	입력: 첫째 줄에 집의 수 N이 주어진다. N은 1,000보다 작거나 같다. 둘째 줄부터 N개의 줄에 각 집을 빨강으로 칠할 때,
		초록으로 칠할 때, 파랑으로 칠할 때 드는 비용이 주어진다. 비용은 1,000보다 작거나 같은 자연수이다.
	
	출력: 첫째 줄에 모든 집을 칠할 때 드는 비용의 최솟값을 출력한다.
*/

import java.io.*;
import java.util.*;

class RGBStreet {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int n;
	int[][] arr;
	int[][] dp;
	
	RGBStreet(){
		try {
			n = Integer.parseInt(br.readLine());
		}catch(IOException ie) {}
	}
	void input() {
		try {
			arr = new int[n+1][3];
			dp = new int[n+1][3];
			for(int j=0; j<n; j++) {
				String line = br.readLine();
				StringTokenizer st = new StringTokenizer(line, " ");
				for(int i=0; i<3; i++) {
					arr[j][i] = Integer.parseInt(st.nextToken());
				}
			}
		}catch(IOException ie) {}
	}
	void loop() {
		dp[0][0] = arr[0][0];
		dp[0][1] = arr[0][1];
		dp[0][2] = arr[0][2];
		for(int i=1; i<=n; i++) {
			dp[i][0] = Math.min(dp[i-1][1], dp[i-1][2]) + arr[i][0];
			dp[i][1] = Math.min(dp[i-1][0], dp[i-1][2]) + arr[i][1];
			dp[i][2] = Math.min(dp[i-1][0], dp[i-1][1]) + arr[i][2];
		}
	}
	int checkMin() {
		int min = dp[n][0];
		for(int i=0; i<3; i++) {
			min = Math.min(dp[n][i], min);
		}
		return min;
	}
	void play() {
		input();
		loop();
		System.out.println(checkMin());
	}
}

class Main{
	public static void main(String[] args) {
	  new RGBStreet().play();
	}
}

/*
		한 줄 정리
	전에 푼 스티커와 유사한 문제다. 사실 거의 똑같은 문제라고 생각이 된다. 
	
	3개의 색을 입력받는다. 
	빨간색, 초록색, 파란색. 
	최소의 비용을 구하는 것인데, 앞의 집과 뒷집은 같은 색으로 칠하면 안되고, 첫집과 마지막집 끼리는 비교하지 않는다. 
	그러면 이렇게 생각하면 된다. 
	  1. 현재 집에 빨간색을 칠해야 한다면, 전 집의 초록색, 파란색 중에 최소값을 찾아서 현재 값을 더한다.  
	  2. 현재 집에 초록색을 칠해야 한다면, 전 집의 빨간색, 파란색 중에 최소값을 찾아서 현재 값을 더한다.
	  3. 현재 집에 파란색을 칠해야 한다면, 전 집의 빨간색, 초로록색 중 최소값을 찾아서 현재 값을 더한다. 
	그리고 마지막에서 최소값을 구하면 된다. 
	이 패턴대로 DP문제가 많은 것 같다. 까먹지말자 !   
*/