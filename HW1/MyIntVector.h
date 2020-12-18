#pragma once
#include <cstdlib>

class MyIntVector
{
public:
	MyIntVector(size_t init_allocated = DF_CAPACITY);	// Default Constructor
	/*
	* Precondition: ���� init_allocated�� 0 �̻�
     �Ǵ� ���ھ��� void �������� ȣ���� ��(����Ʈ �Ű�����)
    * Postcondition: ��ü �Ҵ� ũ�Ⱑ init_allocated ��ŭ��
      �� dynamic array�� ��������� ���� MyIntVector ��ü ����
	*/
	MyIntVector(const MyIntVector& v);		// Copy Constructor
	/*
	* Precondition: ���ڷ� MyIntVector ��ü
	* Postcondition: ���ڷ� ���� MyIntVector ��ü�� Deep Copy�Ͽ�
	  ��ü ����
	*/
	~MyIntVector();		// Destructor
	/*
	* Postcondition: ���� �Ҵ� ���� dynamic array�� �������
	  data�� �޸� ����
	*/

	MyIntVector& operator=(const MyIntVector& v);	// Assignment Operator
	/*
	* Precondition: �ǿ����ڵ��� MyIntVector ��ü
	* Postcondition: ���ڷ� ���� ��ü(���� ���� =�� �����ʿ� ���� ��ü)��
	  Deep Copy�Ͽ� ȣ���� ��ü(���� ���� =�� ���ʿ� ���� ��ü)�� ����.
	 ���� �� ��ü reference ��ȯ => Chaining ���� ����
	*/
	void reserve(size_t new_capacity);
	/*
	* Precondition: ���� new_allocated�� 0 �̻�
	  Postcondition: ���ڷι��� new_allocated ��ŭ�� ���ο� ũ����
	  dynamic array�� �Ҵ��ϰ�, ������ data�� ����� ��ҵ��
	  used(����� ��� ����)�� copy ��.
	  ���� �Ҵ�޴� dynamic array�� ũ�Ⱑ ������ ũ�⺸�� ���� �ʰ� ��.
	*/
	void push_back(int new_entry);
	/*
	* Precondition: ���� new_entry�� int�� ����
	* Postcondition: ���ڷ� ���� new_entry�� dynamic array��
	  �� �ڿ� ��ҷ� �߰�.
	  dynamic array�� �Ҵ�� ������ �� ����, reserve() ����Լ���
	  ȣ���Ͽ� ���� �Ҵ� ������ 2��� ���� �Ҵ��Ͽ� �� ��Ҹ� �߰�
	*/
	void pop_back();
	/*
	* Precondition: dynamic array�� ������� �ʾƾ� ��
	* Postcondition: dynamic array�� �� �ڿ� ����� ��Ҹ� ����
	*/
	size_t capacity() const;
	/*
	* Postcondition: dynamic array�� �Ҵ�� ����
	  (�迭 ����, ��ü ũ��) ��ȯ
	*/
	size_t size() const;
	/*
	* Postcondition: dynamic array�� ����� ��ҵ��� ���� ��ȯ
	*/
	bool is_empty() const;
	/*
	* Postcondition: dynamic array�� ����ִ��� ���θ� ��ȯ
	*/
	void clear();
	/*
	* Postcondition: dynamic array�� ����� ��� ��ҵ��� �����Ͽ�
	  ����ִ� dynamic array�� �����,
	  �Ҵ� ���� ũ��(capacity)�� default capacity(10)�� ���Ҵ� ��.
	  => ���� Default Constructor�� ȣ���� ���·� �ʱ�ȭ
	*/

	void operator+=(const MyIntVector& addend);
	/*
	* Precondition: ���ڷ� MyIntVector ��ü
	* Postcondition: ȣ���� ��ü(+= �������� ���ʿ� ���� ��ü)��
	  dynamic array�� ���ڷ� ���� ��ü addend
	  (+= �������� �����ʿ� ���� ��ü)�� dynamic array ��ҵ���
	  �̾����(append).
	  ȣ�� ��ü�� dynamic array�� �Ҵ� ũ�⸦ �ʰ��ϸ�,
	  reserve() �Լ��� ȣ���Ͽ� ũ�⸦ ������ append ����
	*/
	int& operator[](size_t index);
	/*
	* Precondition: ���� index�� 0 �̻� used(size) �̸�
	* Postcondition: �ش� index ��ġ�� �����
	  dynamic array�� ��� reference ��ȯ
	*/
	int& operator[](size_t index) const;
	/*
	* Precondition: ���� index�� 0 �̻� used(size) �̸�
	* Postcondition: �ش� index ��ġ�� �����
	  dynamic array�� ��� reference ��ȯ
	*/

	MyIntVector operator+(const MyIntVector& v) const;
	/*
	* Precondition: �ǿ������� �� ��ü�� ���� ����� ��� ������ ����
	* Postcondition: �ǿ������� �� ��ü�� ����� ��ҵ��� ����
	  ���� ��������� ����(���� index ��ҵ鳢�� ����)
	  ���ο� MyIntVector ��ü�� �����Ͽ� ��ȯ
	*/
	MyIntVector operator-(const MyIntVector& v) const;
	/*
	* Precondition: �ǿ������� �� ��ü�� ���� ����� ��� ������ ����
	* Postcondition: �ǿ������� �� ��ü�� ����� ��ҵ��� ����
	  ���� ��������� ��(���� index ��ҵ鳢�� ��)
	  ���ο� MyIntVector ��ü�� ��ȯ
	*/
	int operator*(const MyIntVector& v) const;
	/*
	* Precondition: �ǿ������� �� ��ü�� ���� ����� ��� ������ ����
	* Postcondition: �� ��ü�� ����� ��ҵ鿡 ����
	  ����(��Į�� ��)�� ��ȯ
	*/
	bool operator==(const MyIntVector& v) const;
	/*
	* Postcondition: �ǿ������� �� ��ü�� ���� ������ ���θ� ��ȯ.
	  �ǿ������� �� ��ü�� ����� ��� ����(size)�� ����,
	  ����� ��� ������ ���� ������ true�� ��ȯ
	  ����� ��� ����(size)�� �ٸ��ų�,
	  ����� ��� ���� ���� �ٸ��� false�� ��ȯ
	*/

	MyIntVector operator-() const;
	/*
	* Postcondition: �ǿ����� ��ü�� ���� ������ ���ο� ��ü����
	  ��� ��ҵ��� ��ȣ�� �ٲ㼭 �����ϰ�,
	  ��ȣ�� �ٲ� ���ο� ��ü�� ��ȯ
	*/
	void operator()(int num);
	/*
	* Precondition: ���� num�� int�� ����
	* Postcondition: ���� num�� ������ ��ü�� �����
	  ��� ��ҵ��� ���� �ٲ�
	*/

	static const size_t DF_CAPACITY = 10;	// Default Capacity

private:
	int* data;
	size_t allocated;
	size_t used;
};