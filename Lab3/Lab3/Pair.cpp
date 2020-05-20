#include "Pair.h"

Pair::Pair()
{
	second = 0;
	first = 0;
}

Pair::Pair(int f, int s)
{
	first = f;
	second = s;
}

Pair::Pair(const Pair& p)
{
	first = p.first;
	second = p.second;
}

Pair& Pair::operator=(const Pair& p)
{
	first = p.first;
	second = p.second;

	return *this;
}

istream& operator>>(istream& in, Pair& p)
{
	in >> p.first >> p.second;
	return in;
}

ostream& operator<<(ostream& out, const Pair& p)
{
	out << p.first << " " << p.second;
	return out;
}
