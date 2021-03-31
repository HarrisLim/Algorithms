package baekjoon;
/*
	[만취한 상범]
	
	문제: 서강대학교 곤자가 기숙사의 지하에는 n개의 방이 일렬로 늘어선 감옥이 있다. 각 방에는 벌점을 많이 받은 학생들이 구금되어있다.
		그러던 어느날, 감옥 간수인 상범이는 지루한 나머지 정신나간 게임을 하기로 결정했다.
		게임의 첫 번째 라운드에서 상범이는 위스키를 한 잔 들이키고, 달려가며 감옥을 한 개씩 모두 연다.
		그 다음 라운드에서는 2, 4, 6, ... 번 방을 다시 잠그고, 세 번째 라운드에서는 3, 6, 9, ... 번 방이 열려있으면 잠그고, 잠겨있다면 연다.
		같은 방식으로 n번의 라운드를 진행한 이후, 상범이는 위스키의 마지막 병을 마시고 쓰러져 잠든다.
		구금되어있는 몇 명(어쩌면 0명)의 학생들은 자신의 방을 잠그지 않은 채 상범이가 쓰러져버렸단 것을 깨닫고 즉시 도망친다.
		방의 개수가 주어졌을 때, 몇 명의 학생들이 도주할 수 있는지 알아보자.
		
	입력: 입력의 첫 번째 줄에는 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄에 한 개씩 방의 개수 n(5≤n≤100)이 주어진다.

	출력: 한 줄에 한 개씩 각 테스트 케이스의 답, 즉 몇 명이 탈출할 수 있는지를 출력한다.
*/

import java.io.*;

class Drunken {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int t, n, people;
	int[] memo;
	
	Drunken(){
		try {
			t = Integer.parseInt(br.readLine());
		}catch(IOException ie) {}
	}
	void input() {
		try {
			n = Integer.parseInt(br.readLine());
			memo = new int[n+1];
		}catch(IOException ie) {}
	} 
	
	// 재귀 사용 
	void loop(int i, int x, int count) { // i: 라운드, x: 배수 
		if(count==0) return;
		for(int j=1; j*x<=n; j++) {
			if(memo[j*x]==0)// 열려있으면 
				memo[j*x]=1;
			else // 잠겨있으면 
				memo[j*x]=0;
		}
		loop(i, ++x, --count);
	}
	
	// for문 사용 
//	void loop() {
//		for(int i=2; i<=n; i++) {
//			for(int j=1; j*i<=n; j++) {
//				if(memo[i*j]==0) memo[i*j]=1;
//				else memo[i*j]=0;
//			}
//		}
//	}
	void showResult() {
		for(int i=1; i<=n; i++)
			if(memo[i]==0) people++;
		System.out.println(people);
	}
	void clear() {
		people=0;
	}
	void play() {
		while(t-->0) {
			input();
			loop(1, 2, n-1);
//			loop();
			showResult();
			clear();
		}
	}
}

class Main{
   public static void main(String[] args) {
      new Drunken().play();
   }
}

/*
		한 줄 정리  
	처음에 감옥을 한 개씩 모두 연다는 것이니까 memo[]가 0이면 열려있다고 생각. 
	그리고 1씩 증가시키면서 그 수의 배수를 이용하여 0 -> 1, 1 -> 0 으로 변경한 후,
	0의 개수를 출력 
*/