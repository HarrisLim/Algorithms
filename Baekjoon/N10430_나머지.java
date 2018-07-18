package baekjoon;
/*
	[나머지]
	
	문제: (A+B)%C는 (A%C + B%C)%C 와 같을까?
		(A×B)%C는 (A%C × B%C)%C 와 같을까?
		세 수 A, B, C가 주어졌을 때, 위의 네가지 값을 구하는 프로그램을 작성하시오.
		
	입력: 첫째 줄에 A, B, C가 순서대로 주어진다. (2 ≤ A, B, C ≤ 10000)
	
	출력: 첫째 줄에 (A+B)%C, 둘째 줄에 (A%C + B%C)%C, 셋째 줄에 (A×B)%C, 넷째 줄에 (A%C × B%C)%C를 출력한다.
*/

import java.io.*;
import java.util.*;

class Division {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int a, b, c;
	int[] result = new int[4];
	
	Division(){
		try {
			String line = br.readLine();
			StringTokenizer st = new StringTokenizer(line, " ");
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
		}catch(IOException ie) {}
	}
	void calculate() {
		result[0] = (a+b)%c; 
		result[1] = (a%c + b%c)%c;
		result[2] = (a*b)%c;
		result[3] = (a%c * b%c)%c;
	}
	void play() {
		calculate();
		for(int i=0; i<result.length; i++) {
			System.out.println(result[i]);
		}
	}
}

class Main{
	public static void main(String[] args) {
	  new Division().play();
	}
}

/*
		한 줄 정리
	그냥 문제에 있는 식을 이용해 푼 문제. 
	너무 간단하다. 
	다른 사람들 코드를 보니까, 내가 만든 calculate()같은 메소드를 안만들고,
	바로 System.out.println((a+b)%c)이런 식으로 했다. 
	좀 더 간결하게 짜는 방법을 생각하자. 
*/