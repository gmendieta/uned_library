#include "MenuOption.hpp"


MenuOption::MenuOption(const string message):
	message(message)
{
}

MenuOption::~MenuOption()
{
}

string MenuOption::get_message() const
{
	return message;
}


