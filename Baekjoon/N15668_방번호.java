/*
	[방 번호]
	
	문제: 택희는 이번에 이사를 했다. 택희의 이번 방 주소는 연세동 연세빌딩 N호이다.
		택희는 방의 문 앞에 예쁜 스티커로 방 번호를 붙이려고 한다.
		하지만 문을 꾸미기 위해 스티커 세트를 사온 택희는 방 번호를 붙이려던 중 무언가 문제가 있음을 알아차렸다.
		스티커 세트에는 0부터 9까지의 정수가 한 장씩만 들어있었는데,
		택희의 방 번호에는 같은 자릿수가 두 개 이상 들어갈 수도 있으므로 정상적인 방법으로는 방 번호를 붙일 수가 없었다.

		이에 택희는 새로운 방법을 생각해냈다. N을 만드는 대신, 두 자연수 A와 B를 만들어 A+B=N이 되도록 하는 것이다.
		단, 스티커 세트에는 0 이상 9 이하의 정수가 하나씩밖에 없어서,
		A와 B에 쓰인 모든 자릿수는 어떤 것도 두 번 이상 쓰여선 안 된다.
		모양이 특이한 스티커이기 때문에, 6과 9를 서로 뒤집어서 쓰는 것 또한 불가능하다.

		예를 들어, 방 번호가 555호라고 하자. 이를 123 + 432로 분할할 경우,
		2와 3이 총 두 번씩 쓰였으므로 불가능한 분할이다.
		99 + 456으로 분할하는 것도 마찬가지로, 9가 두 번 쓰였으므로 불가능하다.
		하지만 512 + 43으로 분할할 경우, 어떤 자릿수도 두 번 이상 쓰이지 않았으므로 가능한 분할이다.

		하지만 택희의 방 번호는 제법 큰 수여서 빠르게 A와 B를 찾아낼 수가 없었다.
		여러분이 한번 택희를 도와줘 보도록 하자.

	입력: 첫 줄에 방 번호 N이 주어진다. (1 ≤ N ≤ 10^9)

	출력: 만일 조건을 만족하는 A와 B가 존재하지 않는다면 첫째 줄에 -1 하나만을 출력한다.
		답이 존재한다면, A + B = N이 되며 문제의 조건을 만족하는 두 자연수 A와 B를 출력 예제 1의 형식에 맞게 출력한다.
		만일 그런 A, B가 여러 가지라면 아무 쌍이나 하나만 출력한다.
*/
import java.util.*;

class RoomNumber{
	Scanner s = new Scanner(System.in);
	int roomNum;
	int A=-1,B=-1;

	void input(){
		roomNum = s.nextInt();
	}
	void calculate(){
		int a=0, b=0;
		b = roomNum/2;
		String bx = b+"";
		if(bx.length()>5){
			b = checkDigit(b);
		}
		a = roomNum-b;
		int bt = b;
		for(int i=0; i<bt; i++){
			if(hasOverlap(a, b)){
				b--;
				a = roomNum-b;
			}else{
				A=a;
				B=b;
				break;
			}
		}
	}
	int checkDigit(int z){
		String zx = z+"";
		int temp = 10-zx.length();
		String ax = "";
		for(int i=0; i<temp; i++){
			ax +="9";
		}
		int a = Integer.parseInt(ax);
		return a;
	}
	boolean hasOverlap(int a, int b){
		int[] ten = new int[10];
		String ax=a+"";
		String bx=b+"";
		for(int i=0; i<ax.length(); i++){
			if(ten[Character.getNumericValue(ax.charAt(i))] == 1){
				return true;
			}
			ten[Character.getNumericValue(ax.charAt(i))] = 1;
		}
		for(int i=0; i<bx.length(); i++){
			if(ten[Character.getNumericValue(bx.charAt(i))] == 1){
				return true;
			}
			ten[Character.getNumericValue(bx.charAt(i))] = 1;;
		}
		return false;
	}
	
	void showResult(){
		if(A==-1) System.out.println(A);
		else System.out.println(A+" + "+B);
	}
	void play(){
		input();
		calculate();
		showResult();
	}
}

class Main{
	public static void main(String[] args){
		RoomNumber rn = new RoomNumber();
		rn.play();
	}
}

/*
		한 줄 정리
	If, 38579
	19289 a의 최소값 5
	19289 b의 최대값 5
	
	만약, 7자리에서 / 2하면
	a와 b가 6자리를 갖고 있으니까, 총 12자리를 쓰겠지 안겹치려면 ?
	그러니까 a는 그냥 놔두고 b를 4자리로 해야지 1~9999처럼.
	이렇게 해야, 시간 초과가 안나.
	
	a의 자릿수가 5보다 작거나 같으면
		b=19289
	6보다 크면
		b=9999 or 999 or 99 or 9 (자릿수 만큼 9를 넣어준다)
	a=N-b
	a랑 b랑 중복검사 
	if 중복된다면, b를 -1
	else A=a, B=b break;
	A=-1; B=-1; // A랑 B는 멤버변수

	이거 너무 어렵다. 20일 정도 걸렸다 ㅎㅎ 
*/