#include <iostream>
#include <algorithm>
#include "MyIntVector.h"
using namespace std;

MyIntVector::MyIntVector(size_t init_allocated)
	: used(0), allocated(init_allocated)
{
	if (init_allocated < 0) {
		cout << "size_t error" << endl;
		exit(-1);
	}
	data = new int[allocated];
}

MyIntVector::MyIntVector(const MyIntVector& v)
	: allocated(v.allocated), used(v.used)
{
	data = new int[allocated];
	copy(v.data, v.data + v.used, data);
}

MyIntVector::~MyIntVector()
{
	if (data != NULL)
		delete[] data;
}

MyIntVector& MyIntVector::operator=(const MyIntVector& v)
{
	if (this == &v)
		return *this;

	if (allocated != v.allocated)
	{
		delete[] data;
		allocated = v.allocated;
		data = new int[allocated];
	}

	used = v.used;
	copy(v.data, v.data + v.allocated, data);
	return *this;
}

void MyIntVector::reserve(size_t new_allocated)
{
	if (new_allocated < 0) {
		cout << "size_t error" << endl;
		exit(-1);
	}

	if (new_allocated <= allocated)
		return;

	int* larger_array = new int[new_allocated];
	copy(data, data + used, larger_array);
	delete[] data;
	data = larger_array;
	allocated = new_allocated;
}

void MyIntVector::push_back(int new_entry)
{
	if (used == allocated)
		reserve(allocated * 2);
	data[used++] = new_entry;
}

void MyIntVector::pop_back()
{
	if (used == 0) {
		cout << "Empty Vector" << endl;
		exit(-2);
	}
	data[used - 1] = NULL;
	used--;
}

size_t MyIntVector::capacity() const { return allocated; }

size_t MyIntVector::size() const { return used; }

bool MyIntVector::is_empty() const
{
	if (used == 0)
		return true;
	else
		return false;
}

void MyIntVector::clear()
{
	delete[] data;
	allocated = 10;
	used = 0;
	data = new int[allocated];
}

void MyIntVector::operator+=(const MyIntVector& addend)
{
	if (used + addend.used > allocated)
		reserve(used + addend.used);

	copy(addend.data, addend.data + addend.used, data + used);
	used += addend.used;
}

int& MyIntVector::operator[](size_t index)
{
	if (index < 0 || index >= used) {
		cout << "Out of range" << endl;
		exit(-3);
	}
	return data[index];
}

int& MyIntVector::operator[](size_t index) const
{
	if (index < 0 || index >= used) {
		cout << "Out of range" << endl;
		exit(-3);
	}
	return data[index];
}

MyIntVector MyIntVector::operator+(const MyIntVector& v) const
{
	if (used != v.used) {
		cout << "Size is not same" << endl;
		exit(-4);
	}

	MyIntVector res(allocated);
	for (size_t i = 0; i < used; i++)
		res.push_back(data[i] + v[i]);
	return res;
}

MyIntVector MyIntVector::operator-(const MyIntVector& v) const
{
	if (used != v.used) {
		cout << "Size is not same" << endl;
		exit(-4);
	}

	MyIntVector res(allocated);
	for (size_t i = 0; i < used; i++)
		res.push_back(data[i] - v[i]);
	return res;
}

int MyIntVector::operator*(const MyIntVector& v) const
{
	if (used != v.used) {
		cout << "Size is not same" << endl;
		exit(-4);
	}

	int res = 0;
	for (size_t i = 0; i < used; i++)
		res += data[i] * v[i];
	return res;
}

bool MyIntVector::operator==(const MyIntVector& v) const
{
	if (used != v.used)
		return false;

	for (size_t i = 0; i < used; i++) {
		if (data[i] != v[i])
			return false;
	}
	return true;
}

MyIntVector MyIntVector::operator-() const
{
	MyIntVector res = *this;
	for (size_t i = 0; i < used; i++) {
		res.data[i] *= -1;
	}
	return res;
}

void MyIntVector::operator()(int num)
{
	for (size_t i = 0; i < used; i++)
		data[i] = num;
}