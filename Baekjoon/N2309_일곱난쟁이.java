/*
	[일곱 난쟁이]

	문제: 왕비를 피해 일곱 난쟁이들과 함께 평화롭게 생활하고 있던 백설공주에게 위기가 찾아왔다. 일과를 마치고 돌아온 난쟁이가 일곱 명이 아닌 아홉 명이었던 것이다.

		아홉 명의 난쟁이는 모두 자신이 "백설 공주와 일곱 난쟁이"의 주인공이라고 주장했다. 뛰어난 수학적 직관력을 가지고 있던 백설공주는, 다행스럽게도 일곱 난쟁이의 키의 합이 100이 됨을 기억해 냈다.

		아홉 난쟁이의 키가 주어졌을 때, 백설공주를 도와 일곱 난쟁이를 찾는 프로그램을 작성하시오.

	입력: 아홉 개의 줄에 걸쳐 일곱 난쟁이의 키가 주어진다. 주어지는 키는 100을 넘지 않는 자연수이며, 아홉 난쟁이의 키는 모두 다르며, 가능한 정답이 여러가지인 경우에는 아무거나 출력한다.

	출력: 일곱 난쟁이의 키를 오름차순으로 출력한다.
*/
	
import java.util.*;

class Main{
	Scanner s = new Scanner(System.in);
	int[] height = new int[9];
	TreeSet<Integer> numbers = new TreeSet<Integer>();
	int total, firNum, secNum;

	void getHeight(){
		for(int i=0; i<9; i++){
			height[i] = s.nextInt();
			if(height[i] >= 100) System.exit(-1);
			numbers.add(height[i]);
		}
		total();
	}
	void total(){
		for(int i=0; i<9; i++){
			total += height[i];
		}
	}
	void keep(){
		int leftNum = total-100;
		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
				if(height[i] == height[j]) continue;
				if(leftNum == (height[i] + height[j])){
					firNum = height[i];
					secNum = height[j];
					//System.out.println("leftNum: "+ leftNum +", firNum: "+ firNum +", secNum: "+ secNum);
					return;
				}
			}
		}
	}
	void show(){
		int temp;
		Iterator<Integer> number = numbers.iterator();
		while(number.hasNext()){
			temp = number.next();
			if(temp == firNum || temp == secNum) continue;
			System.out.println(temp);
		}
	}
	public static void main(String[] args){
		Main m = new Main();
		m.getHeight();
		m.keep();
		m.show();
	}
}