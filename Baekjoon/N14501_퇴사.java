package baekjoon;
/*
	[퇴사]
	
	문제: 상담원으로 일하고 있는 백준이는 퇴사를 하려고 한다.
		오늘부터 N+1일째 되는날 퇴사를 하기 위해서, 남은 N일 동안 최대한 많은 상담을 하려고 한다.
		백준이는 비서에게 최대한 많은 상담을 잡으라고 부탁을 했고, 비서는 하루에 하나씩 서로 다른 사람의 상담을 잡아놓았다.
		각각의 상담은 상담을 완료하는데 걸리는 기간 Ti와 상담을 했을 때 받을 수 있는 금액 Pi로 이루어져 있다.
		N = 7인 경우에 다음과 같은 상담 일정표를 보자.
		
		 	1일	2일	3일	4일	5일	6일	7일
		Ti	3	5	1	1	2	4	2
		Pi	10	20	10	20	15	40	200
		
		1일에 잡혀있는 상담은 총 3일이 걸리며, 상담했을 때 받을 수 있는 금액은 10이다.
		5일에 잡혀있는 상담은 총 2일이 걸리며, 받을 수 있는 금액은 15이다.		
		상담을 하는데 필요한 기간은 1일보다 클 수 있기 때문에, 모든 상담을 할 수는 없다.
		예를 들어서 1일에 상담을 하게 되면, 2일, 3일에 있는 상담은 할 수 없게 된다.
		2일에 있는 상담을 하게 되면, 3, 4, 5, 6일에 잡혀있는 상담은 할 수 없다.
		또한, N+1일 째에는 회사에 없기 때문에, 6, 7일에 있는 상담을 할 수 없다.
		퇴사 전에 할 수 있는 상담의 최대 이익은 1일, 4일, 5일에 있는 상담을 하는 것이며, 이 때의 이익은 10+20+15=45이다.
		상담을 적절히 했을 때, 백준이가 얻을 수 있는 최대 수익을 구하는 프로그램을 작성하시오.

	입력: 첫째 줄에 N (1 ≤ N ≤ 15)이 주어진다.
		둘째 줄부터 N개의 줄에 Ti와 Pi가 공백으로 구분되어서 주어지며,
		1일부터 N일까지 순서대로 주어진다. (1 ≤ Ti ≤ 5, 1 ≤ Pi ≤ 1,000)

	출력: 첫째 줄에 백준이가 얻을 수 있는 최대 이익을 출력한다.
*/

import java.io.*;
import java.util.*;

class Resignation {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int n;
	int[] t, p; // t: 소요 기간, p: 금액
	int[] dp; // N일 까지 얻는 이익 
	int sum;
	
	Resignation(){
		try {
			n = Integer.parseInt(br.readLine());
			dp = new int[n+1]; 
			t = new int[n+1];
			p = new int[n+1];
		}catch(IOException ie) {}
	}
	void input() {
		try {
			for(int i=1; i<=n; i++) {
				String line = br.readLine();
				StringTokenizer st = new StringTokenizer(line, " ");
				t[i] = Integer.parseInt(st.nextToken());
				p[i] = Integer.parseInt(st.nextToken());
				dp[i] = p[i];
			}
		}catch(IOException ie) {}
	}
	void loop() {
		for(int i=2; i<=n; i++) {
//			System.out.println("--------- "+i+" ------------");
			for(int j=1; j<i; j++) {
//				System.out.println("i-j: "+(i-j)+", t["+j+"]: "+t[j]);
				if(i-j>=t[j]) {
//					System.out.println("p["+i+"] + dp["+j+"]: "+ (p[i]+dp[j])+", dp["+i+"]: "+ dp[i]);
					dp[i] = Math.max(p[i]+dp[j], dp[i]);
				}
			}
		}
		
		// 더했을 때 근무일을 초과하는 경우의 dp[i](합)의 값은 출력하지 않는다. 
		for(int i=1; i<=n; i++) {
			if(i+t[i] <= n+1) {
				if(sum < dp[i]) {
					sum = dp[i];
				}
			}
		}
	}
	void showResult() {
		System.out.println(sum);
	}
	void play() {
		input();
		loop();
		showResult();
	}
}

class Main{
   public static void main(String[] args) {
      new Resignation().play();
   }
}

/*
		한 줄 정리 
	dp[N]에 N일 까지의 이익을 넣는다. 
	넣을 때, 1일이랑 1일에 해당하는 상담기간을 비교한다. 
	쭉쭉 비교해 나가면서 날짜가 상담기간보다 크거나 같다면, 해당 날짜의 비용+지금까지의 비용, 해당날짜까지의 비용 중 max를 구해서
	dp[]에 넣는다. 말로 설명한 것을 보는 것보다 위의 코드를 보자.
	나는 http://mygumi.tistory.com/151에서 코드 설명을 봤는데, 너무 어렵다고 생각했는데 이렇게 간단히 풀어서 놀랐다.
	더 발전하자 ! 
*/