/*
	[캥거루 세 마리]
	
	문제: 캥거루 세 마리가 사막에서 놀고 있다. 사막에는 수직선이 하나 있고, 캥거루는 서로 다른 한 좌표 위에 있다.
		한 번 움직일 때, 바깥쪽의 두 캥거루 중 한 마리가 다른 두 캥거루 사이의 정수 좌표로 점프한다.
		한 좌표 위에 있는 캥거루가 두 마리 이상일 수는 없다.
		캥거루는 최대 몇 번 움직일 수 있을까?

	입력: 첫째 줄에 세 캥거루의 초기 위치 A, B, C가 주어진다. (0 < A < B < C < 100)

	출력: 캥거루가 최대 몇 번 움직일 수 있는지 출력한다.
*/

import java.util.*;

class Kangaroo{
	Scanner s = new Scanner(System.in);
	int a, b, c;
	int max;
	int count;
	boolean flag;

	void input(){
		a = s.nextInt();
		b = s.nextInt();
		c = s.nextInt();
	}
	int measure(){
		int left = b-a;
		int right = c-b;

		if(left < right) return 1;
		else return 2;
	}
	void findMax(){
		if(measure() == 1){
			plus();
		}else{
			mius();
		}
	}
	void plus(){
		if(a<b) a = b+1;
		else b = a+1;
		if(c==a || c==b) return;
		count++;
		plus();
	}
	void mius(){
		if(b<c) c = b-1;
		else b = c-1;
		if(a==b || a==c) return;
		count++;
		mius();
	}
	void showResult(){
		System.out.println(count);
	}
	void play(){
		input();
		findMax();
		showResult();
	}
}

class Main{
	public static void main(String[] args){
		Kangaroo k = new Kangaroo();
		k.play();
	}
}

/*
		한 줄 정리
	- (a와 b의 거리) (b와 c의 거리)를 구하여 거리가 짧은 쪽의 가장자리 캥거루를 
	   가운데 캥거루 옆의 좌표로 옮긴다
	- 가장자리 캥거루와 가운데 캥거루의 좌표를 +1 or -1 반복하면서 반대 쪽 가장자리 캥거루와 같아지면 return
*/