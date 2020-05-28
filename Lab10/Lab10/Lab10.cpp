#include <iostream>
#include "point.h"
#include <ctime>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
	srand(time(0));

	int choose;
	point* root = nullptr;
	bool is_tree_find = false;

	do
	{
		cout << "0.�����" << endl;
		cout << "1.������������ �������� ���������������� �������� ������" << endl;
		cout << "2.����������� ������" << endl;
		cout << "3.����� ����������� ������� � ������" << endl;
		cout << "4.������������� �������� ���������������� ������ � ������ ������" << endl;

		cin >> choose;

		switch (choose)
		{
		case 1:
		{
			int count;
			cout << "���-�� ��-��� = ";
			cin >> count;

			if (root != nullptr)
				destroy(root);

			is_tree_find = false;
			root = build_ideal_tree(count);
			break;
		}
		case 2:
		{
			if (root != nullptr)
				print_tree(root, 0);
			else
				cout << "������� ����������� ������!" << endl;
			break;
		}
		case 3:
		{
			if (root != nullptr)
			{
				double min;
				if (is_tree_find == false)
				{
					min = root->data;
					find_min(root, min);
				}
				else
				{
					min = find_min_find_tree(root);
				}

				cout << "����������� ������� = " << min << endl;
			}
			else
				cout << "������� ����������� ������!" << endl;
			break;
		}
		case 4:
		{
			if (root != nullptr)
			{
				point* new_root = nullptr;
				build_find_tree(root, &new_root);
				destroy(root);
				root = new_root;
				is_tree_find = true;
			}
			else
				cout << "������� ����������� ������!" << endl;
			break;
		}
		case 0:
		{
			destroy(root);
			break;
		}
		default:
			cout << "�������� ����� ����" << endl;
			break;
		}
	} 
	while (choose != 0);
}
