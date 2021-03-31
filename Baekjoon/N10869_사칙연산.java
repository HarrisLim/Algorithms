/*
	[사칙연산]

	문제: 두 자연수 A와 B가 주어진다. 이 때, A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오. 

	입력: 두 자연수 A와 B가 주어진다. (1 ≤ A, B ≤ 10,000)

	출력: 첫째 줄에 A+B, 둘째 줄에 A-B, 셋째 줄에 A*B, 넷째 줄에 A/B, 다섯째 줄에 A%B를 출력한다.
*/

import java.io.*;

class Main {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	void input() throws IOException{
		String nums = br.readLine();
		int idx = 0;
		int first=0,second=0;
		idx = nums.indexOf(" ");
		first = Integer.parseInt(nums.substring(0, idx));
		second = Integer.parseInt(nums.substring(idx+1));
		output(first, second);
	}
	void output(int a, int b){
		System.out.println(a+b);
		System.out.println(a-b);
		System.out.println(a*b);
		System.out.println(a/b);
		System.out.println(a%b);
	}
	public static void main(String[] args) {
		Main m = new Main();
		try{
			m.input();
		}catch(IOException ie){}
	}
}