#pragma once
#include <iostream>
using namespace std;

template<class T>
class Vector
{
private:
	T* a; //массив
	int size; //размер (сколько эл-тов добавлено)
	int max_size; //максим размер (сколько можно добавить элементов)
public:
	Vector();
	Vector(int max_size);
	Vector(const Vector<T>& v);
	~Vector();

	int get_size() { return size; }
	void push_back(T data);
	T& operator[](int index);
	int operator()();
	Vector<T> operator*(int k);
	Vector<T>& operator=(const Vector<T>& v);

	//перегрузка оператора ввода (cin >> t)
	friend istream& operator>> <>(istream& in, Vector<T>& v);
	//перегрузка оператора вывода (cout << t)
	friend ostream& operator<< <>(ostream& out, const Vector<T>& v);
};

template<class T>
Vector<T>::Vector()
{
	size = 0;
	max_size = 10;
	a = new T[max_size];
}

template<class T>
Vector<T>::Vector(int max_size)
{
	size = 0;
	this->max_size = max_size;
	a = new T[max_size];
}

template<class T>
Vector<T>::Vector(const Vector<T>& v)
{
	size = v.size;
	max_size = v.max_size;
	a = new T[max_size];
	for (int i = 0; i < size; i++)
	{
		a[i] = v.a[i];
	}
}

template<class T>
Vector<T>::~Vector()
{
	delete[] a;
}

template<class T>
void Vector<T>::push_back(T data)
{
	if (size == max_size)
	{
		//увеличиваем массив в 2 раза
		T* b = new T[size * 2];
		for (int i = 0; i < size; i++)
			b[i] = a[i];
		
		delete[] a;
		max_size = max_size * 2;
		a = b;
	}

	a[size] = data;
	size++;
}

template<class T>
T& Vector<T>::operator[](int index)
{
	return a[index];
}

template<class T>
int Vector<T>::operator()()
{
	return size;
}

template<class T>
Vector<T> Vector<T>::operator*(int k)
{
	Vector<T> res(*this);

	for (int i = 0; i < res.size; i++)
	{
		res.a[i] = res.a[i] * k;
	}

	return res;
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v)
{
	if (this != &v)
	{
		delete[] a;

		a = new T[v.max_size];
		for (int i = 0; i < v.size; i++)
			a[i] = v.a[i];
		
		size = v.size;
		max_size = v.max_size;
	}

	return *this;
}

template<class T>
istream& operator>><>(istream& in, Vector<T>& v)
{
	T r;

	for (int i = 0; i < v.max_size; i++)
	{
		in >> r;
		v.push_back(r);
	}
	return in;
}

template<class T>
ostream& operator<<<>(ostream& out, const Vector<T>& v)
{
	for (int i = 0; i < v.size; i++)
	{
		out << v.a[i] << " ";
	}

	return out;
}