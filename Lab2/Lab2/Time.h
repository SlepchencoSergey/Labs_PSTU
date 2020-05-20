#pragma once
#include <iostream>
using namespace std;

class Time
{
private:
	int min, sec;
public:
	Time(); //����������� ��� ����������
	Time(int min, int sec); //����������� � �����������
	Time(const Time& time); //����������� �����������
	~Time(){} //����������

	//���������� ����������
	//�������� ������������
	Time& operator=(const Time& t);
	//�������� ��������
	Time operator+(int sec);
	//��������� ���������
	bool operator==(const Time& t);
	bool operator!=(const Time& t);

	int get_min() { return min; } //��������
	void set_min(int min) { this->min = min; } //�����������

	int get_sec() { return sec; } //��������
	void set_sec(int sec) { this->sec = sec; } //�����������

	//���������� ��������� ����� (cin >> t)
	friend istream& operator>>(istream& in, Time& p);
	//���������� ��������� ������ (cout << t)
	friend ostream& operator<<(ostream& out, const Time& p);
};

