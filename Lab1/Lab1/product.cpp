#include "product.h"

product::product(string name)
{
	this->name = name;
	this->shifr = "";
	this->count = 0;

	cout << "Вызов конструктора " << this << endl;
}

product::product(string name, string shifr, int count)
{
	this->name = name;
	this->shifr = shifr;
	this->count = count;

	cout << "Вызов конструктора " << this << endl;
}

product::~product()
{
	cout << "Вызов деструктора " << this << endl;
}

void product::print()
{
	cout << "Название: " << name << "; Шифр: " << shifr << "; Кол-во: " << count << endl;
}
