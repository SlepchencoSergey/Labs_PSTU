#include <iostream>
#include "Vector.h"
#include "Time.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

    Vector<int> v;
	cout << "������� �������� �������" << endl;
	cin >> v;
	cout << v << endl;

	int k;
	cout << "k = ";
	cin >> k;
	Vector<int> b = v * k;

	for (int i = 0; i < v.get_size(); i++)
	{
		cout << b[i] << " ";
	}
	
	cout << endl;
	cout << "������ ������� = " << v() << endl;

	Vector<Time> times(4);
	cout << "������� �������� ������� (�����) � ������� ������ �������" << endl;
	cin >> times;
	cout << times << endl;

	cout << "k = ";
	cin >> k;
	Vector<Time> b_times = times * k;
	cout << b_times;
}
