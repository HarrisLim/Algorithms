package baekjoon;
/*
	[동전 0]
	
	문제: 준규가 가지고 있는 동전은 총 N종류이고, 각각의 동전을 매우 많이 가지고 있다.
		동전을 적절히 사용해서 그 가치의 합을 K로 만드려고 한다. 이 때 필요한 동전 개수의 최소값을 구하는 프로그램을 작성하시오.
		
	입력: 첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 10, 1 ≤ K ≤ 100,000,000)
		둘째 줄부터 N개의 줄에 동전의 가치 Ai가 오름차순으로 주어진다. (1 ≤ Ai ≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수)
	
	출력: 첫째 줄에 K원을 만드는데 필요한 동전 개수의 최소값을 출력한다.
*/

import java.io.*;
import java.util.*;

class Coin0 {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int n, k, x;
	int[] coins;
	
	Coin0(){
		try {
			String line = br.readLine();
			StringTokenizer st = new StringTokenizer(line, " ");
			n = Integer.parseInt(st.nextToken());
			k = Integer.parseInt(st.nextToken());
			coins = new int[n];
		}catch(IOException ie) {}
	}
	void input() {
		try {
			for(int i=0; i<n; i++) {
				coins[i] = Integer.parseInt(br.readLine());
			}
		}catch(IOException ie) {}
	}
	void getCoin() {
		if(k==0) return;
		for(int i=n-1; i>=0; i--) {
			if(coins[i]<=k) {
				x += k/coins[i];
				k%=coins[i];
				getCoin();
				break;
			}
		}
	}
	void play() {
		input();
		getCoin();
		System.out.println(x);
	}
}

class Main{
	public static void main(String[] args) {
	  new Coin0().play();
	}
}

/*
		한 줄 정리
	나누기가 아니라 빼기로 했을 때, 60%까지 채점하다가 런타임에러가 나서, 범위를 잘못 지정한 줄 알았다.
	그런데 
	1 100000000
	1
	을 넣으면 overflow가 발생하고 1 10000만 넣어도 overflow가 발생했다. 
	곰곰히 생각하다가, 값이 너무 크니까 빼는 건 무리고 나누는 걸 생각해봤다. 
	수학을 너무 못하지만, 이렇게 한 거 보면 너무 못하는 건 아닌 것 같다 :)

 	재귀로 풀었는데, 
 	1. 입력받은 N개의 코인을 확인하면서 동전(k)보다 작은지 확인헀다. 
 	2. 동전(k)보다 작다면 동전(k)를 현재의 코인(coins[i])로 나누고, 나눈값을 x에 대입한다.
 	3. 그리고 동전(k)는 현재의 코인(coins[i])으로 나눈 나머지값을 대입한다.
 	그리고 getCoin()을 실행하여 위의 1,2,3을 반복한다.
 	
 	그리디 알고리즘으로 최소값을 구할 수 있는 이유는 오름차순으로 나와서 구할 수 있는 것 같다. 
 	원래 내가 알고 있는 그리디 알고리즘은 현재에 최선을 다 하는 것이라서,
 	최적값을 구할 수 없을 수도 있고 ~ 있을 수도 있다고 알고 있다.
*/