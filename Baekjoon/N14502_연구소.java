package baekjoon;
/*
	[연구소]
	
	문제: 인체에 치명적인 바이러스를 연구하던 연구소에서 바이러스가 유출되었다. 다행히 바이러스는 아직 퍼지지 않았고,
		바이러스의 확산을 막기 위해서 연구소에 벽을 세우려고 한다.
		연구소는 크기가 N×M인 직사각형으로 나타낼 수 있으며, 직사각형은 1×1 크기의 정사각형으로 나누어져 있다.
		연구소는 빈 칸, 벽으로 이루어져 있으며, 벽은 칸 하나를 가득 차지한다. 
		일부 칸은 바이러스가 존재하며, 이 바이러스는 상하좌우로 인접한 빈 칸으로 모두 퍼져나갈 수 있다.
		새로 세울 수 있는 벽의 개수는 3개이며, 꼭 3개를 세워야 한다.
		예를 들어, 아래와 같이 연구소가 생긴 경우를 살펴보자.
          2 0 0 0 1 1 0
          0 0 1 0 1 2 0
          0 1 1 0 1 0 0
          0 1 0 0 0 0 0
          0 0 0 0 0 1 1
          0 1 0 0 0 0 0
          0 1 0 0 0 0 0
		이 때, 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 곳이다. 아무런 벽을 세우지 않는다면, 바이러스는 모든 빈 칸으로 퍼져나갈 수 있다.
		2행 1열, 1행 2열, 4행 6열에 벽을 세운다면 지도의 모양은 아래와 같아지게 된다.
          2 1 0 0 1 1 0
          1 0 1 0 1 2 0
          0 1 1 0 1 0 0
          0 1 0 0 0 1 0
          0 0 0 0 0 1 1
          0 1 0 0 0 0 0
          0 1 0 0 0 0 0
		바이러스가 퍼진 뒤의 모습은 아래와 같아진다.
          2 1 0 0 1 1 2
          1 0 1 0 1 2 2
          0 1 1 0 1 2 2
          0 1 0 0 0 1 2
          0 0 0 0 0 1 1
          0 1 0 0 0 0 0
          0 1 0 0 0 0 0
		벽을 3개 세운 뒤, 바이러스가 퍼질 수 없는 곳을 안전 영역이라고 한다. 위의 지도에서 안전 영역의 크기는 27이다.
		연구소의 지도가 주어졌을 때 얻을 수 있는 안전 영역 크기의 최대값을 구하는 프로그램을 작성하시오.
		
	입력: 첫째 줄에 지도의 세로 크기 N과 가로 크기 M이 주어진다. (3 ≤ N, M ≤ 8)
		둘째 줄부터 N개의 줄에 지도의 모양이 주어진다. 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 위치이다.
		2의 개수는 2보다 크거나 같고, 10보다 작거나 같은 자연수이다.
		빈 칸의 개수는 3개 이상이다.
	
	출력: 첫째 줄에 얻을 수 있는 안전 영역의 최대 크기를 출력한다.
*/

import java.io.*;
import java.util.*;

class Point{
	int x, y;
	Point(int x, int y){
		this.x = x;
		this.y = y;
	}
}
class Lab {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int n, m, ans;
	int[] dx = {-1, 1, 0, 0}; // y와 비교했을 때, 0의 위치가 겹치면 안된다. -1,0: 상. 1,0: 하. 0,-1: 좌. 0,1: 우. 
	int[] dy = {0, 0, -1, 1};
	int[][] map, clonedMap;
	
	Lab(){
		try {
			String temp = br.readLine();
			StringTokenizer st = new StringTokenizer(temp, " ");
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			map = new int[n][m];
			clonedMap = new int[n][m];
			for(int i=0; i<n; i++) {
				String line = br.readLine();
				StringTokenizer innerSt = new StringTokenizer(line, " ");
				for(int j=0; j<m; j++) {
					map[i][j] = Integer.parseInt(innerSt.nextToken());
				}
			}
		}catch(IOException ie) {}
	}
	void cloneMap() {
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				clonedMap[i][j] = map[i][j];
	}
	void go(int cnt) {
		if(cnt==3) { // 벽을 3개 쌓았다면,
			bfs();
			return;
		}
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(clonedMap[i][j]==1 || clonedMap[i][j]==2) continue; // 복사한 Map의 현 좌표가 1(벽)이거나 2(virus)면 점프 !
				clonedMap[i][j]=1; // 복사된 map의 현재 좌표에 벽을 쌓는다. 
				go(cnt+1);  // cnt로 cnt+1을 가져간다. 왜냐면 윗줄에서 벽을 1개 쌓았으니까.
				clonedMap[i][j]=0; // 다시 1을 줬던 자리를 0으로 변경
			}
		}
	}
	void bfs() {
		int[][] tempMap = new int[n][m];
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				tempMap[i][j] = clonedMap[i][j];
				
		Queue<Point> q = new LinkedList<>();
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if(tempMap[i][j]==2) // 현좌표가 virus라면, 
					q.add(new Point(i,j)); // q에 현 좌표 enqueue
		
		while(!q.isEmpty()) {
			Point now = q.remove(); // dequeue
			int x = now.x;
			int y = now.y;
			for(int i=0; i<4; i++) { // 상하좌우를 살펴보기 위해.
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(nx < 0 || nx >= n || ny<0 || ny>=m) continue; // 범위가 벗어나면 점프 !
				if(tempMap[nx][ny]==1 || tempMap[nx][ny]==2) continue; // 현 좌표가 벽 또는 virus라면 점프 !
				tempMap[nx][ny]=2;
				q.add(new Point(nx, ny));
			}
		}
		int cnt=0;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if(tempMap[i][j]==0) ++cnt; // tempMap의 현좌표가 0이라면 cnt +1 
		ans = Math.max(ans, cnt); // 최종적으로, 빈 칸이 가장 많이 남는 것을 구하는 거니까 전체탐색을 하면서 max를 구한다.  
	}
	void play() {
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(map[i][j]==2 || map[i][j]==1) continue; // virus거나 벽이면 점프 ! 
				cloneMap();
				clonedMap[i][j]=1; // 복사된 map의 현재 좌표에 벽을 쌓는다. 
				go(1); // cnt로 1을 가져간다. 왜냐면 윗줄에서 벽을 1개 쌓았으니까. 
				map[i][j]=0; // 다시 1을 줬던 자리를 0으로 변경
			}
		}
		System.out.println(ans);
	}
}

class Main{
	public static void main(String[] args) {
	  new Lab().play();
	}
}

/*
		한 줄 정리
	와, 이거 너무 어렵다. 보고해도 어렵다. 
	
	
      0 0 0 2       0 0 0 2 
      2 1 0 0       2 1 0 0
      0 1 2 0       0 1 2 0
      0 0 1 0       0 0 1 0
      - map -    - clonedMap -
    위와같이 map을 먼저 입력받고, 그 map으로 clonedMap을 만든다.  
    play()에서 행열만큼의 크기를 돌면서, 0(빈칸)일 때 clonedMap을 새로 생성하고, 현 좌표에 1(벽)을 대입한다.
    
    ex) clonedMap으로 보자. 
   	  1* 1* 1* 2      1* 1* 0  2      1* 1* 0  2       1* 1* 0  2      1* 1* 0  2      1* 1* 0  2
   	  2  1  0  0  ->  2  1  1* 0  ->  2  1  0  1*  ->  2  1  0  0  ->  2  1  0  0  ->  2  1  0  0
   	  0  1  2  0      0  1  2  0      0  1  2  0       1* 1  2  0      0  1  2  1*     0  1  2  0
   	  0  0  1  0      0  0  1  0      0  0  1  0       0  0  1  0      0  0  1  0      1* 0  1  0
   	 
      1* 1* 0  2      1* 1* 0  2                       1* 0  1* 2      1* 0  1* 2      1* 0  1* 2
  ->  2  1  0  0  ->  2  1  0  2  -> go() return;  ->  2  1  1* 0  ->  2  1  0  1*  -> 2  1  0  0  -> ...
      0  1  2  0      0  1  2  0                       0  1  2  0      0  1  2  0      1* 1  2  0
      0  1* 1  0      0  0  1  1*                      0  0  1  0      0  0  1  0      0  0  1  0 
	  
	 위의 행열과 같이 쭉쭉 이어진다. 왜 분류에 브루트포스가 있는 지 알겠다. 
	 
    
    1. play()에서 행열을 전체탐색 하면서, 좌표를 1씩 증가시키면서 clonedMap의 현 좌표를 0 -> 1로 변경하고 cnt 1(벽의 개수)을 들고 go()를 실행한다.
    2. go()에서 행열을 전체탐색 하면서, clonedMap의 현재 좌표가 0(빈칸)이라면 1(벽)로 변경하고, cnt+1을 들고 go()를 실행.
    3. 만약 cnt(벽의 개수)가 3개라면, bfs()를 실행.
    4. 여기서 벽을 3개 세운 clonedMap을 tempMap에 복사한다. 
    5. Queue를 만들어, 벽을 3개 세운 tempMap을 전체탐색하면서 2(바이러스)라면 Queue에 현 좌표를 Enqueue. 
    6. 바이러스의 좌표가 들어있는 Queue가 empty할 때까지,
       반복문을 실행하면서 현좌표(바이러스의좌표)의 상하좌우 중 0이 있는 좌표는 2(바이러스)로 감염시키고 2로 감염된 좌표를 다시 Queue에 Enqueue.
    7. Queue가 empty하면, 벽을 3개 세운 tempMap을 전체탐색하면서 0이 있는 개수를 ans와 비교하여 큰값을 ans에 대입한다. 
    8. 이렇게 다시 go()로 가서 마지막에 세웠던 벽을 0(빈칸)으로 만들고, 좌표를 한 칸 이동하고 다시 0(빈칸)이라면 1(벽)으로 변경한다. 
    9. 이렇게 반복한다.
    
   	
*/