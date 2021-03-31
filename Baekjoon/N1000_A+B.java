/*
	[A+B]

	문제: 두 수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

	입력: 첫째 줄에 A와 B가 주어진다. (0 < A, B < 10)

	출력: 첫째 줄에 A+B를 출력한다.
*/	

import java.io.*;

public class Main 
{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int sum;
	int a, b;

	int m() throws IOException{
		String line = br.readLine();
		int idx = line.indexOf(" ");
		a = Integer.parseInt(line.substring(0, idx));
		b = Integer.parseInt(line.substring(idx+1));
		sum = a + b;
		return sum;
	}
	public static void main(String[] args) 
	{	
		try{
			Main m = new Main();
			System.out.println(m.m());
		}catch(IOException ie){}
	}
}