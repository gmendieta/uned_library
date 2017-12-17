#pragma once

#include <memory>
#include <list>
#include "User.hpp"
#include "Book.hpp"

class LibraryIO
{
public:
	LibraryIO() = delete;
	~LibraryIO() = delete;
	static bool read_user_csv(const string& filepath, list<shared_ptr<User>>& user_l);
	static bool write_user_csv(const string& filepath, const list<shared_ptr<User>>& user_l);
	static bool read_book_csv(const string& filepath, list<shared_ptr<Book>>& book_l);
	static bool write_book_csv(const string& filepath, const list<shared_ptr<Book>>& book_l);
};

