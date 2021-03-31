package baekjoon;
/*
	[순열 사이클]
	
	문제: 1부터 N까지 정수 N개로 이루어진 순열을 나타내는 방법은 여러가지가 있다.
		예를 들어, 8개의 수로 이루어진 순열 (3, 2, 7, 8, 1, 4, 5, 6)을 배열을 이용해 표현하면 ( 1 2 3 4 5 6 7 8 ) 와 같다.
		                                                                        ( 3 2 7 8 1 4 5 6 )
		또는, Figure 1과 같이 방향 그래프로 나타낼 수도 있다.
		순열을 배열을 이용해  (   1 ...   i ...   n )로 나타냈다면, i에서 πi로 간선을 이어 그래프로 만들 수 있다.
		                 ( PI1 ... PIi ... PIn )
		Figure 1에 나와있는 것 처럼, 순열 그래프 (3, 2, 7, 8, 1, 4, 5, 6) 에는 총 3개의 사이클이 있다.
		이러한 사이클을 "순열 사이클" 이라고 한다. N개의 정수로 이루어진 순열이 주어졌을 때, 순열 사이클의 개수를 구하는 프로그램을 작성하시오.
		
		1 -> 3    2 --      4 -> 8
		^    |    ^  |      ^    |
		|    V    |---      | 6 <-
		5 <- 7
		  		- Figure 1 -
		  		
	입력: 첫째 줄에 테스트 케이스의 개수 T가 주어진다.
	각 테스트 케이스의 첫째 줄에는 순열의 크기 N (2 ≤ N ≤ 1,000)이 주어진다. 둘째 줄에는 순열이 주어지며, 각 정수는 공백으로 구분되어 있다.

	출력: 각 테스트 케이스마다, 입력으로 주어진 순열에 존재하는 순열 사이클의 개수를 출력한다.
*/

import java.io.*;
import java.util.*;

class PermutationCycle {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	ArrayList<Integer> list = new ArrayList<Integer>();
	int t, n; // t: testcase, n: 입력받을 개수  
	int[][] p; // p[0][n-1]: 1~n, p[1][n-1]: 입력받는 수열 
	int[] check; // 방문 확인. -1: 방문 
	int[][] map; // 인접행렬.
	int count, start;
	
	PermutationCycle(){
		try {
			t = Integer.parseInt(br.readLine());
		}catch(IOException ie) {}
	}
	void input() {
		try {
			start=count=0; // start, count 0으로 초기화. 
			n = Integer.parseInt(br.readLine());
			p = new int[n][n];
			map = new int[n][n];
			for(int i=0; i<n; i++)
				p[0][i] = i;
			String line = br.readLine();
			StringTokenizer st = new StringTokenizer(line, " ");
			for(int i=0; i<n; i++) {
				p[1][i] = Integer.parseInt(st.nextToken());
			}
			check = new int[n];
			list.add(0);
		}catch(IOException ie) {}
	}
	void config() {
		for(int i=0;i<n; i++) map[i][p[1][i]-1]=1; // 인접행렬을 만들자. 인접하는 노드가 있다면 1로 표기.
		for(int i=0; i<n; i++) {
			start = i; // 출발점 지정. 
			for(int j=0; j<n; j++) {
				if(check[j]!=-1 && map[i][j]==1) // 방문하지 않고 인접하는 노드가 있다면,
					dfs(j);
			}
		}
	}
	void dfs(int a) { 
		check[a]=-1; // 방문 체크. 
		if(a==start) { // 출발점과 현재점이 같다면, (탐색을 끝까지 마치고 처음 출발점으로 돌아왔다면) 
			count++;
			return;
		}else {
			for(int i=0; i<n; i++) {
				if(check[i]!=-1 && map[a][i]==1) // 방문하지 않고 인접하는 노드가 있다면,
					dfs(i); // 이동 후 탐색 재개.
			}
		}
	}
	void play() {
		while(t-->0) {
			input();
			config();
			System.out.println(count);
		}
	}
}

class Main{
   public static void main(String[] args) {
      new PermutationCycle().play();
   }
}

/*
		한 줄 정리
	그래프에 대한 문제를 많이 안풀어봐서 도저히 감이 오지 않았다. 그래서 찾아봤다. 
	사이클 파악 유형 중 매우 쉬운 문제라는 설명이 있어서 또 부족함을 느낀다. 
	
	입력받은 순열을 index와 비교하면서 싸이클의 개수를 찾는 것이다. 
	3 2 7 8 1 4 5 6을 입력받는다면, 
	
	    1  2  3  4  5  6  7  8
	 1  0  0  1  0  0  0  0  0 
	 2  0  1  0  0  0  0  0  0
	 3  0  0  0  0  0  0  1  0
	 4  0  0  0  0  0  0  0  1
	 5  1  0  0  0  0  0  0  0
	 6  0  0  0  1  0  0  0  0
	 7  0  0  0  0  1  0  0  0
	 8  0  0  0  0  0  1  0  0
	 
	위와 같은 인접행렬을 만들어놓고, 방문여부와 인접여부를 확인하여 dfs를 실행한다.
	만약 1이라면, 1행에서 값이 1인 열(3)을 찾고, 3행에서 1인 열(7)을 찾고, 7행에서 1인 열(5)을 찾고, 5행에서 1인 열(1)을 찾으면
	출발점인 1으로 다시 돌아오니까 count++를 하고 그 dfs문을 중단한다. 그리고 다음 그래프를 탐색한다.
	다음 그래프를 탐색할 때 탐색하지 않은 것들만 해서 탐색한 곳은 다시 방문하지 않는다. 
	
	(이 문제는 인접한 부분들을 먼저 찾는 것보다 인접하는 노드를 끝까지 방문하는 것이니까 dfs를 이용하는 것이 좋다.)
*/