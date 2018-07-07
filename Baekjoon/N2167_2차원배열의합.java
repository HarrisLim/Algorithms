package baekjoon;
/*
	[2차원 배열의 합]
	
	문제: 2차원 배열이 주어졌을 때 (i, j) 위치부터 (x, y) 위치까지에 저장되어 있는 수들의 합을 구하는 프로그램을 작성하시오.
		배열의 (i, j) 위치는 i행 j열을 나타낸다.

	입력: 첫째 줄에 배열의 크기 N, M(1 ≤ N, M ≤ 300)이 주어진다. 다음 N개의 줄에는 M개의 정수로 배열이 주어진다.
		배열에 포함되어 있는 수는 절댓값이 10,000보다 작거나 같은 정수이다.
		그 다음 줄에는 합을 구할 부분의 개수 K(1 ≤ K ≤ 10,000)가 주어진다.
		다음 K개의 줄에는 네 개의 정수로 i, j, x, y가 주어진다(i ≤ x, j ≤ y).

	출력: K개의 줄에 순서대로 배열의 합을 출력한다. 배열의 합은 32bit-int 범위를 초과하지 않는다.
*/

import java.io.*;
import java.util.*;

class DoubleArraySum {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int k; // 합을 구할 시작행렬, 끝행렬을 받을 횟수 
	int[][] arr; // 행렬 초기화 
	int sa, sb, ea, eb; // sa, sb: 시작행[sa][sb].  ea, eb: 끝행렬[ea][eb]

	DoubleArraySum(){
		try{
			String line = br.readLine();
			StringTokenizer st = new StringTokenizer(line, " ");
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			arr = new int[n][m];
			for(int i=0; i<n; i++){
				String temp = br.readLine();
				st = new StringTokenizer(temp, " ");
				for(int j=0; st.hasMoreTokens(); j++)
					arr[i][j] = Integer.parseInt(st.nextToken());
			}
			k = Integer.parseInt(br.readLine());
		}catch(IOException ie){}
	}
	void input(){
		try{
			String line = br.readLine();
			StringTokenizer st = new StringTokenizer(line, " ");
			sa = Integer.parseInt(st.nextToken())-1;
			sb = Integer.parseInt(st.nextToken())-1;
			ea = Integer.parseInt(st.nextToken())-1;
			eb = Integer.parseInt(st.nextToken())-1;
		}catch(IOException ie){}
	}
	void clear() {
		Arrays.fill(arr, 0);
	}
	void play(){
		while(k-->0){
			int sum=0;
			input();
			for(int i=sa; i<arr.length; i++) {  // 시작 행부터 모든 행 
				for(int j=sb; j<arr[0].length; j++) {  // 시작 열부터 모든 열 
					if(i<=ea&&j<=eb) {  // 끝 열과 끝 행보다 작거나 같으면 
						sum+= arr[i][j];  // 더한다. 
					}
				}
			}
			System.out.println(sum);
		}
	}
}
class Main {
	public static void main(String[] args) {
		DoubleArraySum main = new DoubleArraySum();
		main.play();
	}
}

/*
		한 줄 정리 
	bottom-up방식으로 풀었다. (bottom-up방식 맞겠지..?)
	행렬이 주어지고 시작행렬과 끝행렬을 준다.
	시작행렬과 끝행렬까지의 수를 더하는 문제다. 
	나는 시작행렬의 행, 열, 끝행렬의 행, 열을 하나하나 변수로 주었다. 
 
 	그리고 for문을 돌려서 
 	1. 시작 행부터 모든행을 돌고
 	2. 시작 열부터 모든 열을 돌면서 
 	3. 끝 열과 끝 행보다 작거나 같으면 더하는 방식으로 했다.
*/