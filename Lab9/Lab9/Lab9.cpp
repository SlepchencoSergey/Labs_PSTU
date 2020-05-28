#include <iostream>
#include <vector>
#include <ctime>
#include <Windows.h>
#include "hashtable.h"

void show_person(person* p)
{
    cout << "���: " << p->get_fio() << endl;
    cout << "����� ���������: " << p->get_number_passport() << endl;
    cout << "�����: " << p->get_address() << endl;
}

int main()
{
    srand(time(0));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<string> surnames = { "������","������","�������","�����","����","��������","������","���","����","������","�����","�����" };
    vector<string> names = { "����","����","�����","������","����","�������","�����","������","�����","�����","��������","����","�������","������","�������" };
    vector<string> patronymics = { "��������","��������","���������","����������","��������","�����������","���������","����������","��������","���������","������������","��������","����������","����������","����������" };
    vector<string> addresses = { "���� 10", "������ 50", "������ 20", "����������� 45", "������ 3" };

    hashtable* table = nullptr;

    int oper;

    do
    {
        cout << "1.�������� ���-�������" << endl;
        cout << "2.���������� ���-�������" << endl;
        cout << "3.����� �� �����" << endl;
        cout << "4.����������� ���-�� ��������" << endl;
        cout << "5.�������� ���-�������" << endl;
        cout << "6.�������� �� �����" << endl;
        cout << "7.�������������� �� �����" << endl;
        cout << "0.�����" << endl;

        cin >> oper;

        switch (oper)
        {
        case 1:
        {
            int size;
            cout << "������ = ";
            cin >> size;
            table = new hashtable(size);
            break;
        }
        case 2:
        {
            int count;
            cout << "���-�� ��-��� = ";
            cin >> count;

            for (int i = 0; i < count; i++)
            {
                string fio = surnames[rand() % surnames.size()] + " " + names[rand() % names.size()] + " " + patronymics[rand() % patronymics.size()];
                int passport = rand() + 100000;
                string address = addresses[rand() % addresses.size()];

                person* p = new person(fio, passport, address);
                table->add(passport, p);
            }
            break;
        }
        case 3:
        {
            int passport;
            cout << "������� ���� ��� ������: ";
            cin >> passport;

            person* p = table->find(passport);
            if (p == nullptr)
                cout << "������� �� ������" << endl;
            else
            {
                show_person(p);
            } 
            break;
        }
        case 4:
        {
            int count = table->count_collision();
            cout << "���-�� �������� = " << count << endl;
            break;
        }
        case 5:
        {
            table->show();
            break;
        }
        case 6:
        {
            int passport;
            cout << "������� ����� ���������: ";
            cin >> passport;

            bool res = table->remove(passport);
            if (res)
                cout << "�������� ������� ���������" << endl;
            else
                cout << "������� �� ������" << endl;
            break;
        }
        case 7:
        {
            int passport;
            cout << "������� ����� ���������: ";
            cin >> passport;

            person* p = table->find(passport);
            if (p == nullptr)
                cout << "������� �� ������" << endl;
            else
            {
                cout << "��� ��������? 1.��� 2.�����" << endl;
                int choose;
                cin >> choose;
                cin.ignore();

                switch (choose)
                {
                    case 1:
                    {
                        string fio;
                        cout << "������� ����� ���: ";
                        getline(cin, fio);
                        
                        p->set_fio(fio);
                        break;
                    }
                    case 2:
                    {
                        string address;
                        cout << "������� ����� �����: ";
                        getline(cin, address);
                        p->set_address(address);
                        break;
                    }
                }
            }
        }
        default:
            break;
        }
    } 
    while (oper != 0);
}

