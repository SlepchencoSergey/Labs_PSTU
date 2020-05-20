#pragma once
#include <iostream>
using namespace std;

class error
{
private:
	string message;
public:
	error(string message) : message(message){}

	string get_message() const { return message; }
};

