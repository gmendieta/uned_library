#pragma once

#include <string>

using namespace std;

class User
{
	string dni;
	string first_name;
	string last_name;

public:
	explicit User(const string& dni, const string& first_name, const string& last_name);
	~User();

	void set_first_name(const string& firstname);
	string get_first_name() const;
	void set_last_name(const string& lastname);
	string get_last_name() const;
	void set_dni(const string& dni);
	string get_dni() const;

	string str() const;
};

