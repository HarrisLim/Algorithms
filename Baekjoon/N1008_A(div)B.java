/*
	[A/B]

	문제: A/B를 계산하시오.

	입력: 첫째 줄에 A와 B가 주어진다. (0 < A, B < 10)

	출력: 첫째 줄에 A/B를 출력한다. 절대/상대 오차는 10-9 까지 허용한다.
*/
	
import java.io.*;

class Main {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	void input() throws IOException{
		String nums = br.readLine();
		int idx = 0;
		double first=0,second=0;
		idx = nums.indexOf(" ");
		first = Double.parseDouble(nums.substring(0, idx));
		second = Double.parseDouble(nums.substring(idx+1));
		output(first, second);
	}
	void output(double a, double b){
		System.out.println(a/b);
	}
	public static void main(String[] args) {
		Main m = new Main();
		try{
			m.input();
		}catch(IOException ie){}
	}
}

