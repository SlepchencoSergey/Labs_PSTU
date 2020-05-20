#include <iostream>
#include "Vector.h"

int main()
{
    setlocale(LC_ALL, "rus");

    cout << "������ ������� = ";
    int size;
    cin >> size;

	try
	{
		Vector v(size);

		do
		{
			cout << "1.�������� �������" << endl;
			cout << "2.������� ������� �� ������ �������" << endl;
			cout << "3.�������� ������� �� �������" << endl;
			cout << "4.������� ��������" << endl;
			cout << "5.��������� ������� �� �����" << endl;
			cout << "6.��������� �������� � ����� �������" << endl;
			cout << "0.�����" << endl;

			int oper;
			cin >> oper;

			if (oper == 0)
				break;

			try
			{
				switch (oper)
				{
				case 1:
				{
					cout << "������� �������� ��������: ";
					int element;
					cin >> element;

					v = v + element;
					break;
				}
				case 2:
				{
					--v;
					break;
				}
				case 3:
				{
					cout << "������� ������ ��������: ";
					int index;
					cin >> index;

					cout << v[index] << endl; 
					break;
				}
				case 4:
				{
					Vector::iterator start = v.begin();
					Vector::iterator end = v.end();

					while (start != end)
					{
						cout << *start << " ";
						start++;
					}
					cout << endl; 
					break;
				}
				case 5:
				{
					cout << "������� �����: ";
					int k;
					cin >> k;

					v = v * k;
					break;
				}
				case 6:
				{
					cout << "������� �����: ";
					int n;
					cin >> n;

					Vector::iterator end = v.end();
					end = end - n;

					cout << *end << endl;
					break;
				}
				default:
					break;
				}
			}
			catch (const exception & exc)
			{
				cout << exc.what() << endl;
			}
		} 
		while (true);
	}
	catch (const exception& exc)
	{
		cout << exc.what() << endl;
	}
    

}
