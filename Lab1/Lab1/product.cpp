#include "product.h"

product::product(string name)
{
	this->name = name;
	this->shifr = "";
	this->count = 0;

	cout << "����� ������������ " << this << endl;
}

product::product(string name, string shifr, int count)
{
	this->name = name;
	this->shifr = shifr;
	this->count = count;

	cout << "����� ������������ " << this << endl;
}

product::~product()
{
	cout << "����� ����������� " << this << endl;
}

void product::print()
{
	cout << "��������: " << name << "; ����: " << shifr << "; ���-��: " << count << endl;
}
