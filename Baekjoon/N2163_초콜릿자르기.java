package baekjoon;
/*
	[초콜릿 자르기]
	
	문제: 정화는 N×M 크기의 초콜릿을 하나 가지고 있다. 초콜릿은 금이 가 있는 모양을 하고 있으며, 그 금에 의해 N×M개의 조각으로 나눠질 수 있다.
		초콜릿의 크기가 너무 크다고 생각한 그녀는 초콜릿을 친구들과 나눠 먹기로 했다. 
		이를 위해서 정화는 초콜릿을 계속 쪼개서 총 N×M개의 조각으로 쪼개려고 한다.
		초콜릿을 쪼갤 때에는 초콜릿 조각을 하나 들고, 적당한 위치에서 초콜릿을 쪼갠다. 초콜릿을 쪼갤 때에는 금이 가 있는 위치에서만 쪼갤 수 있다.
		이와 같이 초콜릿을 쪼개면 초콜릿은 두 개의 조각으로 나눠지게 된다. 이제 다시 이 중에서 초콜릿 조각을 하나 들고, 쪼개는 과정을 반복하면 된다.
		초콜릿을 쪼개다보면 초콜릿이 녹을 수 있기 때문에, 정화는 가급적이면 초콜릿을 쪼개는 횟수를 최소로 하려 한다.
		초콜릿의 크기가 주어졌을 때, 이를 1×1 크기의 초콜릿으로 쪼개기 위한 최소 쪼개기 횟수를 구하는 프로그램을 작성하시오.

	입력: 첫째 줄에 두 정수 N, M(1≤N, M≤300)이 주어진다.

	출력: 첫째 줄에 답을 출력한다.
*/

import java.io.*;
import java.util.*;

class DivideChocolate {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int n, m;
	
	DivideChocolate(){
		try {
			String line = br.readLine();
			StringTokenizer st = new StringTokenizer(line ," ");
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
		}catch(IOException ie) {}
	}
	void play() {
		if (n==m) System.out.println((n-1)+((m-1)*n));
		else System.out.println((n-1)+((m-1)*n));
	}
}

class Main{
	public static void main(String[] args) {
	  new DivideChocolate().play();
	}
}

/*
		한 줄 정리
	규칙을 찾고 찾다가 찾았다.
    
    3x4(nxm) 크기의 초콜릿이 있다.  
      -------------   
      |  |  |  |  |
      -------------
      |  |  |  |  |
      -------------
      |  |  |  |  |
      -------------
      
    1. 행 단위로 나눈다. (2번으로 한 행씩 나눌 수 있다. 여기서 2는 입력받은 n의 -1이다)
    2. 하나의 행을 열 단위로 나눈다. (3번으로 하나의 행을 한조각 한조각 나눌 수 있다. 여기서 3은 입력받은 m의 -1이다.)
    3. 그리고 하나의 행을 열 단위로 나누는 것을 행의 크기만큼 해줘야하니까, n을 곱한다.   
*/