#pragma once
#include<iostream>
#include <string>
using namespace std;

class book
{
private:
	string name;
	string author;
	int year;
	string publish;
	bool deleted;
public:
	book(){}
	book(string name, string author, int year, string publish);

	void set_name(string name) { this->name = name; }
	string get_name() { return this->name; }

	void set_author(string author) { this->author = author; }
	string get_author() { return this->author; }

	void set_year(int year) { this->year = year; }
	int get_year() { return this->year; }

	void set_publish(string publish) { this->publish = publish; }
	string get_publish() { return this->publish; }

	void set_deleted(bool deleted) { this->deleted = deleted; }
	bool get_deleted() { return this->deleted; }
};

