package baekjoon;
/*
	[분해합]

	문제: 어떤 자연수 N이 있을 때, 그 자연수 N의 분해합은 N과 N을 이루는 각 자리수의 합을 의미한다.
		어떤 자연수 M의 분해합이 N인 경우, M을 N의 생성자라 한다.
		예를 들어, 245의 분해합은 256(=245+2+4+5)이 된다. 따라서 245는 256의 생성자가 된다.
		물론, 어떤 자연수의 경우에는 생성자가 없을 수도 있다. 반대로, 생성자가 여러 개인 자연수도 있을 수 있다.
		자연수 N이 주어졌을 때, N의 가장 작은 생성자를 구해내는 프로그램을 작성하시오.

	입력: 첫째 줄에 자연수 N(1≤N≤1,000,000)이 주어진다.

	출력: 첫째 줄에 답을 출력한다. 생성자가 없는 경우에는 0을 출력한다.
*/	

import java.io.*;
import java.util.ArrayList;


class DividedSum {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	ArrayList<Integer> arr = new ArrayList<Integer>();
	int n;

	DividedSum(){
		try{
			n = Integer.parseInt(br.readLine());
		}catch(IOException e){}
	}
	int calcDigitSum(int a) {
		String ax=a+"";
		int sum=0;
		for(int i=0; i<ax.length(); i++) {
			sum += Character.getNumericValue(ax.charAt(i));
		}
		return sum;
	}
	void loop(int m, int limit) {
		int total = m+calcDigitSum(m);
		if(n==total)
			arr.add(m);
		if(m==0 || limit==0)
			return;
		else
			loop(m-1, limit-1);
	}
	int showResult() {
		if(n==0) return 0;
		loop(n, 100);
		if(arr.size()==0) return 0;
		return arr.get(arr.size()-1);
	}
	void play(){
		System.out.println(showResult());
	}
}

class Main {
	public static void main(String[] args){
		DividedSum ds = new DividedSum();
		ds.play();
	}
}

/*
		한 줄 정리
	그냥 N의 자릿수마다의 수를 더한 값을 0까지 비교하니까 계속 stackoverflow가 떠서 limit을 주었다.
	100으로 준 이유는, N을 1,000,000이하의 숫자만 받을 수 있다.
	그렇다면 999,999 즉, 9+9+9+9+9+9를 해도 54이기 때문이다.
*/