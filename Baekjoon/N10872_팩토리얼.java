package baekjoon;
/*
	[팩토리얼]
	
	문제: 0보다 크거나 같은 정수 N이 주어진다. 이 때, N!을 출력하는 프로그램을 작성하시오.

	입력: 첫째 줄에 정수 N(0 ≤ N ≤ 12)가 주어진다.

	출력: 첫째 줄에 N!을 출력한다.
*/

import java.io.*;

class Factorial {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int n;
	int sum=1;

	Factorial(){
		try{
			n = Integer.parseInt(br.readLine());
		}catch(IOException ie){}
	}
	
	// 재귀 
	int loop(int x){
		if(x<2) return 1;
		else{
			sum*=x;
			loop(x-1);
		}
		return sum;
	}
	
	// for문 
	int myFor() {
		for(int i=1; i<=n; i++)
			sum*= i;
		return sum;
	}
	void play(){
		System.out.println(loop(n));
//		System.out.println(myFor());
	}
}

class Main {
	public static void main(String[] args){
		Factorial main = new Factorial();
		main.play();
	}
}

/*
		한 줄 정리
	재귀로 어떻게 하는지 모르겠어서 for문으로 작성해보고 재귀로 바꿨다. 
	1~입력받은 수까지 곱하는 팩토리얼, 근데 0일 때도 1이다.
*/