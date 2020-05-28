#pragma once
#include <iostream>
#include <exception>
using namespace std;

class Vector
{
private:
	int* a; //массив
	int size; //размер (сколько эл-тов добавлено)
	int max_size; //максим размер (сколько можно добавить элементов)
	const int MAX_SIZE = 30;
public:
	Vector(int max_size); 
	Vector(const Vector& v);
	~Vector();

	int get_size() { return size; }
	Vector& operator=(const Vector& v);
	int& operator[](int index);
	int operator()();
	Vector operator*(int k);
	Vector& operator+(int k);
	Vector& operator--();

	class iterator
	{
		int* current;
	public:
		iterator(int* p) : current(p){}
		int& operator*() { return *current; }
		int& operator*() const { return *current; }
		bool operator==(const iterator& it) const { return current == it.current; }
		bool operator!=(const iterator& it) const { return current != it.current; }
		iterator& operator++() { ++current; return *this; }
		iterator operator++(int) { int* tmp = current; ++current; return iterator(tmp); }
		iterator& operator-(int n)
		{
			current = current - n;
			return *this;
		}

		friend class Vector;
	};

	iterator begin() const { return iterator(a); }
	iterator end() const { return iterator(a+size); }
};

