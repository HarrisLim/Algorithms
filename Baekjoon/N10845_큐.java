/*
	[다리 놓기]
	
	문제: 정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
		명령은 총 여섯 가지이다.

		- push X: 정수 X를 큐에 넣는 연산이다.
		- pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
		- size: 큐에 들어있는 정수의 개수를 출력한다.
		- empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
		- front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
		- back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.

	입력: 첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다.
		주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

	출력: 출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.
*/

import java.util.*;

class MyQueue {
	Scanner s = new Scanner(System.in);
	LinkedList<String> queue = new LinkedList<String>();
	int n;
	String num;

	MyQueue(){
		n = s.nextInt();
	}
	void command(String str){
		switch(str){
			case "push": push(); break;
			case "pop": pop(); break;
			case "size": size(); break;
			case "empty": empty(); break;
			case "front": front(); break;
			case "back": back(); break;
		}
	}
	void pop(){
		String head="";
		if(queue.isEmpty()) head="-1";
		else {
			head = queue.get(0);
			queue.remove(0);
		}
		System.out.println(head);
	}
	void push(){
		queue.add(num);
	}
	void front(){
		String head = "";
		if(queue.isEmpty()) head="-1";
		else head = queue.get(0);
		System.out.println(head);
	}
	void back(){
		String tail = "";
		if(queue.size() == 0) tail="-1";
		else tail = queue.get(queue.size()-1);
		System.out.println(tail);
	}
	void empty(){
		int empty=1; // 비어있다면,
		if(queue.size()!=0) empty=0;
		System.out.println(empty);
	}
	void size(){
		System.out.println(queue.size());
	}
	void play(){
		while(n>0){
			String temp = s.next();
			if(temp.equals("push")){
				num = s.next();
				command(temp);
			}else{
				command(temp);
			}
			n--;
		}
	}
}

class Main {
	public static void main(String[] args){
		MyQueue mq = new MyQueue();
		mq.play();
	}
}

/*
		한 줄 정리
	문제에 맞춰서 기능을 구현한다. 
	비교적 쉬운 문제 ! 
	처음에는 Queue interface를 사용했는데, 그러면 back을 구현할 수 없어서 
	ArrayList로 변경했다. 
*/