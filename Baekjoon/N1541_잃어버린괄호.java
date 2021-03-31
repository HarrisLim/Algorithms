package baekjoon;
/*
	[잃어버린 괄호]
	
	문제: 세준이는 양수와 +, -, 그리고 괄호를 가지고 길이가 최대 50인 식을 만들었다. 그리고 나서 세준이는 괄호를 모두 지웠다.
		그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만드려고 한다.
		괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.
		
	입력: 첫째 줄에 식이 주어진다. 식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로 이루어져 있고, 가장 처음과 마지막 문자는 숫자이다.
		그리고 연속해서 두 개 이상의 연산자가 나타나지 않고, 5자리 이상 연속되는 숫자는 없다. 수는 0으로 시작할 수 있다.
	
	출력: 첫째 줄에 정답을 출력한다. 
*/

import java.io.*;

class LostBracket {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	String[] arr1, arr2;
	String line;
	
	LostBracket(){
		try {
			line = br.readLine();
		}catch(IOException ie) {}
	}
	int test2(){
		int sum = 0;
		arr1 = line.split("\\-");
		for(int i=0; i<arr1.length; i++) {
			arr2 = arr1[i].split("\\+");
			int tempsum = 0;
			for(String z :arr2) tempsum+=Integer.parseInt(z);
			if(i==0) tempsum*= -1; // +니까 -괄호로 묶어준 역할을 하는 것. 
			sum -= tempsum;
		}
		return sum;
	}
	void play() {
		System.out.println(test2());
	}
}

class Main{
	public static void main(String[] args) {
	  new LostBracket().play();
	}
}

/*
		한 줄 정리
	어려운 문제는 아닌 것 같은데, +가 연속으로 나왔을 떄, 해결 방법을 몰랐다. 
	55-50+40+20+30-90이 있다면, 
	-50과 +30까지 괄호를 묶어야 하지만, 내가 원래 하던 코드로는 -50+40만 괄호가 묶였다. 
	또한, -50과 +40을 빼고 그 값에서 +20을 또 빼야되는데, 도저히 문자열처리(?)를 어떻게 해야할지 몰랐다.
	이틀정도 고민하다가 찾아봤는데, 이 문제를 푼 다른 사람들은 거의 다 정규식을 사용했다.  
	
	-가 나오면 다음 -가 나올 때까지의 값을 더하면 되니까, 
	-단위로 split으로 나누고, 나눈 값이 들어간 배열을 다시 +단위로 split을 이용하여 배열로 나눈다.
	   (arr1 = line.split("\\-");  arr2 = arr1[i].split("\\+");
	+단위로 나눈 배열을 모두 더하고 -단위로 나눈 값과 뺀다.
	   (sum -= tempsum)
	 
	왜 이것을 내가 생각하지 못했을까, 완전 새로운 문제다 나에겐 !! 
	
*/