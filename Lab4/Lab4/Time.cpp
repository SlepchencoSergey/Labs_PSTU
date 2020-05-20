#include "Time.h"
#include "Time.h"

Time::Time()
{
	this->min = 0;
	this->sec = 0;
}

Time::Time(int min, int sec)
{
	this->min = min;
	this->sec = sec;
}

Time::Time(const Time& time)
{
	this->min = time.min;
	this->sec = time.sec;
}

Time& Time::operator=(const Time& t)
{
	this->min = t.min;
	this->sec = t.sec;

	return *this;
}

Time Time::operator+(int sec)
{
	Time res;
	res.sec = this->sec + sec;
	res.min = this->min;

	if (res.sec >= 60)
	{
		res.min += res.sec / 60;
		res.sec = res.sec % 60;
	}

	return res;
}

bool Time::operator==(const Time& t)
{
	return sec == t.sec && min == t.min;
}

bool Time::operator!=(const Time& t)
{
	return !(*this == t);
}

Time Time::operator*(int k)
{
	int total_sec = min * 60 + sec;
	total_sec *= k;

	Time res;
	res.min = total_sec / 60;
	res.sec = total_sec % 60;

	return res;
}

istream& operator>>(istream& in, Time& p)
{
	in >> p.min >> p.sec;
	return in;
}

ostream& operator<<(ostream& out, const Time& p)
{
	out << p.min << ":" << p.sec;
	return out;
}
