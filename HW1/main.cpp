#include <iostream>
#include <cstdlib>
#include "MyIntVector.h"
using namespace std;

int main()
{
	MyIntVector v1;
	if (v1.is_empty())
		cout << "v1�� ����ִ� ����" << endl << endl;
	else
		cout << "v1�� ������� �ʴ� ����" << endl << endl;

	for (size_t i = 0; i < 10; i++)
		v1.push_back(i + 1);

	cout << "v1: ����Ʈ �����ڷ� ����(Default Constructor)" << endl;
	cout << "v1 capcity: " << v1.capacity() << endl;
	cout << "v1 size: " << v1.size() << endl;
	for (size_t i = 0; i < v1.size(); i++)
		cout << v1[i] << ", ";
	cout << endl << endl;

	MyIntVector v2 = v1;
	if (v2.is_empty())
		cout << "v2�� ����ִ� ����" << endl << endl;
	else
		cout << "v2�� ������� �ʴ� ����" << endl << endl;

	cout << "v2: v1�� ���� ����(Copy Constructor)" << endl;
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

	cout << "v3: v1�� ���� ���� ����(operator=)" << endl;
	v3 = v1;
	cout << "v3 capcity: " << v3.capacity() << endl;
	cout << "v3 size: " << v3.size() << endl;
	for (size_t i = 0; i < v3.size(); i++)
		cout << v3[i] << ", ";
	cout << endl << endl;

	cout << "v3 += v2 ����(operator+=)" << endl;
	v3 += v2;
	cout << "v3 capcity: " << v3.capacity() << endl;
	cout << "v3 size: " << v3.size() << endl;
	for (size_t i = 0; i < v3.size(); i++)
		cout << v3[i] << ", ";
	cout << endl << endl;

	cout << "v3�� pop_back() 5�� ����" << endl;
	for (size_t i = 0; i < 5; i++)
		v3.pop_back();
	cout << "v3 capcity: " << v3.capacity() << endl;
	cout << "v3 size: " << v3.size() << endl;
	for (size_t i = 0; i < v3.size(); i++)
		cout << v3[i] << ", ";
	cout << endl << endl;

	v3.reserve(v3.capacity() * 2);
	cout << "v3�� reserve() ����: capacity�� 2��� Ȯ��" << endl;
	cout << "v3 capcity: " << v3.capacity() << endl;
	cout << "v3 size: " << v3.size() << endl;
	for (size_t i = 0; i < v3.size(); i++)
		cout << v3[i] << ", ";
	cout << endl << endl;

	v3 = -v3;
	cout << "v3 = -v3 ����(Unary operator-)" << endl;
	cout << "v3 capcity: " << v3.capacity() << endl;
	cout << "v3 size: " << v3.size() << endl;
	for (size_t i = 0; i < v3.size(); i++)
		cout << v3[i] << ", ";
	cout << endl << endl;

	v3.clear();
	cout << "v3�� clear() ����" << endl;
	cout << "v3 capcity: " << v3.capacity() << endl;
	cout << "v3 size: " << v3.size() << endl << endl;

	MyIntVector v4 = v1 + v2;
	cout << "v4: v1 + v2 ����(Binary operator+)" << endl;
	cout << "v4 capcity: " << v4.capacity() << endl;
	cout << "v4 size: " << v4.size() << endl;
	for (size_t i = 0; i < v4.size(); i++)
		cout << v4[i] << ", ";
	cout << endl << endl;

	MyIntVector v5 = v4 - v1;
	cout << "v5: v4 - v1 ����(Binary operator-)" << endl;
	cout << "v5 capcity: " << v5.capacity() << endl;
	cout << "v5 size: " << v5.size() << endl;
	for (size_t i = 0; i < v5.size(); i++)
		cout << v5[i] << ", ";
	cout << endl << endl;

	cout << "����(��Į�� ��): v1 * v2 = "
		<< v1 * v2 << endl << endl;

	if (v1 == v2)
		cout << "v1�� v2�� size�� ����, ��� ���ҵ��� ���� ���� ����" << endl << endl;
	else
		cout << "v1�� v2�� size�� �ٸ��ų�, ���ҵ��� ���� �ٸ�" << endl << endl;

	if (v4 == v5)
		cout << "v4�� v5�� size�� ����, ��� ���ҵ��� ���� ���� ����" << endl << endl;
	else
		cout << "v4�� v5�� size�� �ٸ��ų�, ���ҵ��� ���� �ٸ�" << endl << endl;

	return 0;
}