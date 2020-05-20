#pragma once
#include "Pair.h"
class Ellipse :
	public Pair
{
public:
	Ellipse() : Pair(5, 10){}
	Ellipse(int a, int b) : Pair(a,b){}

	double get_square();
	void print() { cout << "έλλθορ: a = " << first << " b = " << second << endl; }
};

