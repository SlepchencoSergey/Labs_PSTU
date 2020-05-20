#include <iostream>
#include "Vector.h"

int main()
{
	setlocale(LC_ALL, "rus");

	cout << "Размер вектора = ";
	int size;
	cin >> size;

	try
	{
		Vector v(size);

		do
		{
			cout << "1.Добавить элемент" << endl;
			cout << "2.Удалить элемент из начала вектора" << endl;
			cout << "3.Получить элемент по индексу" << endl;
			cout << "4.Вывести элементы" << endl;
			cout << "5.Умножение вектора на число" << endl;
			cout << "6.Получение элемента с конца вектора" << endl;
			cout << "0.Выход" << endl;

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
					cout << "Введите значение элемента: ";
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
					cout << "Введите индекс элемента: ";
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
					cout << "Введите число: ";
					int k;
					cin >> k;

					v = v * k;
					break;
				}
				case 6:
				{
					cout << "Введите номер: ";
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
			catch (const error & exc)
			{
				cout << exc.get_message() << endl;
			}
		} while (true);
	}
	catch (const error & exc)
	{
		cout << exc.get_message() << endl;
	}


}
