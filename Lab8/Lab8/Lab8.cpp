#include <iostream>
#include "book.h"
#include <list>
#include <fstream>
#include <Windows.h>
#include <iomanip>
using namespace std;

book* create()
{
	cin.ignore();

	string name;
	cout << "Введите название: ";
	getline(cin, name);

	string author;
	cout << "Введите автора: ";
	getline(cin, author);

	string publish;
	cout << "Введите издательство: ";
	getline(cin, publish);

	int year;
	cout << "Введите год: ";
	cin >> year;

	book* b = new book(name, author, year, publish);
	return b;
}

void show(const list<book*>& books)
{
	cout << setw(5) << "№" << setw(20) << "Название" << setw(30) << "Автор" << setw(10) << "Год" << setw(25) << "Издательство" << endl;
	
	auto start = books.begin();
	int i = 1;

	while (start != books.end())
	{
		book* b = *start;
		if (!b->get_deleted())
		{
			cout << setw(5) << i << setw(20) << b->get_name() << setw(30) << b->get_author() << setw(10)
				<< b->get_year() << setw(25) << b->get_publish() << endl;
			i++;
		}
		start++;
	}
}

//поиск по ключу
list<book*>::const_iterator find_book(const list<book*>& books, string name, string author)
{
	auto start = books.begin();

	while (start != books.end())
	{
		book* b = *start;
		if (b->get_name().compare(name) == 0 && b->get_author().compare(author) == 0)
			return start;

		start++;
	}
	return books.end();
}

//поиск по номеру
list<book*>::const_iterator find_book(const list<book*>& books, int number)
{
	auto start = books.begin();
	int i = 1;

	while (start != books.end())
	{
		book* b = *start;
		if (i == number)
			return start;

		start++;
		if (!b->get_deleted())
			i++;
	}
	return books.end();
}

void edit(book* b)
{
	cout << "Что редактировать? 1.Название 2.Автор 3.Год 4.Издательство" << endl;
	int oper;
	cin >> oper;

	cin.ignore();

	switch (oper)
	{
		case 1:
		{
			cout << "Введите новое название: ";
			string name;
			getline(cin, name);
			b->set_name(name);
			break;
		}
		case 2:
		{
			cout << "Введите нового автора: ";
			string author;
			getline(cin, author);
			b->set_author(author);
			break;
		}
		case 3:
		{
			cout << "Введите новый год: ";
			int year;
			cin >> year;
			b->set_year(year);
			break;
		}
		case 4:
		{
			cout << "Введите новое издательство: ";
			string publish;
			getline(cin, publish);
			b->set_publish(publish);
			break;
		}
	}
}

bool edit(list<book*>& books)
{
	cout << "1.По ключу" << endl;
	cout << "2.По номеру" << endl;

	int choose;
	cin >> choose;

	list<book*>::const_iterator find_b = books.end();

	switch (choose)
	{
	case 1:
	{
		cin.ignore();

		string name, author;
		cout << "Введите название: ";
		getline(cin, name);

		cout << "Введите автора: ";
		getline(cin, author);

		find_b = find_book(books, name, author);
		break;
	}
	case 2:
	{
		int number;
		cout << "Введите номер: ";
		cin >> number;

		find_b = find_book(books, number);
		break;
	}
	}

	if (find_b != books.end())
	{
		edit(*find_b);
		return true;
	}
	else
		return false;
}

bool remove_from_list(list<book*>& books)
{
	int count_del_books = 0;

	auto start = books.begin();
	while (start != books.end())
	{
		book* b = *start;

		if (b->get_deleted())
			count_del_books++;
		start++;
	}

	if (count_del_books > books.size() / 2)
	{
		start = books.begin();

		while (start != books.end())
		{
			book* b = *start;

			if (b->get_deleted())
			{
				books.erase(start++);
			}
			else
				start++;
		}
		return true;
	}
	return false;
}

bool remove(list<book*>& books, book** remove_book)
{
	cout << "1.По ключу" << endl;
	cout << "2.По номеру" << endl;

	int choose;
	cin >> choose;

	list<book*>::const_iterator find_b = books.end();

	switch (choose)
	{
		case 1:
		{
			cin.ignore();

			string name, author;
			cout << "Введите название: ";
			getline(cin, name);

			cout << "Введите автора: ";
			getline(cin, author);

			find_b = find_book(books, name, author);
			break;
		}
		case 2:
		{
			int number;
			cout << "Введите номер: ";
			cin >> number;

			find_b = find_book(books, number);
			break;
		}
	}

	if (find_b != books.end())
	{
		*remove_book = *find_b;
		(*find_b)->set_deleted(true);
		if (remove_from_list(books))
			*remove_book = nullptr;
		return true;
	}
	else
		return false;
}



void show_by_author(const list<book*>& books, string author)
{
	cout << setw(5) << "№" << setw(20) << "Название" << setw(30) << "Автор" << setw(10) << "Год" << setw(25) << "Издательство" << endl;

	auto start = books.begin();
	int i = 1;

	while (start != books.end())
	{
		book* b = *start;
		if (!b->get_deleted() && b->get_author().compare(author) == 0)
		{
			cout << setw(5) << i << setw(20) << b->get_name() << setw(30) << b->get_author() << setw(10)
				<< b->get_year() << setw(25) << b->get_publish() << endl;
			i++;
		}
		start++;
	}
}

void show_by_period(const list<book*>& books, int start_year, int end_year)
{
	cout << setw(5) << "№" << setw(20) << "Название" << setw(30) << "Автор" << setw(10) << "Год" << setw(25) << "Издательство" << endl;

	auto start = books.begin();
	int i = 1;

	while (start != books.end())
	{
		book* b = *start;
		if (!b->get_deleted() && b->get_year() >= start_year && b->get_year() <= end_year)
		{
			cout << setw(5) << i << setw(20) << b->get_name() << setw(30) << b->get_author() << setw(10)
				<< b->get_year() << setw(25) << b->get_publish() << endl;
			i++;
		}
		start++;
	}
}

void add_book(list<book*>& books)
{
	cout << "Куда добавить? 1.Начало 2.Конец 3.Заданная позиция" << endl;
	int choose;
	cin >> choose;
	int pos;
	if (choose == 1)
		pos = 0;
	else if (choose == 2)
		pos = books.size();
	else
	{
		cout << "Введите позицию: ";
		cin >> pos;
	}

	book* b = create();

	auto it = books.begin();
	for (int i = 0; i < pos; i++)
		it++;

	books.insert(it, b);
}

void save_in_file(const list<book*>& books)
{
	ofstream file("books.bin", ios::binary);

	auto start = books.begin();

	while (start != books.end())
	{
		book* b = *start;
		file.write((char*)b, sizeof(*b));
		start++;
	}

	file.close();
}

void load_file(list<book*>& books)
{
	ifstream file("books.bin", ios::binary);

	if (file.is_open())
	{
		book* b = new book();

		while (file.read((char*)b, sizeof(book)))
		{
			books.push_back(b);
			b = new book();
		}
		file.close();
	}
}

bool reestablish_book(list<book*>& books, book* remove_book)
{
	if (remove_book == nullptr)
		return false;

	auto start = books.begin();

	while (start != books.end())
	{
		book* b = *start;
		if (b == remove_book)
		{
			b->set_deleted(false);
			return true;
		}
		start++;
	}
	return false;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	list<book*> books;
	load_file(books);
	book* last_remove_book = nullptr;

	int oper;

	do
	{
		cout << "1.Добавление" << endl;
		cout << "2.Удаление" << endl;
		cout << "3.Редактирование" << endl;
		cout << "4.Просмотр" << endl;
		cout << "5.Поиск по автору" << endl;
		cout << "6.Поиск по периоду" << endl;
		cout << "7.Сохранить изменения" << endl;
		cout << "8.Отмена удаления" << endl;
		cout << "0.Выход" << endl;

		cin >> oper;

		switch (oper)
		{
		case 1:
		{
			add_book(books);
			break;
		}
		case 2:
		{
			bool res = remove(books, &last_remove_book);
			if (res)
				cout << "Удаление успешно завершено" << endl;
			else
				cout << "Книга не найдена" << endl;
			break;
		}
		case 3:
		{
			bool res = edit(books);
			if (res)
				cout << "Редактирование успешно завершено" << endl;
			else
				cout << "Книга не найдена" << endl;
			break;
		}
		case 4:
		{
			show(books);
			break;
		}
		case 5:
		{
			cout << "Введите автора: ";
			string author;
			cin.ignore();
			getline(cin, author);
			show_by_author(books, author);
			break;
		}
		case 6:
		{
			int start_year, end_year;
			cout << "Начало периода: ";
			cin >> start_year;
			cout << "Конец периода: ";
			cin >> end_year;

			show_by_period(books, start_year, end_year);
			break;
		}
		case 7:
		{
			save_in_file(books);
			break;
		}
		case 8:
		{
			bool res = reestablish_book(books, last_remove_book);
			if (res)
				cout << "Последнее удаление отменено" << endl;
			else
				cout << "Отмена невозможна" << endl;
		}
		default:
			break;
		}
	} 
	while (oper != 0);
}
