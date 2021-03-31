package baekjoon;
/*
	[ A + B -2 ]
	
	문제: 두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
		
	입력: 첫째 줄에 A, 둘째 줄에 B가 주어진다. (0 < A, B < 10)

	출력: 첫째 줄에 A+B를 출력한다.
*/

import java.io.*;
import java.util.*;

class AplusBminus2 {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int a, b;
	
	AplusBminus2(){
		try {
			a = Integer.parseInt(br.readLine());
			b = Integer.parseInt(br.readLine());
		}catch(IOException ie) {}
	}
	void play() {
		System.out.println(a+b);
	}
}

class Main{
	public static void main(String[] args) {
	  new AplusBminus2().play();
	}
}

/*
		한 줄 정리
	a + b를 입력받아서 더한 값을 출력하는 아주아주아주! 간단한 문제.
*/

