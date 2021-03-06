/*

#################################
   이차원 배열의 선언과 초기화
#################################

(자료형) (변수 이름) [행의 수_세로][열의 수_가로]

ex. int arr6[2][3];

2 by 3 행렬처럼 생각하면 됨...

  1 2 3 열
1 ㅁㅁㅁ
2 ㅁㅁㅁ 이런 형태 !!!!
행

but, 이차원 배열의 원소도 메모리 공간에 연속적으로 할당되므로,
첫 번째 행부터 순서대로 메모리 공간을 가진다 !!!!

1행    2행
ㅁㅁㅁ ㅁㅁㅁ
1 2 3  1 2 3 열

그런데, 실제로 index는 "0"부터 시작하기 때문에, 편의상 저렇게 명칭하고 계산실수 없도록 할 것 !!!!



#############
 초기화 방법
#############

case 1. int arr[2][3]; // 쓰레기 값으로 초기화

case 2. int arr[2][3] = {}; // 모든 원소가 0으로 초기화

case 3. int arr[2][3] = { 1, 2, }; // 메모리 공간의 첫 번째 원소부터 초기화, 나머지 부분은 자동으로 "0"

case 4. int arr[2][3] = {
				{ 1, 2, 3 },
				{ 4, 5, 6 }
			}; // 직관적인 초기화 방법

######################################################################################################


####################################
   이차원 배열의 이름에 대한 의미
####################################

int arr[2][3];

- 1행 1열의 원소의 시작 주소를 가지는 포인터임.
- 그리고, 이차원 배열의 이름은 더블 포인터가 아님.
(포인터형 선언시 주의가 필요함, 물론 매개변수도 마찬가지 !!!!)

왜냐하면, 이차원 배열의 이름이 가지는 주소의 메모리 공간에는 크기가 3인 일차원 배열의 주소가 들어있음
그러니까... 행 주소를 가지고 있음 !!!!
그 크기 만큼에 해당하는 정해진 기본 자료형이 없으니까 새로운 형태로 만들어줘야함.

####################################################### 수정할 것

but, 배열 전체의 규모를 가리키는 것과 같다.
- arr[2][3]은 int형 3개의 배열이 2개 있는 것과 같으니 4 * 3 * 2 = 24


arr[0], arr[1] 의 의미
- 각 행을 의미하는데, 행의 첫 번째 원소의 주소를 가리키고 크기도 행 전체의 크기를 의미한다.
- arr[2][3]에서는 int형 3개의 배열 1개를 의미하는 것과 같으니 4 * 3 * 1 = 12


######################################################################################################

####################################
####################################
   이차원 배열 이름의 포인터 연산
####################################
####################################

int arr[2][3];

이차원 배열의 이름 "arr"은 배열의 시작 주소이다.
그렇지만, 그 주소는 첫 번째 행의 주소를 의미하기도 하고, 첫 번째 행의 첫 번째 열의 원소의 주소를 의미하긴 한데...
- 이차원 배열의 이름은 배열 전체를 대상으로 하기 때문에 약간의 의미가 다름.
- 크기를 찍어보면 "4 * 3 * 2 = 24"
but, 저장하고 있는 값은 첫 번째 행의 주소야 !!!!

"arr + 1" 수행 시 증가되는 값
- 이차원 배열의 이름은 실질적으로 첫 번째 행을 가리키고 있는 것이므로,
포인터를 이용한 증감 연산 수행 시, 행 단위 연산을 하게 된다 !!!!
- 그래서, 이차원 배열의 포인터 형을 선언할 시 맨 첫 번째 index만 생략 가능하고 크기를 명시해야 한다.
(예제에서는 int형 3개짜리 일차원 배열의 크기인 "4 * 3 = 12"만큼의 증감이 이루어진다.)


"*arr" 수행 시, 당연히 이차원 배열은 첫 번째 행을 가리키고 있으므로, 첫 번째 행의 주소값.
- 크기를 찍어보면 "4 * 3 = 12"

"**arr" 수행 시, 첫 번째 행의 첫 번째 열의 원소를 가리키고 있으므로 해당 값.
- 크기를 찍어보면 "4"


결국엔 같은 주소라고 해도, 가리키고 있는 대상이 무엇인지에 따라 크기가 다르다.
- 무조건 주소값이라고 해서 "4Bytes"인 건 기본 자료형을 대상으로...
- 배열에서는 의미가 다름...

######################################################################################################

###############################
###############################
이차원 배열의 포인터 형
###############################
###############################

(자료형) (* 변수명) [열의 인덱스의 크기]
- 실제로, 다차원 배열 같은 경우 맨 왼쪽 첫 번째 index의 크기를 제외한 나머지를 명시해야
포인터 연산 시 증감하는 바이트 수를 결정할 수 있다 !!!!

ex. int arr[2][3];
int (*ptr)[3] = arr;

- 소괄호를 꼭 써야함.
(소괄호가 없으면 int *형 포인터 배열을 의미하니까 !!!!)


######################################################################################################


################################
삼차원 배열의 선언과 초기화
################################


ex. 깊이, 행, 열
int arr9[2][3][4] = {
	{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12}
	},
	{
		{13, 14, 15, 16},
		{17, 18, 19, 20},
		{21, 22, 23, 24}
	}
};

######################################################################################################

*/

#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
	cout << "###########################################################" << endl;
	cout << "### 이차원 배열의 이름의 의미" << endl << endl;

	int arr7[2][3] = { 1, 2, 3, 4, 5, };

	cout << arr7 << endl;
	cout << "sizeof(arr7): " << sizeof(arr7) << endl; // 배열 전체의 (Byte 단위) 크기
	cout << "sizeof(arr7[0]): " << sizeof(arr7[0]) << endl; // 행의 크기

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "&arr7[" << i << "][" << j << "]: " << &arr7[i][j] << " ";
		}
		cout << endl;
	}


	cout << "###########################################################" << endl;
	cout << "### 이차원 배열의 포인터 연산" << endl << endl;

	int arr8[2][3] = { 1, 2, 3, 4, 5, 6 };
	int (*ptr)[3] = arr8 + 1; // 이차원 배열의 포인터 형, 두 번째 행을 가리키고 있음.
	
	cout << "arr8: " << arr8 << endl; // 배열의 시작, 배열 전체를 의미함, 실질적으로 배열의 첫 행을 가리킴.
	cout << "&arr8: " << &arr8 << endl; // 배열의 이름의 주소를 담고 있는 메모리 공간의 주소
	cout << "sizeof(arr8): " << sizeof(arr8) << endl; // 그래서 배열 전체의 크기 24 Bytes
	cout << "sizeof(&arr8): " << sizeof(&arr8) << endl; // 당연히 변수의 주소값은 4Bytes
	cout << "arr8 + 1: " << arr8 + 1 << endl; // 12만큼 증가 했다고???! 다음 행을 가리키네.
						  // 포인터 연산을 수행하고 나면 일반 주소값처럼 됨.
						  // 더이상 이차원 배열의 의미가 없음.
	cout << "sizeof(arr8 + 1): " << sizeof(arr8 + 1) << endl << endl; // 그래서 4Bytes
	
	
	cout << "*(arr8 + 1): " << *(arr8 + 1) << endl; // *(arr8 + 1) = arr8[1]
	cout << (*(arr8 + 1) + 1) << endl; // (*(arr8 + 1) + 1) = arr8[1][1]
	
	// 주소 찍어 봄.
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << &arr8[i][j] << '\t';
		}
		cout << endl;
	}

	cout << "###########################################################" << endl;
	cout << "### 정리(이차원 배열 포인터 연산)" << endl << endl;

	int arr9[2][3] = { 1, 2, 3, 4, 5, 6 };

	cout << "arr9: "<<arr9 << endl; // 이차원 배열 전체를 의미하고, 이차원 배열 시작 주소
									// 크기는 24
									// 실질적으로 가리키고 있는 것은 첫 행의 주소, 행 단위 연산을 할 것임.
	cout << "*arr9: "<<*arr9 << endl; // 첫 행의 주소 arr9[0]
									  // 크기는 12
									  // 실질적으로 가리키고 있는 것은 첫 행의 첫열 주소, 열 단위 연산을 할 것임.
									  // 그래서 Deferencing을 하면 값을 저장하고 있는
	cout << "**arr9: "<<**arr9 << endl << endl; // 첫행 첫열의 값 arr9[0][0], 얘는 포인터가 아니라 값을 저장하는 변수임.
												// 크기는 4

	cout << "###########################################################" << endl;


	return 0;
}
