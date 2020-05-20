#include "Vector.h"

Vector::Vector(int max_size)
{
	if (max_size > MAX_SIZE)
		throw exception("размер больше максимального");

	size = 0;
	this->max_size = max_size;
	a = new int[max_size];
}

Vector::Vector(const Vector& v)
{
	size = v.size;
	max_size = v.max_size;
	a = new int[max_size];
	for (int i = 0; i < size; i++)
	{
		a[i] = v.a[i];
	}
}

Vector::~Vector()
{
	delete[] a;
}

Vector& Vector::operator=(const Vector& v)
{
	if(this != &v)
	{
		delete[] a;

		a = new int[v.max_size];
		for (int i = 0; i < v.size; i++)
			a[i] = v.a[i];

		size = v.size;
		max_size = v.max_size;
	}

	return *this;
}

int& Vector::operator[](int index)
{
	if (index < 0 || index >= size)
		throw exception("выход за границы вектора");

	return a[index];
}

int Vector::operator()()
{
	return size;
}

Vector Vector::operator*(int k)
{
	Vector res(*this);

	for (int i = 0; i < res.size; i++)
	{
		res.a[i] = res.a[i] * k;
	}

	return res;
}

Vector& Vector::operator+(int k)
{
	if (size == max_size)
		throw exception("вектор полный");

	a[size] = k;
	size++;

	return *this;
}

Vector& Vector::operator--()
{
	if (size == 0)
		throw exception("вектор пустой");

	for (int i = 0; i < size-1; i++)
	{
		a[i] = a[i + 1];
	}

	size--;

	return *this;
}
