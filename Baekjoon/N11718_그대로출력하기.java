/*
	[그대로 출력하기]

	문제: 입력 받은 대로 출력하는 프로그램을 작성하시오.

	입력: 입력이 주어진다. 입력은 최대 100줄로 이루어져 있고, 알파벳 소문자, 대문자, 공백, 숫자로만 이루어져 있다. 각 줄은 100글자를 넘지 않으며, 빈 줄은 주어지지 않는다. 또, 각 줄은 공백으로 시작하지 않고, 공백으로 끝나지 않는다.

	출력: 입력받은 그대로 출력한다.
*/

import java.io.*;

class Main {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	String arr[] = new String[100];
	int count;
	void input() throws IOException{
		String temp;
		while((temp = br.readLine()) != null){
			int tempLen = temp.length();
			if(temp.length() > 100 || temp.length() == 0 ||
				temp.indexOf(" ") == 0 || temp.indexOf(" ") == tempLen-1) break;
			arr[count] = temp;
			count++;
		}
	}
	void output() {
		for(int i = 0; i < count; i++) {
			System.out.println(arr[i]);
		}
	}
	public static void main(String[] args) {
		try {
			Main m = new Main();
			m.input();
			m.output();
		}catch(IOException ie) {}
	}
}