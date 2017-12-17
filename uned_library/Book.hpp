#pragma once

#include <string>

using namespace std;

class Book
{
	string isbn;
	string title;
	string writer;

public:
	explicit Book(const string& isbn, const string& title, const string& writter);
	~Book();
	string get_isbn() const;
	void set_isbn(const string& isbn);
	string get_title() const;
	void set_title(const string& title);
	string get_writter() const;
	void set_writter(const string& writter);

	string str() const;
};

