#include "hashtable.h"

int hashtable::hash_code(int key)
{
	double a = 0.7;
	double ka = key * a;
	double drob_part = ka - (int)ka;

	return (int)(drob_part * max_size);
}

hashtable::hashtable(int size)
{
	max_size = size;
	table = new node * [max_size];
	for (int i = 0; i < max_size; i++)
	{
		table[i] = nullptr;
	}
}

hashtable::~hashtable()
{
	delete[] table;
}

void hashtable::add(int key, person* p)
{
	int code = hash_code(key);

	node* point = new node();
	point->p = p;
	point->key = key;
	point->next = nullptr;

	if (table[code] == nullptr)
	{
		table[code] = point;
	}
	else
	{
		point->next = table[code];
		table[code] = point;
	}
}

person* hashtable::find(int key)
{
	int code = hash_code(key);

	node* current = table[code];
	while (current != nullptr)
	{
		if (current->key == key)
			return current->p;
		current = current->next;
	}

	return nullptr;
}

bool hashtable::remove(int key)
{
	int code = hash_code(key);

	node* current = table[code];
	if (current != nullptr && current->key == key)
	{
		table[code] = table[code]->next;
		delete current;
		return true;
	}
	else
	{
		while (current->next != nullptr)
		{
			if (current->next->key == key)
			{
				node* temp = current->next;
				current->next = current->next->next;
				delete temp;
				return true;
			}
			current = current->next;
		}
	}

	return false;
}

int hashtable::count_collision()
{
	int count = 0;

	for (int i = 0; i < max_size; i++)
	{
		node* current = table[i];
		if (current != nullptr)
		{
			while (current != nullptr)
			{
				count++;
				current = current->next;
			}
			count--;
		}
	}

	return count;
}

void hashtable::show()
{
	for (int i = 0; i < max_size; i++)
	{
		node* current = table[i];
		if (current != nullptr)
		{
			while (current != nullptr)
			{
				cout << "ФИО: " << current->p->get_fio() << endl;
				cout << "Номер пасспорта: " << current->p->get_number_passport() << endl;
				cout << "Адрес: " << current->p->get_address() << endl << endl;
				current = current->next;
			}
		}
	}
}
