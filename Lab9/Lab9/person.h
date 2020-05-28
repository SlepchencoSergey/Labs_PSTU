#pragma once
#include <iostream>
#include <string>
using namespace std;

class person
{
private:
	string fio;
	int number_passport;
	string address;
public:
	person(string fio, int passport, string address) : fio(fio), number_passport(passport), address(address){}
	
	string get_fio() { return fio; }
	void set_fio(string fio) { this->fio = fio; }

	int get_number_passport() { return number_passport; }
	void set_number_passport(int number_passport) { this->number_passport = number_passport; }

	string get_address() { return address; }
	void set_address(string address) { this->address = address; }
};

