#pragma once

#include <map>
#include <string>
#include <memory>

#include "MenuOption.hpp"

using namespace std;
const char EXIT_CHAR = '0';

class MenuPage
{
	string header, name;
	map<char, shared_ptr<MenuOption>> option_map;

public:
	explicit MenuPage(const string& name, const string& header="");
	~MenuPage();
	
	static char read_char();
	MenuPage& add_option(const string& message, char option);
	MenuPage& add_exit_option(const string& message = "Exit");
	char show();
};


