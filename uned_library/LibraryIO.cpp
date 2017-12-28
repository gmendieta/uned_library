
#include "LibraryIO.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

const char CSV_SEP = ';';

bool LibraryIO::read_user_csv(const string& filepath, list<shared_ptr<User>>& user_l)
{
	ifstream fp;
	fp.open(filepath, ios_base::in);
	if (!fp.is_open()) {
		cout << "Error opening file \"" << filepath << "\"" << endl;
		return false;
	}
	vector<string> fields;
	string line;  // Store a whole line
	string field; // Store a single csv field
	unsigned int line_number = 1;
	while (getline(fp, line)) {
		fields.clear(); // Clean old fields
		stringstream line_stream(line);
		while(getline(line_stream, field, CSV_SEP)) {
			fields.push_back(field);
		}
		// Check read fields and generate User instance
		if (fields.size() != 3) {
			cout << "Error parsing User file \"" << filepath << "\". Line " << line_number << endl;
			user_l.clear();  // Warning
			return false;
		}
		user_l.push_back(make_shared<User>(fields[0], fields[1], fields[2]));
		++line_number;
	}
	return true;
}

bool LibraryIO::write_user_csv(const string& filepath, const list<shared_ptr<User>>& user_l)
{
	ofstream fp;
	fp.open(filepath, ios_base::out);
	if (!fp.is_open()) {
		return false;
	}
	for (auto&& user : user_l) {
		fp << user->get_dni() << CSV_SEP << user->get_first_name() << CSV_SEP << user->get_last_name() << endl;
	}
	fp.close();
	return true;
}

bool LibraryIO::read_book_csv(const string& filepath, list<shared_ptr<Book>>& book_l)
{
	ifstream fp;
	fp.open(filepath, ios_base::in);
	if (!fp.is_open()) {
		cout << "Error opening file \"" << filepath << "\"" << endl;
		return false;
	}
	vector<string> fields;
	string line;
	string field;
	unsigned int line_number = 1;
	while (getline(fp, line)) {
		fields.clear();
		stringstream line_stream(line);
		while (getline(line_stream, field, CSV_SEP)) {
			fields.push_back(field);
		}
		// Check read fields and generate Book instance
		if (fields.size() != 3) {
			cout << "Error parsing Book file \"" << filepath << "\". Line " << line_number << endl;
			book_l.clear(); // Warning
			return false;
		}
		book_l.push_back(make_shared<Book>(fields[0], fields[1], fields[2]));
		++line_number;
	}
	return true;
}

bool LibraryIO::write_book_csv(const string& filepath, const list<shared_ptr<Book>>& book_l)
{
	ofstream fp;
	fp.open(filepath, ios_base::out);
	if (!fp.is_open()) {
		return false;
	}
	for (auto&& book : book_l) {
		fp << book->get_isbn() << CSV_SEP << book->get_title() << CSV_SEP << book->get_writer() << endl;
	}
	fp.close();
	return true;
}
