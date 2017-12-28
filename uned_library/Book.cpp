
#include "Book.hpp"

#include <sstream>
#include <string>

using namespace std;

Book::Book(const string& isbn, const string& title, const string& writer)
	:isbn(isbn), title(title), writer(writer)
{
}

Book::~Book()
{

}

string Book::get_isbn() const
{
	return this->isbn;
}

void Book::set_isbn(const string& isbn)
{
	this->isbn = isbn;
}

string Book::get_title() const
{
	return this->title;
}

void Book::set_title(const string& title)
{
	this->title = title;
}

string Book::get_writer() const
{
	return this->writer;
}

void Book::set_writer(const string& writter)
{
	this->writer = writter;
}

string Book::str() const
{
	ostringstream ss;
	ss << title << " " << writer << " (" << isbn << ")";
	return ss.str();
}
