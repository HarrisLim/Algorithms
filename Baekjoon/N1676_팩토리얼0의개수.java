package baekjoon;
/*
	[팩토리얼]
	
	문제: 0보다 크거나 같은 정수 N이 주어진다. 이 때, N!을 출력하는 프로그램을 작성하시오.

	입력: 첫째 줄에 정수 N(0 ≤ N ≤ 12)가 주어진다.

	출력: 첫째 줄에 N!을 출력한다.
*/

import java.io.*;

class Factorial0 {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int n;
	int count;

	Factorial0(){
		try{
			n = Integer.parseInt(br.readLine());
		}catch(IOException ie){}
	}
	void search2() {
		int a,b,c;
		if(n==0) a=0;
		else a=(n/5);
		b=(n/25);
		c=(n/125);
		count = a+b+c;
	}
	void showResult() {
		System.out.println(count);
	}
	void play(){
		search2();
		showResult();
	}
}

class Main {
	public static void main(String[] args){
		Factorial0 main = new Factorial0();
		main.play();
	}
}

/*
		한 줄 정리
	이 문제는 팩토리얼로 풀어보려고 하다가 도저히 모르겠어서 찾아봤다. 
	입력받은 값에서 5로 나눈 몫을 count하면 된다. (몫이 0의 개수이다)  
	그런데 5의 거듭제곱도 확인을 해야한다. 그래서 25와 125를 확인하는 것이다.
	아직 나의 실력으로는 이건 도저히 내가 생각해서 풀 수 없는 문제같다.
	팩토리얼과 관련이 있기는 하지만, 넌센스 같은 넌센스 같지 않은 이 느낌은 뭘까  
*/