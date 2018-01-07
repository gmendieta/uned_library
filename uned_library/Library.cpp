

#include <iostream>

#include "Library.hpp"
#include "LibraryIO.hpp"


using namespace std;


Library::Library()
{

}

Library::~Library()
{
	user_l.clear();
	book_l.clear();
}

bool Library::exists_user(const string& dni) const
{
	auto u = find_user(dni);
	return (u != nullptr);
}

bool Library::add_user(const string& dni, const string& first_name, const string& last_name)
{
	if (exists_user(dni)) {
		return false;
	}
	auto user = std::make_shared<User>(dni, first_name, last_name);
	add_user(user);
	return true;
}

bool Library::add_user(shared_ptr<User>& user)
{
	if (exists_user(user->get_dni())) {
		return false;
	}
	user_l.push_back(user);
	return true;
}

bool Library::remove_user(shared_ptr<User>& user)
{
	return remove_user(user->get_dni());
}

bool Library::remove_user(const string& dni)
{
	auto user = find_user(dni);
	if (user) {
		user_l.remove(user);
		return true;
	}
	return false;
}

shared_ptr<User> Library::find_user(const string& dni) const
{
	for (auto&& user : user_l) {
		if (user->get_dni() == dni)
			return user;
	}
	return shared_ptr<User>();
}

bool Library::exists_book(const string& isbn) const
{
	auto b = find_book(isbn);
	return (b != nullptr);
}

bool Library::add_book(const string& isbn, const string& title, const string& writter)
{
	if (exists_book(isbn)) {
		return false;
	}
	auto book = std::make_shared<Book>(isbn, title, writter);
	book_l.push_back(book);
	return true;
}

bool Library::add_book(shared_ptr<Book>& book)
{
	if (exists_book(book->get_isbn())) {
		return false;
	}
	book_l.push_back(book);
	return true;
}

bool Library::remove_book(shared_ptr<Book>& book)
{
	return remove_book(book->get_isbn());
}

bool Library::remove_book(const string& isbn)
{
	auto book = find_book(isbn);
	if (book) {
		book_l.remove(book);
		return true;
	}
	return false;
}

shared_ptr<Book> Library::find_book(const string& isbn) const
{
	for (auto&& book : book_l) {
		if (book->get_isbn() == isbn)
			return book;
	}
	return shared_ptr<Book>();
}

bool Library::load_users(const string& filepath, bool replace)
{
	list<shared_ptr<User>> user_l;
	if (LibraryIO::read_user_csv(filepath, user_l))	{
		if (replace) this->user_l.clear(); // If replace is True, remove all previous Users
		for (auto&& user : user_l) {
			add_user(user);
		}
		return true;
	}
	return false;
}

bool Library::save_users(const string& filepath) const
{
	return LibraryIO::write_user_csv(filepath, user_l);
}

bool Library::load_books(const string& filepath, bool replace)
{
	list<shared_ptr<Book>> book_l;
	if (LibraryIO::read_book_csv(filepath, book_l))	{
		if (replace) this->book_l.clear(); // If replace is True, remove all previous Books
		for (auto&& book : book_l) {
			add_book(book);
		}
		this->book_l = book_l;
		return true;
	}
	return false;
}

bool Library::save_books(const string& filepath) const
{
	return LibraryIO::write_book_csv(filepath, book_l);
}

unsigned int Library::get_users_str_l(list<string>& users_str_l)
{
	users_str_l.clear();
	for (auto&& user : user_l) {
		users_str_l.push_back(user->str());
	}
	return users_str_l.size();
}

unsigned int Library::get_books_str_l(list<string>& books_str_l)
{
	books_str_l.clear();
	for (auto&& book: book_l) {
		books_str_l.push_back(book->str());
	}
	return books_str_l.size();
}



