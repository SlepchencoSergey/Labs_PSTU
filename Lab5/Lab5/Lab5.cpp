#include <iostream>
#include <ctime>
using namespace std;

template<class T>
T find_min(T* a, int n)
{
    T min = a[0];

	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
	}

	return min;
}

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
	cout << "������� ������� �������: ";
	cin >> n;

	int* a = new int[n];
	fill_array(a, n);
	cout << "������������� ������" << endl;
	print_array(a, n);
	int min1 = find_min(a, n);
	cout << "����������� ������� = " << min1 << endl;

	double* b = new double[n];
	fill_array(b, n);
	cout << "������������ ������" << endl;
	print_array(b, n);
	double min2 = find_min(b, n);
	cout << "����������� ������� = " << min2 << endl;

	char* c = new char[n];
	fill_char_array(c, n);
	cout << "���������� ������" << endl;
	print_array(c, n);
	char min3 = find_min(c, n);
	cout << "����������� ������� = " << min3 << endl;
}