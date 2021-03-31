/*
	[AxB]

	문제: 두 정수 A와 B를 입력받은 다음, A×B를 출력하는 프로그램을 작성하시오.

	입력: 첫째 줄에 A와 B가 주어진다. (0 < A, B < 10)

	출력: 첫째 줄에 A×B를 출력한다.
*/

import java.io.*;

class Main {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	void input() throws IOException{
		String nums = br.readLine();
		int idx = 0, first=0,second=0;
		idx = nums.indexOf(" ");
		first = Integer.parseInt(nums.substring(0, idx));
		second = Integer.parseInt(nums.substring(idx+1));
		output(first, second);
	}
	void output(int a, int b){
		System.out.println(a*b);
	}
	public static void main(String[] args) {
		Main m = new Main();
		try{
			m.input();
		}catch(IOException ie){}
	}
}