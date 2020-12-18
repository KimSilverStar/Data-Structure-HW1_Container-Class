#include <iostream>
#include <cstdlib>
#include "MyIntVector.h"
using namespace std;

int main()
{
	MyIntVector v1;
	if (v1.is_empty())
		cout << "v1은 비어있는 벡터" << endl << endl;
	else
		cout << "v1은 비어있지 않는 벡터" << endl << endl;

	for (size_t i = 0; i < 10; i++)
		v1.push_back(i + 1);

	cout << "v1: 디폴트 생성자로 생성(Default Constructor)" << endl;
	cout << "v1 capcity: " << v1.capacity() << endl;
	cout << "v1 size: " << v1.size() << endl;
	for (size_t i = 0; i < v1.size(); i++)
		cout << v1[i] << ", ";
	cout << endl << endl;

	MyIntVector v2 = v1;
	if (v2.is_empty())
		cout << "v2는 비어있는 벡터" << endl << endl;
	else
		cout << "v2는 비어있지 않는 벡터" << endl << endl;

	cout << "v2: v1을 복사 생성(Copy Constructor)" << endl;
	cout << "v2 capcity: " << v2.capacity() << endl;
	cout << "v2 size: " << v2.size() << endl;
	for (size_t i = 0; i < v2.size(); i++)
		cout << v2[i] << ", ";
	cout << endl << endl;

	MyIntVector v3;
	for (size_t i = 0; i < 5; i++)
		v3.push_back(i + 10);
	cout << "v3 capcity: " << v3.capacity() << endl;
	cout << "v3 size: " << v3.size() << endl;
	for (size_t i = 0; i < v3.size(); i++)
		cout << v3[i] << ", ";
	cout << endl << endl;

	cout << "v3: v1을 대입 연산 수행(operator=)" << endl;
	v3 = v1;
	cout << "v3 capcity: " << v3.capacity() << endl;
	cout << "v3 size: " << v3.size() << endl;
	for (size_t i = 0; i < v3.size(); i++)
		cout << v3[i] << ", ";
	cout << endl << endl;

	cout << "v3 += v2 수행(operator+=)" << endl;
	v3 += v2;
	cout << "v3 capcity: " << v3.capacity() << endl;
	cout << "v3 size: " << v3.size() << endl;
	for (size_t i = 0; i < v3.size(); i++)
		cout << v3[i] << ", ";
	cout << endl << endl;

	cout << "v3에 pop_back() 5번 수행" << endl;
	for (size_t i = 0; i < 5; i++)
		v3.pop_back();
	cout << "v3 capcity: " << v3.capacity() << endl;
	cout << "v3 size: " << v3.size() << endl;
	for (size_t i = 0; i < v3.size(); i++)
		cout << v3[i] << ", ";
	cout << endl << endl;

	v3.reserve(v3.capacity() * 2);
	cout << "v3에 reserve() 수행: capacity를 2배로 확장" << endl;
	cout << "v3 capcity: " << v3.capacity() << endl;
	cout << "v3 size: " << v3.size() << endl;
	for (size_t i = 0; i < v3.size(); i++)
		cout << v3[i] << ", ";
	cout << endl << endl;

	v3 = -v3;
	cout << "v3 = -v3 수행(Unary operator-)" << endl;
	cout << "v3 capcity: " << v3.capacity() << endl;
	cout << "v3 size: " << v3.size() << endl;
	for (size_t i = 0; i < v3.size(); i++)
		cout << v3[i] << ", ";
	cout << endl << endl;

	v3.clear();
	cout << "v3에 clear() 수행" << endl;
	cout << "v3 capcity: " << v3.capacity() << endl;
	cout << "v3 size: " << v3.size() << endl << endl;

	MyIntVector v4 = v1 + v2;
	cout << "v4: v1 + v2 수행(Binary operator+)" << endl;
	cout << "v4 capcity: " << v4.capacity() << endl;
	cout << "v4 size: " << v4.size() << endl;
	for (size_t i = 0; i < v4.size(); i++)
		cout << v4[i] << ", ";
	cout << endl << endl;

	MyIntVector v5 = v4 - v1;
	cout << "v5: v4 - v1 수행(Binary operator-)" << endl;
	cout << "v5 capcity: " << v5.capacity() << endl;
	cout << "v5 size: " << v5.size() << endl;
	for (size_t i = 0; i < v5.size(); i++)
		cout << v5[i] << ", ";
	cout << endl << endl;

	cout << "내적(스칼라 곱): v1 * v2 = "
		<< v1 * v2 << endl << endl;

	if (v1 == v2)
		cout << "v1과 v2는 size가 같고, 모든 원소들의 값이 서로 같음" << endl << endl;
	else
		cout << "v1과 v2는 size가 다르거나, 원소들의 값이 다름" << endl << endl;

	if (v4 == v5)
		cout << "v4와 v5는 size가 같고, 모든 원소들의 값이 서로 같음" << endl << endl;
	else
		cout << "v4와 v5는 size가 다르거나, 원소들의 값이 다름" << endl << endl;

	return 0;
}