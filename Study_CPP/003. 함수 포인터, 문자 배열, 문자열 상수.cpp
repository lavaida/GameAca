/*

#######################
      함수 포인터
#######################

- 함수를 가리킬 수 있는 포인터.
- 함수의 주소를 갖는 포인터
- 배열의 이름이 그 배열의 시작 주소인 것처럼, 함수 이름도 함수의 시작 주소임.
- 함수는 메모리 영역의 Code 영역에서 Binary 형태(기계어)로 컴파일이 된다?!
- 프로그램 시작(컴파일) 시 생성되고, 프로그램 종료 시 소멸된다.

- Code 영역에 등록되므로 함수 또한 포인터를 통한 호출이 가능하다.

ex. (반환 타입) (* 변수 이름) (매개변수 타입만?!)



####################
  함수 포인터 배열
####################
- 분기문을 만들지 않고도 함수 호출이 가능해짐.

int(*pFunc2[4])(int, int) = { add, sub };
- 배열 안에 함수의 이름을 넣어줌.

그런데, 함수를 구현할 때 매개변수, 리턴값의 타입이 고정된 형태로 되어있음 !!!!
So, 유연하게 사용하기는 어렵다.

#############################################################################################

################
   문자 배열
################

- 문자를 다루는 자료형은 char 형.
- char형은 단일 문자의 데이터를 가진다.
- char형이 여러개 있으면 단일 문자들이 여러 개 붙어서 문자열이 된다 !!!!

So, 문자 배열에 문자열을 저장하게 되면 메모리가 할당되어 직접 저장된다.
- 선언과 동시에 문자열로 초기화 해야 함.

ex. char str[10] = "Hello";

- 10 Bytes가 정적배열의 크기 !!!!
- 문자가 포함된 것은 5 Bytes.
그리고, 추가적으로 문자열의 끝을 의미하는 '\0' 문자 넣어줌 !!!!

ex. char str[] = "Hello";
- 배열의 크기를 설정하지 않고 문자열로 초기화를 진행할 경우
- '\0' 문자를 포함한, (문자열의 길이 + 1)만큼의 크기가 자동적으로 설정된다.


- 각 원소에 char 형 문자가 한개씩 들어있는 배열을 문자 배열이라고 한다.

################################################
- 문자 배열의 이름을 출력하면 문자열이 출력된다.
################################################

- 문자 배열도 index를 통한 접근이 가능하다.
물론, 해당 원소의 값을 변경도 가능함.



########################
  NULL 문자의 중요성
########################

- 문자열의 끝을 의미하는 '\0' 문자를 만날 때까지 메모리를 읽어들인다.
- 쓰레기 값이 나오게 됨.


#############################################################################################

#################
   문자열 상수 - 리터럴 상수 중 하나.
#################

- "Hello" 이런 형태.
- 큰 따옴표 안에 작성된 문자열을 의미함.
- '\0' 문자를 포함한 크기만큼 Data 영역에 할당이 된다 !!!!

ex. char *pStr = "Hello";
- 문자열이 임시로 저장된 메모리 공간의 주소를 대입받음.

- 물론, 인덱스 접근이 가능.
but, 문자열 상수는 원소의 값을 변경 불가능 함.


######################
  문자열 상수의 배열
######################

- 문자열 상수도 (char *)형으로 주소를 가지고 있기 때문에 포인터 배열의 선언이 가능하다.

ex. char *pArr[3] = { "Good", "Day", "Commander" };
- 크기는 주소값 3개니까 12 Bytes !!!!

#############################################################################################

#############################
  문자 배열 vs. 문자열 상수
#############################

- 둘 다 문자열의 시작 주소를 갖고 있다는 동일한 점.

- 문자 배열은 문자 하나 하나를 배열의 원소에 담는 것이다.
그리고, (char *const) 형 ㅋㅋㅋㅋ.

- 문자열 상수는 Data 영역에 등록된 문자열의 시작 주소를 담는 것이다.
그리고, (const char *) 형

#############################################################################################

##########################
    문자열 입력 받기
##########################

- 입력된 문자열은 입력 버퍼에 저장되고
엔터키를 누르면 메모리에 등록되는 것이 아니라 소멸된다.

- 문자열 상수는 Data 영역에 등록이 된다. -> 프로그램 시작 시 할당이 된다.

- cin을 통한 문자열 입력은 Runtime 중에 하는 것.

So, 배열 형태로 받아야 함.
- 문자 배열의 시작 주소를 기점으로 입력 받은 문자를 하나 하나 원소에 복사함.
(문자열의 길이 + 1 <= 배열의 크기)


*/


#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int Add(int a, int b)
{
	return a + b;
}

int Sub(int a, int b)
{
	return a - b;
}

int main(void) {

	cout << "###########################################################" << endl;
	cout << "### 함수 포인터" << endl << endl;

	int num1 = 0, num2 = 0, result = 0;
	int sel = 0;

	cout << "피연산자 2개 입력: ";
	cin >> num1 >> num2;

	cout << "1. 덧셈, 2. 뺄셈" << endl;
	cin >> sel;
	cout << "################" << endl;

	////int(*pFunc)(int a, int b) = NULL; // 매개변수 이름 있어도 되긴 하는데... 의미 없을 듯 !!!!
	int(*pFunc)(int , int) = NULL;


	//switch (sel)
	//{
	//case 1:
	//	pFunc = Add; // 함수 이름을 대입.
	//	break;
	//case 2:
	//	pFunc = Sub;
	//	break;
	//default:
	//	return 0;
	//	break;
	//}

	cout << "연산 결과: " << pFunc(num1, num2) << endl << endl;

	cout << "###########################################################" << endl;
	cout << "### 함수 포인터의 응용(배열)" << endl << endl;

	int(*pFunc2[4])(int, int) = { add, sub }; // 함수 포인터 배열을 이용해서,
						  // 배열의 원소에 함수 이름을 넣어줬음.

	cout << "연산 결과: " << pFunc2[sel = 1](num1, num2) << endl; // 함수 포인터 배열의 원소에 접근해서 인자 넘겨주면 호출 됨.


	cout << "###########################################################" << endl;
	cout << "### 문자열 배열" << endl << endl;

	char str1[10] = "Hello";
	// H e l l o '\0' ㅁ ㅁ ㅁ ㅁ, 총 10 Bytes
	// 실질적인 데이터가 들어있는 것은 5 Bytes
	// 문자열 끝을 의미하는 '\0' 문자 1 Bytes


	cout << "###########################################################" << endl;
	cout << "### NULL 문자의 중요성" << endl << endl;

	char str2[6] = "Hello";
	//str2[5] = 'A'; // 문자열의 끝이어야 하는 마지막 원소에 다른 문자를 넣었으니...
	// 문자열의 끝을 알 수가 없으니까 '\0' 문자를 만날 때까지 읽어들임.


	cout << "###########################################################" << endl;
	cout << "### 문자열 입력 받기" << endl << endl;

	char *pName1;
	//cin >> pName; // 불가능, 메모리 공간이 잡혀있는 것이 아님.
			// cin 메소드는 사용자가 Enter를 치는 순간
			// 입력 스트림 버퍼에서 문자열을 읽어오는 기능임.
			// 새로운 메모리를 할당하는 그런 기능은 없음.

	char pName2[10];
	//cin >> pName2; // 입력하는 문자열의 길이 + 1은 배열의 크기를 넘지 않도록 주의 !!!!

	return 0;
}
