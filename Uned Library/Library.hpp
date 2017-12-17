#pragma once

#include <list>
#include <vector>
#include <memory>

#include "User.hpp"
#include "Book.hpp"

using namespace std;

class Library
{
	list<shared_ptr<User>> user_l;
	list<shared_ptr<Book>> book_l;

public:
	Library();
	~Library();
	// Users functions
	bool exists_user(const string& dni) const;
	bool add_user(const string& dni, const string& first_name, const string& last_name);
	bool add_user(shared_ptr<User>& user);
	bool remove_user(shared_ptr<User>& user);
	bool remove_user(const string& dni);
	shared_ptr<User> find_user(const string& dni) const;
	// Books functions
	bool exists_book(const string& isbn) const;
	bool add_book(const string& isbn, const string& title, const string& writter);
	bool add_book(shared_ptr<Book>& book);
	bool remove_book(shared_ptr<Book>& user);
	bool remove_book(const string& isbn);
	shared_ptr<Book> find_book(const string& isbn) const;

	bool load_users(const string& filepath, bool replace=true);
	bool save_users(const string& filepath) const;
	bool load_books(const string& filepath, bool replace=true);
	bool save_books(const string& filepath) const;

	unsigned int get_users_str_l(list<string>& users_str_l);
	unsigned int get_books_str_l(list<string>& books_str_l);
};

