#pragma once

#include <string>

using namespace std;

class MenuOption
{
	string message;
public:
	explicit MenuOption(const string message);
	~MenuOption();

	string get_message() const;
};

