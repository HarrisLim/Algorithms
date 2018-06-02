/*
	[방 번호]
	
	문제: 정보 초등학교 6학년 여학생들은 단체로 2박 3일 수학여행을 가기로 했다.
		학생들이 묵을 숙소에는 방의 정원(방 안에 있는 침대 수)을 기준으로 세 종류의 방이 있으며,
		같은 종류의 방들이 여러 개 있다. 정보 초등학교에서는 학생들에게 이 방들을 배정하되,
		배정된 모든 방에 빈 침대가 없도록 하고자 한다.

		예를 들어, 방의 종류가 5인실, 9인실, 12인실이고 
		6학년 여학생 전체가 113명 이라면, 5인실 4개, 9인실 5개, 12인실 4개를 예약하면 각 방에 남는 침대 없이 배정이 가능하다. 
		또한 12인실은 사용하지 않고 5인실 10개와 9인실 7개만 사용하는 것도 가능하다. 
		그러나 방의 종류가 3인실, 6인실, 9인실이고 6학년 여학생 전체가 112명이라면 빈 침대 없이 방을 배정하는 것은 불가능하다.

		방의 정원을 나타내는 서로 다른 세 자연수와 전체 학생 수를 나타내는 자연수 하나가 주어졌을 때, 
		배정된 모든 방에 빈 침대가 없도록 방 배정이 가능한지를 결정하는 프로그램을 작성하시오. 
		단, 세 종류의 방은 모두 충분한 개수가 있다고 가정하며, 
		위의 예에서와 같이 세 종류의 방을 모두 활용하지 않고 한 종류 또는 두 종류의 방만 이용하여 배정하는 것도 허용한다.

	입력: 표준 입력으로 방의 정원을 나타내는 서로 다른 세 자연수 A, B, C (1 ≤ A < B < C ≤ 50)와 
		전체 학생 수를 나타내는 자연수 N (1 ≤ N ≤ 300)이 공백으로 분리되어 한 줄에 주어진다.

	출력: 빈 침대 없이 배정이 가능할 경우 표준 출력으로 1을, 불가능할 경우 0을 출력한다.
*/
import java.util.*;

class AssignationRoom{
	Scanner s = new Scanner(System.in);
	int a, b, c; // 방의 정원을 나타내는 서로 다른 세 자연수, 하나 or 두개만 사용해도 돼
	int total; // 전체 학생수

	AssignationRoom(){
		a = s.nextInt();
		b = s.nextInt();
		c = s.nextInt();
		total = s.nextInt();
	}
	void play(){
		System.out.println(loop());
	}
	int loop(){
		int x=0;
		for(int i=1; a*i<=total; i++){
			if(a*i==total) return 1;
			for(int j=1; b*j<=total; j++){
				if(b*j==total) return 1;
				if(a*i+b*j==total) return 1;
				for(int h=1; c*h<=total; h++){
					if(a*i+c*j==total) return 1;
					if(b*i+c*j==total) return 1;
					if(c*h==total) return 1;
					x=a*i + b*j + c*h;
					if(total==x) return 1;
				}
			}
		}
		return 0;
	}
}

class Main{
	public static void main(String[] args){
		AssignationRoom ar = new AssignationRoom();
		ar.play();
	}
}

/*
		한 줄 정리
	예쁜 코드로 짜고 싶은데, 아직은 예쁜 코드가 잘 안나온다. 
	완전 브루트포스다. 완전 전체탐색을 해버렸어
	[a], [b], [c], [a, b], [a, c], [b, c], [a, b, c]를 다 검사헀다
*/