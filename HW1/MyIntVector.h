#pragma once
#include <cstdlib>

class MyIntVector
{
public:
	MyIntVector(size_t init_allocated = DF_CAPACITY);	// Default Constructor
	/*
	* Precondition: 인자 init_allocated가 0 이상
     또는 인자없이 void 형식으로 호출할 것(디폴트 매개변수)
    * Postcondition: 전체 할당 크기가 init_allocated 만큼인
      빈 dynamic array를 멤버변수로 갖는 MyIntVector 객체 생성
	*/
	MyIntVector(const MyIntVector& v);		// Copy Constructor
	/*
	* Precondition: 인자로 MyIntVector 객체
	* Postcondition: 인자로 받은 MyIntVector 객체를 Deep Copy하여
	  객체 생성
	*/
	~MyIntVector();		// Destructor
	/*
	* Postcondition: 동적 할당 받은 dynamic array인 멤버변수
	  data를 메모리 해제
	*/

	MyIntVector& operator=(const MyIntVector& v);	// Assignment Operator
	/*
	* Precondition: 피연산자들이 MyIntVector 객체
	* Postcondition: 인자로 받은 객체(대입 연산 =의 오른쪽에 오는 객체)를
	  Deep Copy하여 호출한 객체(대입 연산 =의 왼쪽에 오는 객체)에 복사.
	 복사 후 객체 reference 반환 => Chaining 연산 가능
	*/
	void reserve(size_t new_capacity);
	/*
	* Precondition: 인자 new_allocated가 0 이상
	  Postcondition: 인자로받은 new_allocated 만큼의 새로운 크기의
	  dynamic array를 할당하고, 기존의 data에 저장된 요소들과
	  used(저장된 요소 개수)를 copy 함.
	  새로 할당받는 dynamic array의 크기가 기존의 크기보다 작지 않게 함.
	*/
	void push_back(int new_entry);
	/*
	* Precondition: 인자 new_entry가 int형 정수
	* Postcondition: 인자로 받은 new_entry를 dynamic array의
	  맨 뒤에 요소로 추가.
	  dynamic array에 할당된 공간이 꽉 차면, reserve() 멤버함수를
	  호출하여 기존 할당 공간의 2배로 새로 할당하여 새 요소를 추가
	*/
	void pop_back();
	/*
	* Precondition: dynamic array가 비어있지 않아야 함
	* Postcondition: dynamic array의 맨 뒤에 저장된 요소를 삭제
	*/
	size_t capacity() const;
	/*
	* Postcondition: dynamic array에 할당된 공간
	  (배열 길이, 전체 크기) 반환
	*/
	size_t size() const;
	/*
	* Postcondition: dynamic array에 저장된 요소들의 개수 반환
	*/
	bool is_empty() const;
	/*
	* Postcondition: dynamic array가 비어있는지 여부를 반환
	*/
	void clear();
	/*
	* Postcondition: dynamic array에 저장된 모든 요소들을 삭제하여
	  비어있는 dynamic array로 만들고,
	  할당 공간 크기(capacity)를 default capacity(10)로 재할당 함.
	  => 최초 Default Constructor를 호출한 상태로 초기화
	*/

	void operator+=(const MyIntVector& addend);
	/*
	* Precondition: 인자로 MyIntVector 객체
	* Postcondition: 호출한 객체(+= 연산자의 왼쪽에 오는 객체)의
	  dynamic array에 인자로 받은 객체 addend
	  (+= 연산자의 오른쪽에 오는 객체)의 dynamic array 요소들을
	  이어붙임(append).
	  호출 객체의 dynamic array가 할당 크기를 초과하면,
	  reserve() 함수를 호출하여 크기를 넓히고 append 수행
	*/
	int& operator[](size_t index);
	/*
	* Precondition: 인자 index가 0 이상 used(size) 미만
	* Postcondition: 해당 index 위치에 저장된
	  dynamic array의 요소 reference 반환
	*/
	int& operator[](size_t index) const;
	/*
	* Precondition: 인자 index가 0 이상 used(size) 미만
	* Postcondition: 해당 index 위치에 저장된
	  dynamic array의 요소 reference 반환
	*/

	MyIntVector operator+(const MyIntVector& v) const;
	/*
	* Precondition: 피연산자인 두 객체가 서로 저장된 요소 개수가 동일
	* Postcondition: 피연산자인 두 객체에 저장된 요소들의 값을
	  서로 산술적으로 더한(같은 index 요소들끼리 더한)
	  새로운 MyIntVector 객체를 생성하여 반환
	*/
	MyIntVector operator-(const MyIntVector& v) const;
	/*
	* Precondition: 피연산자인 두 객체가 서로 저장된 요소 개수가 동일
	* Postcondition: 피연산자인 두 객체에 저장된 요소들의 값을
	  서로 산술적으로 뺀(같은 index 요소들끼리 뺀)
	  새로운 MyIntVector 객체를 반환
	*/
	int operator*(const MyIntVector& v) const;
	/*
	* Precondition: 피연산자인 두 객체가 서로 저장된 요소 개수가 동일
	* Postcondition: 두 객체에 저장된 요소들에 대한
	  내적(스칼라 곱)을 반환
	*/
	bool operator==(const MyIntVector& v) const;
	/*
	* Postcondition: 피연산자인 두 객체가 서로 같은지 여부를 반환.
	  피연산자인 두 객체가 저장된 요소 개수(size)가 같고,
	  저장된 요소 값들이 서로 같으면 true를 반환
	  저장된 요소 개수(size)가 다르거나,
	  저장된 요소 값이 서로 다르면 false를 반환
	*/

	MyIntVector operator-() const;
	/*
	* Postcondition: 피연산자 객체를 복사 생성한 새로운 객체에서
	  모든 요소들의 부호를 바꿔서 저장하고,
	  부호를 바꾼 새로운 객체를 반환
	*/
	void operator()(int num);
	/*
	* Precondition: 인자 num이 int형 정수
	* Postcondition: 인자 num의 값으로 객체에 저장된
	  모든 요소들의 값을 바꿈
	*/

	static const size_t DF_CAPACITY = 10;	// Default Capacity

private:
	int* data;
	size_t allocated;
	size_t used;
};