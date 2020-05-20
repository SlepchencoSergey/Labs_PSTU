#pragma once
template<class T>
class custom_array
{
private:
	T* a;
	int n;
public:
	custom_array(T* mas, int n);
	T find_min();
};

template<class T>
custom_array<T>::custom_array(T* mas, int n)
{
	a = new T[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = mas[i];
	}
	this->n = n;
}

template<class T>
T custom_array<T>::find_min()
{
	T min = a[0];

	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
	}

	return min;
}
