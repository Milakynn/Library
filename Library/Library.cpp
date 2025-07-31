#include "Book.h"

void showMenu();
void showAllBooks();

Book myArray[30];
int totalBooks = 6;

int main() {
  
	Book book1;
	book1.setBookDetails("After", "Anna Todd", "LIN1108", true);
	Book book2;
	book2.setBookDetails("Harry Poter", "J.K Rowling", "DAM1703", false);
	Book book3;
	book3.setBookDetails("The Summer I Turned Pretty", "Jenny Han", "MAM2301", true);
	Book book4;
	book4.setBookDetails("A Game Of Thrones", "George.R Martin", "PAP0408", true);
	Book book5;
	book5.setBookDetails("The Lord Of The Rings", "J.R.R Tolkien", "TIKI1102", false);
	Book book6;
	book6.setBookDetails("Bridgerton", "Julia Quinn", "SEGA1708", true);

	myArray[0] = book1;
	myArray[1] = book2;
	myArray[2] = book3;
	myArray[3] = book4;
	myArray[4] = book5;
	myArray[5] = book6;

	int option;
	while (true) {
		showMenu();
		cout << "Select an option: ";
		cin >> option;
		if (option == 1) {
			showAllBooks();
		}
		if (option == 2) {
			string isbnToBorrow = "";
			while (isbnToBorrow != "0") {
				cout << "==> Enter the book's ISBN you want to borrow or tap 0 (zero) to exit: ";
				cin >> isbnToBorrow;

				for (int i = 0; i < totalBooks; i++) {
					if (myArray[i].isbn == isbnToBorrow) {
						if (myArray[i].borrowBook()) {
							cout << "==> You have borrowed the book: " << myArray[i].title 
								<< " Written by: " << myArray[i].author << endl;
							cout << "Don't forget to return the book: " << myArray[i].title << endl;
							break;
						}
						else { // we couldn't borrow the book
							cout << "==> The book " << myArray[i].title << " is unavailable." << endl;
						}
					}
				}
			}
		}
		if (option == 3) {
			string isbnToReturn;
			cout << "==> Enter the ISBN of the book you want to return or 0 (zero) to exit: ";
			cin >> isbnToReturn;

			for (int i = 0; i < totalBooks; i++) {
				if (myArray[i].isbn == isbnToReturn) {
					myArray[i].returnBook();
					cout << "==> You have returned the book: " << myArray[i].title
						<< " Written by: " << myArray[i].author << endl;
				}
			}
		}
		if (option == 4) {
			cout << "Bye-Bye thank you for you visit!" << endl;
			cout << "Hope to see you again!" << endl;
			break;
		}
	}

}

void showMenu() {
	cout << "========================================" << endl;
	cout << "=                OPTIONS               =" << endl;
	cout << "= 1: Show all books                    =" << endl;
	cout << "= 2: Borrow Books                      =" << endl;
	cout << "= 3: Return Books                      =" << endl;
	cout << "= 4: EXIT the program                  =" << endl;
	cout << "========================================" << endl;
}

void showAllBooks() {
	for (int i = 0; i < totalBooks; i++) {
		cout << "ISBN: " << myArray[i].isbn << ", "
			<< "Title: " << myArray[i].title << ", "
			<< "Author: " << myArray[i].author << ", "
			<< "Available: " << myArray[i].available << endl;
	}
	cout << endl;
}