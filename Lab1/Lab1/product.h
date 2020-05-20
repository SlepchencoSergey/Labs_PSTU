#pragma once
#include <iostream>
#include <string>
using namespace std;

class product
{
private:
	string name;
	string shifr;
	int count;
public:
	product(string name);
	product(string name, string shifr, int count);
	~product();
	void print();
};

