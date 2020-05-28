#pragma once
#include "person.h"

class hashtable
{
private:
	class node
	{
	public:
		int key;
		person* p;
		node* next;
	};

	int max_size;
	node** table;

	int hash_code(int key);

public:
	hashtable(int size);
	~hashtable();

	void add(int key, person* p);
	person* find(int key);
	bool remove(int key);
	int count_collision();
	void show();
};

