// UnedLibrary.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <list>
#include "Library.hpp"
#include "MenuPage.hpp"

using namespace std;
enum main_menu_options
{
	exit_menu = '0',
	show_users = '1',
	show_books = '2',
};

int main()
{
	cout << "Uned Library" << endl;
	auto library = Library();
	library.load_users("library_data/users.uned");
	library.load_books("library_data/books.uned");

	auto main_menu = MenuPage("main", "Uned Library");
	main_menu.add_option("Show Users", main_menu_options::show_users)
			 .add_option("Show Books", main_menu_options::show_books)
			 .add_exit_option();

	
	char option = main_menu_options::exit_menu;
	list<string> string_l;
	do
	{
		option = main_menu.show();
		switch (option)
		{
		case main_menu_options::show_users:
			library.get_users_str_l(string_l);
			for (auto&& user_str : string_l) {
				cout << user_str << endl;
			}
			MenuPage::read_char();
			break;
		case main_menu_options::show_books:
			library.get_books_str_l(string_l);
			for (auto&& book_str : string_l) {
				cout << book_str << endl;
			}
			MenuPage::read_char();
			break;
		default: ;
		}
	} while (option != main_menu_options::exit_menu);

    return 0;
}
