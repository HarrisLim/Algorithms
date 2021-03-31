package baekjoon;
/*
	[택시 기하학]
	
	문제: 19세기 독일 수학자 헤르만 민코프스키는 비유클리드 기하학 중 택시 기하학을 고안했다.
		택시 기하학에서 두 점 T1(x1,y1), T2(x2,y2) 사이의 거리는 다음과 같이 구할 수 있다.
		D(T1,T2) = |x1-x2| + |y1-y2|
		두 점 사이의 거리를 제외한 나머지 정의는 유클리드 기하학에서의 정의와 같다.
		따라서 택시 기하학에서 원의 정의는 유클리드 기하학에서 원의 정의와 같다.
		원: 평면 상의 어떤 점에서 거리가 일정한 점들의 집합
		반지름 R이 주어졌을 때, 유클리드 기하학에서 원의 넓이와, 택시 기하학에서 원의 넓이를 구하는 프로그램을 작성하시오.
	
	입력: 첫째 줄에 반지름 R이 주어진다. R은 10,000보다 작거나 같은 자연수이다.
	
	출력: 첫째 줄에는 유클리드 기하학에서 반지름이 R인 원의 넓이를, 둘째 줄에는 택시 기하학에서 반지름이 R인 원의 넓이를 출력한다.
		넓이는 소수점 여섯째 자리까지 출력한다.
*/

import java.io.*;

class Taxi {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int r;
	double u, ux; // u: 유클리드, ux: 비유클리드 
	
	Taxi(){
		try {
			r = Integer.parseInt(br.readLine());
		}catch(IOException ie) {}
	}
	double calcTaxi() {
//		return ux = ((2*r)*(2*r))/2; // 내 코드. (이것도 된다) 
		return ux = r*r*2; // 답을 본 코드.
	}
	double calcEuclid() {
		return u = (r*r)*Math.PI;
	}
	void showResult() {
		System.out.printf("%.6f", calcEuclid()); // over 1.6
		System.out.println();
		System.out.printf("%.6f",calcTaxi()); 
	}
	void play() {
		showResult();
	}
}

class Main {
	public static void main(String[] args) {
		Taxi main = new Taxi();
		main.play();
	}
}

/*
		한 줄 정리
	원의 넓이 공식
	  - 유클리드 기하학: 반지름^2 x 파이
	  - 택시기하학: 사실 택시기하학에서는 원이 아니고 우리가 알고 있는 정사각형이다. 
	             정사각형의 넓이 공식은 "한 변의 길이 * 한 변의 길이"이다. 
	             위의 식을 보면, ((2*r)*(2*r))/2를 한 것은 정사각형의 반지름을 받은 거니까, *2를 하고 
	             그 *2를 한 값은 한 변의 길이니까, 그 값을 또 곱해줬다. /2를 한 것은 아, 이거 그냥 이렇게 안해도 되네 ?
	             그냥 반지름 * 반지름 * 2하면 되네,, 한 변의 길이 * 한 변의 길이구나.. 너무 어렵게 생각했다. 
	             수학 너무 어렵다..
	            
	참고: https://prezi.com/vxbc0mlqaaij/1/
	     https://m.blog.naver.com/PostView.nhn?blogId=alwaysneoi&logNo=100172516753&proxyReferer=https%3A%2F%2Fwww.google.co.kr%2F
 */