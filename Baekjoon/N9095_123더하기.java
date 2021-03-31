package baekjoon;
/*
	[1, 2, 3 더하기]
	
	문제: 정수 4를 1, 2, 3의 조합으로 나타내는 방법은 총 7가지가 있다.
			1+1+1+1
			1+1+2
			1+2+1
			2+1+1
			2+2
			1+3
			3+1
		정수 n이 주어졌을 때, n을 1,2,3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

	입력: 첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. n은 양수이며 11보다 작다.

	출력: 각 테스트 케이스마다, n을 1,2,3의 합으로 나타내는 방법의 수를 출력한다.
*/

import java.io.*;
import java.util.*;

class PlusOneTwoThree {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int t, n; // t: 테스트케이스, n: 경우의 수를 구할 값 
	int[] x; // 값을 저장해 놓을 배열. 
	PlusOneTwoThree(){
		try {
			t = Integer.parseInt(br.readLine());
		}catch(IOException ie) {}
	}
	void input() {
		try {
			n = Integer.parseInt(br.readLine());
			x = new int[n];
			Arrays.fill(x, 1);
		}catch(IOException ie) {}
	}
	int loop(int p) {
		for(int i=0; i<n; i++) // 1,2,3일 때 경우의 수를 먼저 X배열에 대입해놓는다. 
			if(i==2) x[i]=i+2;
			else x[i] = i+1;
		
		if(n>=3) 
			for(int i=3; i<n; i++) // 4이상일 때, 입력받은 값의 -3, -2, -1의 경우의 수를 구해서 더한다. 
				x[i] = x[i-3] + x[i-2] + x[i-1];
		
		return x[p];
	}
	void play() {
		while(t-->0) {
			input();
			System.out.println(loop(n-1));
		}
	}
}

class Main{
	public static void main(String[] args) {
	  new PlusOneTwoThree().play();
	}
}

/*
		한 줄 정리
	며칠을 고민하다가 블로그를 찾아봤다. 그냥 패턴이 있다. 왜 이렇게 생각을 못했을까.
	
	4의 경우의 수를 구해야 한다면, (1의 경우의수 + 2의 경우의수 + 3의 경우의 수)를 구하면 된다. 
	그러니까, X[n]를 구하려면 ( X[n-3] + X[n-2] + X[n-1] )를 구하면 되는 것이다. 
	
	그런데 만약, 1과 2로 더한 값의 경우의 수를 구한다면, ( X[n-2] + X[n-1] )이 되는 것이다. 
*/