package baekjoon;
/*
	[스티커]
	
	문제: 상근이의 여동생 상냥이는 문방구에서 스티커 2n개를 구매했다.
		스티커는 그림 (a)와 같이 2행 n열로 배치되어 있다. 상냥이는 스티커를 이용해 책상을 꾸미려고 한다.
		상냥이가 구매한 스티커의 품질은 매우 좋지 않다. 스티커 한 장을 떼면, 그 스티커와 변을 공유하는 스티커는 모두 찢어져서 사용할 수 없게 된다.
		즉, 뗀 스티커의 왼쪽, 오른쪽, 위, 아래에 있는 스티커는 사용할 수 없게 된다.
		모든 스티커를 붙일 수 없게된 상냥이는 각 스티커에 점수를 매기고, 점수의 합이 최대가 되게 스티커를 떼어내려고 한다.
		먼저, 그림 (a)와 같이 각 스티커에 점수를 매겼다. 상냥이가 뗄 수 있는 스티커의 점수의 최대값을 구하는 프로그램을 작성하시오.
		즉, 2n개의 스티커 중에서 점수의 합이 최대가 되면서 서로 변을 공유 하지 않는 스티커 집합을 구해야 한다.
		위의 그림의 경우에 점수가 50, 50, 100, 60인 스티커를 고르면, 점수는 260이 되고 이 것이 최대 점수이다.
		가장 높은 점수를 가지는 두 스티커 (100과 70)은 변을 공유하기 때문에, 동시에 뗄 수 없다.
		
			30 | 10 | 100 | 20 | 40
			-----------------------
			30 | 50 |  70 | 10 | 60
		
	입력: 입력은 최대 1000개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 한 줄이며, 병에 들어있는 약의 개수 N ≤ 30 가 주어진다.
		입력의 마지막 줄에는 0이 하나 주어진다.
	
	출력: 각 테스트 케이스에 대해서 가능한 문자열의 개수를 출력한다.
*/

import java.io.*;
import java.util.*;

class Sticker {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int t, n;
	int[][] arr;
	int[][] dp;
	
	Sticker(){
		try {
			t = Integer.parseInt(br.readLine());
		}catch(IOException ie) {}
	}
	void input() {
		try {
			n = Integer.parseInt(br.readLine());
			arr = new int [3][100002];
			dp = new int [3][100002];
			int x=1;
			while(x<3) {
				String line = br.readLine();
				StringTokenizer st = new StringTokenizer(line, " ");
				for(int i=1; i<=n; i++) {
					arr[x][i] = Integer.parseInt(st.nextToken());
				}
				x++;
			}
		}catch(IOException ie) {}
	}
	void loop() {
		for(int i=1; i<=n; i++) {
			dp[0][i] = Math.max(dp[0][i-1], Math.max(dp[1][i-1], dp[2][i-1]));
			dp[1][i] = Math.max(dp[2][i-1], dp[0][i-1]) + arr[1][i];
			dp[2][i] = Math.max(dp[1][i-1], dp[0][i-1]) + arr[2][i];
		}
	}
	int checkMax() {
		int max =0;
		for(int i=1; i<=2; i++)
			for(int j=n; j<=n+1; j++)
				max = Math.max(dp[i][j], max);
		return max;
	}
	void play() {
		while(t-->0) {
			input();
			loop();
			System.out.println(checkMax());
		}
	}
}

class Main{
	public static void main(String[] args) {
	  new Sticker().play();
	}
}

/*
		한 줄 정리
	이것도 스티커, 포도주시식같은 문제와 비슷하게 풀었다. 사실 완벽하게는 내가 못풀었고 창현님의 설명을 참고했다. 
	무조건 2행으로만 들어와서 1행을 추가한 3행으로 만들어주었다. 
	
	조건이 3가지가 있다. 
	  1. 전 열의 데이터를 하나도 참고하지 않았을 때,    // 0행 
	  2. 전 열의 데이터를 1행 하나 참고했을 때,       // 1행 
	  3. 전 열의 데이터를 2행 하나 참고했을 때,       // 2행 
	그래서 0행에는 그 전 열의 최대값을 넣어준다. 
	1행은 전 열의 0행 데이터와 2행 데이터 중 큰 값과 자신을 더하고,  // 0행 데이터는 전전 열의 최대값. 
	2행은 전 열의 0행 데이터와 1행 데이터 중 큰 값과 자신을 더한다. 
	ex) 5
        50 10 100 20 40
        30 50  70 10 60
	
	 -----------------------------
	|   0 |  50 | 100 | 200 | 210 |
	|-----------------------------
	|  50 |  40 | 200 | 130 | 250 |
	|-----------------------------
	|  30 | 100 | 110 | 210 | 260 |
	 -----------------------------
	
	위의 식대로 문제를 풀면 이러한 행렬이 나온다. 
*/