/*
	[방 번호]
	
	문제: 독일 로또는 {1, 2, ..., 49}에서 숫자 6개를 고른다.
		로또 번호를 선택하는데 사용되는 가장 유명한 전략은 49가지 숫자 중 k(k>6)개의 숫자를 골라 
		집합 S를 만든 다음 그 숫자만 가지고 번호를 선택하는 것이다.
		예를 들어, k=8, S={1,2,3,5,8,13,21,34}인 경우 이 집합 S에서 숫자를 고를 수 있는 경우의 수는 총 28가지이다.
		([1,2,3,5,8,13], [1,2,3,5,8,21], [1,2,3,5,8,34], [1,2,3,5,13,21], ..., [3,5,8,13,21,34])
		집합 S와 k가 주어졌을 때, 숫자를 고르는 모든 방법을 구하는 프로그램을 작성하시오.

	입력: 입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 한 줄로 이루어져 있다. 
		첫 번째 숫자는 k (6 < k < 13)이고, 다음 k개 숫자는 집합 S에 포함되는 수이다. S의 원소는 오름차순으로 주어진다.
		입력의 마지막 줄에는 0이 하나 주어진다. 

	출력: 각 테스트 케이스 마다 숫자를 고르는 모든 방법을 출력한다. 이 때, 사전 순으로 출력한다.
		각 테스트 케이스 사이에는 빈 줄을 하나 출력한다.
*/

import java.util.*;

class Lotto {
	Scanner s = new Scanner(System.in);
	int nums[];
	Stack<Integer> st = new Stack<Integer>();
	int k;

	void config(){
		k = s.nextInt();
		nums = new int[k];
		for(int i=0; i<k; i++)
			nums[i] = s.nextInt();
	}
	void showResult(){
		for(int i=0; i<st.size(); i++){
			System.out.print(st.get(i)+" ");
		}
		System.out.println();
	}
	void loop(int n, int r, int idx){
		if(r==0){
			showResult();
			return;
		}else if(n==r){
			for(int i=0; i<n; i++) st.add(nums[idx+i]);
			showResult();
			for(int i=0; i<n; i++) st.pop();
		}else{
			st.add(nums[idx]);
			loop(n-1, r-1, idx+1);
			st.pop();
			loop(n-1, r, idx+1);
		}
	}
	void play(){
		while(true){
			config();
			if(k==0) break;
			loop(k, 6, 0);
			System.out.println();
		}
	}
}

class Main {
	public static void main(String[] args){
		Lotto lo = new Lotto();
		lo.play();
	}
}

/*
		한 줄 정리
	사실, 경우의 수를 어떻게 구해야 하는지 몰라서 인터넷을 엄청 찾아봤다.
	조합, 배열, 순열, 부분집합 등 경우의 수를 구하는 수학적인 방법이 굉장히 많이 있었다. 
	나는 부분집합을 사용하여서 문제를 푸는 것을 참고했다. (나 혼자의 힘으로 풀고 싶었지만, 실력이 부족했다)
	n-1Cr-1, n-1Cr 공식을 이용했다. stack을 사용하였다.
	입력을 다 받고, 재귀함수로 돌려준다.

	여기서 하나 배운 것은, 재귀함수에서 파라미터를 변동시키고 난 후
	return을 하면 다시 그 함수로 돌아갈 떄 위치만 돌아가는 것이 아니라 파라미터 값도 변동 전으로 돌아간다.
	
	당연히 아직 많이 부족하다. 잘해지자 ! 
	http://bumbums.tistory.com/2 (경우의수 설명 링크)
*/