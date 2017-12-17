
#include <iostream>
#include <stdlib.h>
#include <limits>

#include "MenuPage.hpp"

using namespace std;

MenuPage::MenuPage(const string& name, const string& header):
	name(name), header(header)
{
}

MenuPage::~MenuPage()
{
}

char MenuPage::read_char()
{
	char option;
	cin >> option;
	while (!cin) {
		cin.clear();
		cin.ignore();
		cin >> option;
	}
	return option;
}

MenuPage& MenuPage::add_option(const string& message, char option)
{
	if (option_map.find(option) != option_map.end()) {
		cout << "Error adding \"" << message << "\" option. Index" << option << " already exists" << endl;
	}
	else if (option == EXIT_CHAR) {
		cout << "Error adding \"" << message << "\" option. Index" << option << " is reserved" << endl;
	}
	else {
		auto menu_option = make_shared<MenuOption>(message);
		option_map.emplace(option, menu_option);
	}
	return (*this);
}

MenuPage& MenuPage::add_exit_option(const string& message)
{
	auto menu_option = make_shared<MenuOption>(message);
	option_map.emplace(EXIT_CHAR, menu_option);
	return (*this);
}

char MenuPage::show()
{
	char option = EXIT_CHAR;
	do
	{
		system("cls");
		cout << header << endl << endl;
		auto it = option_map.begin();
		++it; // Because of Exit option
		for ( ; it != option_map.end(); ++it) {
			// Get min and max option
			cout << it->first << ": " << it->second->get_message() << endl;
		}
		if (option_map.find(EXIT_CHAR) != option_map.end()) {
			it = option_map.begin();
			cout << it->first << ": " << it->second->get_message() << endl;
		}
		cout << endl;
		cout << "Please select an option: ";
		option = read_char();
	} while (option_map.find(option) == option_map.end());
	return option;
}
