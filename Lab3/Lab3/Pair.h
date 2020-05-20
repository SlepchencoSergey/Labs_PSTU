#pragma once
#include <iostream>
using namespace std;

class Pair
{
protected:
	int first, second;

public:
	Pair();
	Pair(int f, int s);
	Pair(const Pair& p);
	~Pair(){}

	Pair& operator=(const Pair& p);

	int product() { return first * second; }

	int get_first() { return first; }
	void set_first(int f) { first = f; }

	int get_second() { return second; }
	void set_second(int s) { second = s; }

	//перегрузка оператора ввода (cin >> t)
	friend istream& operator>>(istream& in, Pair& p);
	//перегрузка оператора вывода (cout << t)
	friend ostream& operator<<(ostream& out, const Pair& p);

	virtual void print() { cout << "Пара чисел: " << first << " " << second << endl; }
};

