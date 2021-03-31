/*
	[A-B]

	문제: A-B를 계산하시오.

	입력: 첫째 줄에 A와 B가 주어진다. (0< A, B < 10)

	출력: 첫째 줄에 A-B를 출력한다.
*/	

import java.io.*;

public class Main 
{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int sub;
	int a, b;

	int m() throws IOException{
		String line = br.readLine();
		int idx = line.indexOf(" ");
		a = Integer.parseInt(line.substring(0, idx));
		b = Integer.parseInt(line.substring(idx+1));
		sub = a - b;
		return sub;
	}
	public static void main(String[] args) 
	{	
		try{
			Main m = new Main();
			System.out.println(m.m());
		}catch(IOException ie){}
	}
}