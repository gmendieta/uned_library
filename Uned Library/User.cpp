
#include "User.hpp"

#include <sstream>
#include <string>


using namespace std;

User::User(const string& dni, const string& first_name, const string& last_name)
	:dni(dni), first_name(first_name), last_name(last_name)
{

}

User::~User()
{
}

void User::set_dni(const string& dni)
{
	this->dni = dni;
}

string User::get_dni() const
{
	return dni;
}

void User::set_first_name(const string& first_name)
{
	this->first_name = first_name;
}

string User::get_first_name() const
{
	return first_name;
}

void User::set_last_name(const string& last_name)
{
	this->last_name = last_name;
}

string User::get_last_name() const
{
	return last_name;
}

string User::str() const
{
	ostringstream ss;
	ss << first_name << " " << last_name << " (" << dni << ")";
	return ss.str();
}
