/*
	[LCS2]

	문제: LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때,
		모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.
		예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.
	
	입력: 첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.
	
	출력: 첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를, 둘째 줄에 LCS를 출력한다.
		LCS가 여러가지인 경우에는 아무거나 출력한다.
*/

import java.io.*;
import java.util.Vector;

class LCS2 {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	Vector<String> list = new Vector<String>(); // LCS를 담기 위한 list
	String[] a, b; // a: 첫번 째 문자열, b: 두번 째 문자열
	int[][] dp = new int[1000][1000];
	
	LCS2(){
		try {
			String line = br.readLine();
			a = new String[line.length()+1];
			for(int i=1; i<a.length; i++) {
				a[i] = Character.toString(line.charAt(i-1));
			}
			line = br.readLine();
			b=new String[line.length()+1];
			for(int i=1; i<b.length; i++) {
				b[i] = Character.toString(line.charAt(i-1));
			}
		}catch(IOException ie) {}
	}

	// LCS의 길이를 구하기 위한 dp. 아마, bottom-up 방식
	int loop() {
		if(a.length==0 || b.length==0) return 0;
		for(int i=1; i<a.length; i++) {
			for(int j=1; j<b.length; j++) {
				if(a[i].equals(b[j]))
					dp[i][j] = dp[i-1][j-1]+1;
				else
					dp[i][j] = Math.max(dp[i-1][j],dp[i][j-1]); // dp의 위 or 왼 숫자중 큰 것
			}
		}
		return dp[a.length-1][b.length-1];
	}

	// LCS 구하기 위한 재귀
	void recur(int x, int y, int val){
		if(x==0||y==0) return;
		if(a[x].equals(b[y])){
			list.add(a[x]);
			recur(x-1, y-1, val-1);
		}else{
			if(dp[x-1][y] > dp[x][y-1]){ // 위가 크면
				recur(x-1, y, val);
			}else if(dp[x-1][y] < dp[x][y-1]){ // 위가 작으면
				recur(x, y-1, val);
			}else { // 같으면
				recur(x-1, y, val);
			}
		}
	}
	void play() {
		System.out.println(loop());
		recur(a.length-1, b.length-1, dp[a.length-1][b.length-1]);
		for(int i=list.size()-1; i>=0; i--)
			System.out.print(list.get(i));
	}
}
class Main {
	public static void main(String[] args) {
		LCS2 main = new LCS2();
		main.play();
	}
}

/*
		한 줄 정리 
	
	- 순환식
	    	     --  0                            // if i=0 or j=0;  // i나 j가 0이면 0
	    L[i,j]  |    L[i-1, j-1]+1                // if Xi = Yi      // 같으면 왼쪽위(대각선)의 값 +1   
	             --  max(L[i-1,j], L[i, j-1])     // otherwise       // 다르면 왼쪽값과 위쪽값 중 큰 값

	순환식이랑 dp테이블을 보고 코드를 짰다. 내가 바로 순환식이랑 dp테이블을 만들기에는 힘들어서
	참고했는데, 참고해도 내가 해서 너무 좋다 :)
	
*/  

