#include <iostream>
#include <vector>
#include <ctime>
#include <Windows.h>
#include "hashtable.h"

void show_person(person* p)
{
    cout << "ФИО: " << p->get_fio() << endl;
    cout << "Номер пасспорта: " << p->get_number_passport() << endl;
    cout << "Адрес: " << p->get_address() << endl;
}

int main()
{
    srand(time(0));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<string> surnames = { "Иванов","Петров","Сидоров","Тесла","Маск","Эйнштейн","Ньютон","Гук","Кюри","Сталин","Ленин","Маркс" };
    vector<string> names = { "Иван","Петр","Сидор","Никола","Илон","Альберт","Исаак","Роберт","Мария","Иосиф","Владимир","Карл","Алексей","Михаил","Дмитрий" };
    vector<string> patronymics = { "Иванович","Петрович","Сидорович","Николаевич","Илонович","Альбертович","Исаакович","Робертович","Маркович","Иосифович","Владимирович","Карлович","Алексеевич","Михаилович","Дмитриевич" };
    vector<string> addresses = { "Мира 10", "Ленина 50", "Ленина 20", "Декабристов 45", "Попова 3" };

    hashtable* table = nullptr;

    int oper;

    do
    {
        cout << "1.Создание хэш-таблицы" << endl;
        cout << "2.Заполнение хэш-таблицы" << endl;
        cout << "3.Поиск по ключу" << endl;
        cout << "4.Определение кол-ва коллизий" << endl;
        cout << "5.Просмотр хэш-таблицы" << endl;
        cout << "6.Удаление по ключу" << endl;
        cout << "7.Редактирование по ключу" << endl;
        cout << "0.Выход" << endl;

        cin >> oper;

        switch (oper)
        {
        case 1:
        {
            int size;
            cout << "Размер = ";
            cin >> size;
            table = new hashtable(size);
            break;
        }
        case 2:
        {
            int count;
            cout << "Кол-во эл-тов = ";
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
            cout << "Введите ключ для поиска: ";
            cin >> passport;

            person* p = table->find(passport);
            if (p == nullptr)
                cout << "Элемент не найден" << endl;
            else
            {
                show_person(p);
            } 
            break;
        }
        case 4:
        {
            int count = table->count_collision();
            cout << "Кол-во коллизий = " << count << endl;
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
            cout << "Введите номер пасспорта: ";
            cin >> passport;

            bool res = table->remove(passport);
            if (res)
                cout << "Удаление успешно завершено" << endl;
            else
                cout << "Элемент не найден" << endl;
            break;
        }
        case 7:
        {
            int passport;
            cout << "Введите номер пасспорта: ";
            cin >> passport;

            person* p = table->find(passport);
            if (p == nullptr)
                cout << "Элемент не найден" << endl;
            else
            {
                cout << "Что поменять? 1.ФИО 2.Адрес" << endl;
                int choose;
                cin >> choose;
                cin.ignore();

                switch (choose)
                {
                    case 1:
                    {
                        string fio;
                        cout << "Введите новое ФИО: ";
                        getline(cin, fio);
                        
                        p->set_fio(fio);
                        break;
                    }
                    case 2:
                    {
                        string address;
                        cout << "Введите новый адрес: ";
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

