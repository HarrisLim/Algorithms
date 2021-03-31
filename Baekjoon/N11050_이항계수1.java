package baekjoon;

/*
	[이항 계수1]
	
	문제: 자연수 N과 정수 K가 주어졌을 때 이항 계수 nCk를 구하는 프로그램을 작성하시오.
	
	입력: 첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 10, 0 ≤ K ≤ N)
	
	출력: nCk를 출력한다.
*/

import java.util.*;
import java.io.*;

class Binomial1 {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int n, k;
	
	Binomial1(){
		try{
			String line = br.readLine();
			StringTokenizer st = new StringTokenizer(line, " ");
			n=Integer.parseInt(st.nextToken());
			k=Integer.parseInt(st.nextToken());
		}catch(IOException ie){}
	}
	int loop(int a, int b){
		if(a==b||b==0) return 1;
		return loop(a-1, b)+loop(a-1, b-1);
	}
	void play(){
		System.out.println(loop(n, k));
	}	
}

class Main {
	public static void main(String[] args) {
		Binomial1 main = new Binomial1();
		main.play();
	}
}

/*		
		한 줄 정리
	식을 외우고 있어서, 너무 쉽게 풀었다.
	설명을 무엇이라고 써야할지 모르겠다. 알고리즘 스터디할 때 왜 다른 분들이 그냥 식이 있다고 말하셨는지 알 것 같다.
	이항계수란, n개 중에서 k개를 선택할 수 있는 경우의 수를 구하는 것이다. 
	nCk가 있다면,
	if n==k || k==0 일 때, return 1;
	else return recursion(n-1, k) + recursion(n-1, k-1);
*/