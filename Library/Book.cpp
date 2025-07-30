#include "Book.h"

void Book::setBookDetails(string title1, string author1, string isbn1, bool available1) {
	title = title1;
	author = author1;
	isbn = isbn1;
	available = available1;
}

void Book::displayBookDetails() {
	cout << "Title: " << title << endl;
	cout << "Author: " << author << endl;
	cout << "ISBN: " << isbn << endl;
	cout << "Availability: " << available << endl;
}

void Book::returnBook() {
	available = false;
}

bool Book::borrowBook() {
	if (available == false) {
		//cout << "You cannot borrow the book : " << title << endl; 
		return false;
	}
	else {
		available = false;
		//cout << "You have borrowed the book: " << title << endl;
		return true;
	}
}