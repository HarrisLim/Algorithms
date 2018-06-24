package baekjoon;
/*
	[거스름돈]
	
	문제: 타로는 자주 JOI잡화점에서 물건을 산다.
		JOI잡화점에는 잔돈으로 500엔, 100엔, 50엔, 10엔, 5엔, 1엔이 충분히 있고, 언제나 거스름돈 갯수가 가장 적게 잔돈을 준다.
		타로가 JOI잡화점에서 물건을 사고 카운터에서 1000엔 지폐를 한장 냈을 때, 받을 잔돈에 포함된 잔돈의 갯수를 구하는 프로그램을 작성하시오.
		예를 들어 입력된 예1의 경우에는 아래 그림에서 처럼 4개를 출력해야 한다.
		       ---------------------
		 620엔 | 500엔 100엔 10엔 10엔 |
		       ---------------------
	입력: 입력은 한줄로 이루어져있고, 타로가 지불할 돈(1 이상 1000미만의 정수) 1개가 쓰여져있다.

	출력: 제출할 출력 파일은 1행으로만 되어 있다. 잔돈에 포함된 매수를 출력하시오.
*/

import java.io.*;

class Change {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int change;
	int count;
	
	Change(){
		try {
			change = 1000-Integer.parseInt(br.readLine());
		}catch(IOException ie) {}
	}
	int checkChange() {
		if(change>=500) {
			count++;
			change-=500;
		}
		if(change>=100){
			count++;
			change-=100;
			if(change>=100) checkChange();
		}
		if(change>=50) {
			count++;
			change-=50;
		}
		if(change>=10) {
			count++;
			change-=10;
			if(change>=10) checkChange();
		}
		if(change>=5) {
			count++;
			change-=5;
		}
		if(change>=1){
			count++;
			change-=1;
			if(change>=1) checkChange();
		}
		return count;
	}
	void play() {
		checkChange();
		System.out.println(checkChange());
	}
}

class Main {
	public static void main(String[] args) {
		Change main = new Change();
		main.play();
	}
}

/*
		한 줄 정리
	너무 하나하나 다 비교하면서 한건가..?
	입력받은 코인에서 500원 이상이면 빼고, 뺀 값이 100원 이상이면 재귀로 빼고, 그 뺀 값이 50원 이상이면 50을 빼고,,,
	이렇게 쭉쭉 진행시켰다. 
 */