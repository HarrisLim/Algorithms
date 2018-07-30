package baekjoon;
/*
	[경로 찾기]
	
	문제: 가중치 없는 방향 그래프 G가 주어졌을 때, 모든 정점 (i, j)에 대해서, i에서 j로 가는 경로가 있는지 없는지 구하는 프로그램을 작성하시오.

	입력: 첫째 줄에 정점의 개수 N (1 ≤ N ≤ 100)이 주어진다. 둘째 줄부터 N개 줄에는 그래프의 인접 행렬이 주어진다.
		i번째 줄의 j번째 숫자가 1인 경우에는 i에서 j로 가는 간선이 존재한다는 뜻이고, 0인 경우는 없다는 뜻이다. i번째 줄의 i번째 숫자는 항상 0이다.

	출력: 총 N개의 줄에 걸쳐서 문제의 정답을 인접행렬 형식으로 출력한다.
		정점 i에서 j로 가는 경로가 있으면 i번째 줄의 j번째 숫자를 1로, 없으면 0으로 출력해야 한다.
*/

import java.io.*;
import java.util.*;

class SearchingPath {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int n;
	int[][] map;
	boolean[] visit;
	ArrayList<int[]> list = new ArrayList<int[]>();
	
	SearchingPath(){ // map입력
		try {
			String temp = br.readLine();
			StringTokenizer st = new StringTokenizer(temp, " ");
			n = Integer.parseInt(st.nextToken());
			for(int i=0; i<n; i++) {
				list.add(new int[n]);
			}
			map = new int[n][n];
			visit = new boolean[n];
			for(int i=0; i<n; i++) {
				String line = br.readLine();
				StringTokenizer innerSt = new StringTokenizer(line, " ");
				for(int j=0; j<n; j++) {
					map[i][j] = Integer.parseInt(innerSt.nextToken());
				}
			}
		}catch(IOException ie) {}
	}
	void inputList() { // 입력받은 인접행렬을 인접리스트로 복사
		for(int i=0; i<n; i++) 
			for(int j=0; j<n; j++) 
				if(map[i][j] == 1)
					list.get(i)[j] = map[i][j];
	}
	void initVisit() { // visit배열 false로 초기화 
		for(int i=0; i<n; i++) {
			Arrays.fill(visit, false);
		}
	}
	void dfs(int s, int a, int count) { // s는 행, a는 1이 있는 열.  
		for(int i=0; i<n; i++) {
			if(list.get(a)[i]==1 && visit[i]==false) { // 현재의 좌표가 1이고 아직 방문하지 않았다면, 
				visit[i]=true;
				// 사실 밑의 코드로 속도를 줄이려고 했는데, 오히려 독이 되었다. 반례가 생긴다 
//				if(a < s) {
//					map[s]=map[a];
//					return;
//				}
				map[s][i]=1;
				dfs(s, i, count+1);
			}
		}
	}
	void play() {
		inputList();
		for(int i=0; i<n; i++) {
			initVisit();
			dfs(i, i, 1); // n개 만큼 돈다. 
		}

		for(int[] x: map) {
			for(int z: x) System.out.print(z+" ");
			System.out.println();
		}
	}
}

class Main{
	public static void main(String[] args) {
	  new SearchingPath().play();
	}
}

/*
		한 줄 정리
	나혼자 처음으로 테스트케이스를 모두 맞춘 그래프 문제이다. 그런데 시간초과가 나오고, 시간초과를 고쳤더니 틀렸습니다가 나온다. 
	그래서 질문을 통해서 해결할 수 있었다. 조건을 걸지 않아야하는 부분도 조건을 걸었다. 나름 퍼포먼스가 좋게 나오게 하려고 했던 것이지만,
	독이 되었다. 
	
	이 문제는 인접행렬을 입력받고, 그 인접행렬을 다시 인접행렬로 출력하는 것이다. 
	나는 인접행렬로 입력받은 것을 인접리스트로 만들고, 계산을 해서 인접행렬로 다시 만들어서 출력하였다. 
	
	
	아래와 같은 코드를 입력받는다면,  
	7
	0  0  0  1  0  0  0
	0  0  0  0  0  0  1
	0  0  0  0  0  0  0
	0  0  0  0  1  1  0
	1  0  0  0  0  0  0
	0  0  0  0  0  0  1
	0  0  1  0  0  0  0 
	
	1. 가장 먼저 1행에서 갈 수 있는 노드를 찾는다.   ( 1 0 1 1 1 1 1 )
	  1) 1 -> 4      
	  2) 4 -> 5
	  3) 5 -> 1
	  3.5) 1 -> 4는 중복이니까 4행의 6번째로 go!
	  4) 4 -> 6
	  5) 6 -> 7
	  6) 7 -> 3
	  7) 3 -> X
	2. 2행에서 갈 수 있는 노드를 찾는다.   ( 0 0 1 0 0 0 1 )
	  1) 2 -> 7
	  2) 7 -> 3
	  3) 3 -> X
	3. 3행에서 갈 수 있는 노드를 찾는다.   ( 0 0 0 0 0 0 0 )
	  1) 3 -> X
	4. 4행에서 갈 수 있는 노드를 찾는다.   ( 1 0 1 1 1 1 1 )
	  1) 4 -> 5
	  2) 5 -> 1
	  3) 1 -> 4
	  4) 4 -> 5로 또 가면 중복이니까, 4 -> 6
	  5) 6 -> 7
	  6) 7 -> 3
	  7) 3 -> X
	5. n-1행까지 실행시킨다.
	
	
	그런데 나는 위의 4번에서 결과가 1번처럼 나와서 모두 그런 것인 줄 알고 58~62번 코드를 추가하여 시간을 줄이려고 했지만,
	반례가 생긴다. 밑의 코드가 그 반례이다. 
	4
	0 0 0 1
	0 0 0 0
	1 1 0 0
	0 0 0 0
*/