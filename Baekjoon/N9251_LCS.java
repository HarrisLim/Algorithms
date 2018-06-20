/*
	[LCS]
	
	문제: LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때,
		모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.
		예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

	입력: 첫째 줄과 둘째 줄에 두 문자열이 주어진다.
		문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.

	출력: 첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를 출력한다.
*/

import java.io.*;
import java.util.*;

class LCS{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	String[] a, b;
	int[][] memo = new int[1000][1000];

	LCS(){
		try{
			String line = br.readLine();
			a = new String[line.length()+1];
			for(int i=1; i<a.length; i++)
				a[i] = Character.toString(line.charAt(i-1));
			line = br.readLine();
			b = new String[line.length()+1];
			for(int i=1; i<b.length; i++)
				b[i] = Character.toString(line.charAt(i-1));
		}catch(IOException ie){}
	}
	void loop(){
		for(int i=1; i<a.length; i++){
			for(int j=1; j<b.length; j++){
				if(a[i].equals(b[j])){
					memo[i][j] = memo[i-1][j-1]+1;
				}else{
					memo[i][j] = Math.max(memo[i-1][j], memo[i][j-1]);
				}
			}
		}
	}
	void showResult(){
		System.out.println(memo[a.length-1][b.length-1]);
	}
	void play(){
		loop();
		showResult();
	}
}

class Main {
	public static void main(String[] args){
		LCS main = new LCS();
		main.play();
	}
}
/*
		한 줄 정리
	LCS2하고 생각을 정리하면서 LCS도 했다.
	dp행렬을 만들고, 첫 행렬은 다 0으로 채우고, 그 다음부터
	Ai와 Bi가 같다면,
		대각선위에 있는 수에 +1해서 memo[i][j]에 넣는다.
	같지 않다면
		왼쪽과 위쪽의 수를 비교해서 큰 값을 memo[i][j]에 넣는다.
*/