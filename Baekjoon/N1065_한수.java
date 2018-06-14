package baekjoon;
/*
	[한수]
	
	문제: 어떤 양의 정수 X의 자리수가 등차수열을 이룬다면, 그 수를 한수라고 한다.
	등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다.
	N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오. 

	입력: 첫째 줄에 1,000보다 작거나 같은 자연수 N이 주어진다.
	
	출력: 첫째 줄에 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력한다.
*/

import java.io.*;
import java.util.ArrayList;

class SeqNumber {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	ArrayList<Integer> nums = new ArrayList<Integer>();
	ArrayList<Integer> gaps = new ArrayList<Integer>();
	int n;
	int count;
	
	SeqNumber(){
		try {
			n = Integer.parseInt(br.readLine());
		}catch(IOException ie) {}
	}
	// 자리수마다의 차이 검사 
	void getGap(int num) {
		nums.removeAll(nums);
		while(num!=0) {
			nums.add(num%10);
			num /= 10;
		}
		checkSame();
	}
	// 자리수마다의 차이가 같은지 확인 후 같으면 count++
	void checkSame() {
		gaps.removeAll(gaps);
		boolean flag=false;
		int temp=nums.get(0)-nums.get(1);
		gaps.add(temp);
		int tempSec=0;
		for(int i=2; i<nums.size(); i++) {
			tempSec=nums.get(i-1)-nums.get(i);
			gaps.add(tempSec);
		}
		for(int i=1; i<gaps.size(); i++){
			if(gaps.get(0) == gaps.get(i)) {
				flag=true;
			}else {
				flag=false;
				break;
			}
		}
		if(flag) {
			count++;
		}
	}
	int loop(int begin) {
		if(n<100) return n;
		else if(begin==n+1) return count;
		else {
			getGap(begin);
			loop(begin+1);
			return count;
		}
	}
	void play() {
		if(n<100) {
			System.out.println(loop(1));
		}else {
			System.out.println(loop(100)+99);
		}
	}
}

class Main {
	public static void main(String[] args){
		SeqNumber main = new SeqNumber();
		main.play();
	}
}

/*
		한 줄 정리
	100보다 작을 떄는 입력받은 수가 한수의 개수이므로 100이하를 입력받으면 그대로 출력,
	100 이상을 받으면 100이상에서 한수의 개수를 구하고 +99를 한다. (어차피 100까지는 99인 것을 아니까)
	만약, 101을 입력받았다면 1과 0과 1의 차이를 구하고 같다면 count++를 한다. 다르면 넘어간다.
*/