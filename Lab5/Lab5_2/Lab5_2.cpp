#include <iostream>
#include <ctime>
#include "custom_array.h"
using namespace std;

template<class T>
void fill_array(T* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
	}
}

template<class T>
void print_array(T* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void fill_char_array(char* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = (char)(rand() % 26 + 'a');
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));

	int n;
	cout << "введите размеры массива: ";
	cin >> n;

	int* a = new int[n];
	fill_array(a, n);
	print_array(a, n);
	custom_array<int> a1(a,n);
	int min1 = a1.find_min();
	cout << "Минимальный элемент = " << min1 << endl;

	double* b = new double[n];
	fill_array(b, n);
	print_array(b, n);
	custom_array<double> b1(b, n);
	double min2 = b1.find_min();
	cout << "Минимальный элемент = " << min2 << endl;

	char* c = new char[n];
	fill_char_array(c, n);
	print_array(c, n);
	custom_array<char> c1(c, n);
	char min3 = c1.find_min();
	cout << "Минимальный элемент = " << min3 << endl;
}