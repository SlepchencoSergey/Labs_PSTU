#pragma once
#include <iostream>
using namespace std;

class Time
{
private:
	int min, sec;
public:
	Time(); //конструктор без параметров
	Time(int min, int sec); //конструктор с параметрами
	Time(const Time& time); //конструктор копирования
	~Time(){} //деструктор

	//перегрузки операторов
	//оператор присваивания
	Time& operator=(const Time& t);
	//оператор сложения
	Time operator+(int sec);
	//операторы равенства
	bool operator==(const Time& t);
	bool operator!=(const Time& t);

	int get_min() { return min; } //селектор
	void set_min(int min) { this->min = min; } //модификатор

	int get_sec() { return sec; } //селектор
	void set_sec(int sec) { this->sec = sec; } //модификатор

	//перегрузка оператора ввода (cin >> t)
	friend istream& operator>>(istream& in, Time& p);
	//перегрузка оператора вывода (cout << t)
	friend ostream& operator<<(ostream& out, const Time& p);
};

