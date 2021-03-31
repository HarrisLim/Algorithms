/*
	[최소공배수]
	
	문제: 두 자연수 A와 B에 대해서, A의 배수이면서 B의 배수인 자연수를 A와 B의 공배수라고 한다.
		이런 공배수 중에서 가장 작은 수를 최소공배수라고 한다.
		예를 들어, 6과 15의 공배수는 30, 60, 90등이 있으며, 최소 공배수는 30이다.
		두 자연수 A와 B가 주어졌을 때, A와 B의 최소공배수를 구하는 프로그램을 작성하시오.

	입력: 첫째 줄에 테스트 케이스의 개수 T(1 ≤ T ≤ 1,000)가 주어진다.
		둘째 줄부터 T개의 줄에 걸쳐서 A와 B가 주어진다. (1 ≤ A, B ≤ 45,000)

	출력: 첫째 줄부터 T개의 줄에 A와 B의 최소공배수를 입력받은 순서대로 한 줄에 하나씩 출력한다.
*/

import java.util.*;

class MinCommonMulti {
	Scanner s = new Scanner(System.in);
	int n, a, b;
	int val;

	MinCommonMulti(){
		n = s.nextInt();
	}
	void input(){
		a = s.nextInt();
		b = s.nextInt();
	}
	void gcd(int o, int p){ // 최대공약수
		if(p==0) return;
		int left = o%p;
		o = p;
		val = p;
		gcd(o, left);
	}
	int lcm(int o, int p){ // 최소공배수
		return o*p/val;
	}
	void play(){
		while(n-->0){
			input();
			gcd(a, b);
			System.out.println(lcm(a, b));
		}
	}
}

class Main {
	public static void main(String[] args){
		MinCommonMulti mcm = new MinCommonMulti();
		mcm.play();
	}
}

/*
		한 줄 정리
	밑의 코드로 하니까 overflow떠서, 유클리드 호제법을 검색해봤다. 
	식을 그래도 코드로 구현하니까 된다. 수학...
	유클리드호제법은 사실 최대공약수를 구하는 식이지만, 
	a*b / 최대공약수 <- 이렇게 최소공배수를 구할 수 있다.

		터진 코드..
	void multiply(int q, int w){
		if(ax < bx){
			ax=a*q;
			multiply(q+1, w);
		}
		if(ax > bx){
			bx=b*w;
			multiply(q, w+1);
		}
	}
*/