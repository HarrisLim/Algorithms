/*
	[윷놀이]
	
	문제: 우리나라 고유의 윷놀이는 네 개의 윷짝을 던져서 배(0)와 등(1)이 나오는 숫자를 세어
		도, 개, 걸, 윷, 모를 결정한다. 
		네 개 윷짝을 던져서 나온 각 윷짝의 배 혹은 등 정보가 주어질 때
		도(배 한 개, 등 세 개), 개(배 두 개, 등 두 개), 걸(배 세 개, 등 한 개), 윷(배 네 개), 모(등 네 개) 중
		어떤 것인지를 결정하는 프로그램을 작성하라.
		
	입력: 첫째 줄부터 셋째 줄까지 각 줄에 각각 한 번 던진 윷짝들의 상태를 나타내는
		네 개의 정수(0 또는 1)가  빈칸을 사이에 두고 주어진다.

	출력: 첫째 줄부터 셋째 줄까지 한 줄에 하나씩 결과를  도는 A, 개는 B, 걸은 C, 윷은 D, 모는 E로 출력 한다.
*/

import java.util.*;

class Game {
	Scanner s = new Scanner(System.in);
	int[] stick = new int[4];
	int count;
	// A:도  B:개  C:걸  D:윷  E:모
	String result;

	void input(){
		for(int i=0; i<4; i++)
			stick[i] = s.nextInt();
	}
	void check(){
		for(int s: stick)
			if(s==0)
				count++;
	}
	void showResult(){
		switch(count){
			case 0 : result="E"; break;
			case 1 : result="A"; break;
			case 2 : result="B"; break;
			case 3 : result="C"; break;
			case 4 : result="D"; break;
		}
	}
	void play(){
		for(int i=0; i<3; i++){
			input();
			check();
			showResult();
			System.out.println(result);
			count=0;
		}
	}
}

class Main {
	public static void main(String[] args) {
		Game g = new Game();
		g.play();
	}
}

/*
		한 줄 정리
	- 0(배)가 하나면 도, 둘이면 개, 셋이면 걸, 넷이면 윷 
	- 1(등)이 네개면 모 == 0(배)가 0개                               
*/