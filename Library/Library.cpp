#include "Book.h"

void showMenu();
void showAllBooks();
void addNewBooks();
void sortBooks();

Book myArray[300];
int totalBooks = 6;

int main() {
  
	Book book1;
	book1.setBookDetails("After", "Anna Todd", "LIN1108", true); // Book is available
	Book book2;
	book2.setBookDetails("Harry Poter", "J.K Rowling", "DAM1703", false); // Book is not available
	//Book book3;
	//book3.setBookDetails("The Summer I Turned Pretty", "Jenny Han", "MAM2301", true); // Book is available
	Book book3;
	book3.setBookDetails("A Game Of Thrones", "George.R Martin", "PAP0408", true); // Book is available
	//Book book5;
	//book5.setBookDetails("The Lord Of The Rings", "J.R.R Tolkien", "TIKI1102", false); // Book is not available
	//Book book6;
	//book6.setBookDetails("Bridgerton", "Julia Quinn", "SEGA1708", true); // Book is available

	myArray[0] = book1; 
	myArray[1] = book2;
	//myArray[2] = book3;
	myArray[2] = book3;
	//myArray[4] = book5;
	//myArray[5] = book6;

	int option;
	while (true) {
		showMenu(); 
		cout << "Select an option: ";
		cin >> option;
		if (option == 1) {
			showAllBooks();
		}
		if (option == 2) {
			cout << "========================================" << endl;
			cout << "=          Borrow Book                 =" << endl;
			cout << "========================================" << endl;
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
			cout << "========================================" << endl;
			cout << "=          Return Book                 =" << endl;
			cout << "========================================" << endl;
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
			addNewBooks();
		}
		if (option == 5) {
			sortBooks();
		}
		if (option == 6) {
			cout << "Bye-Bye thank you for you visit!" << endl;
			cout << "Hope to see you again!" << endl;
			break;
		}
	}

}

void showMenu() {
	cout << "========================================" << endl;
	cout << "=          Library System              =" << endl;
	cout << "========================================" << endl;
	cout << "= 1: Show all books                    =" << endl;
	cout << "= 2: Borrow Books                      =" << endl;
	cout << "= 3: Return Books                      =" << endl;
	cout << "= 4: Add New Books                     =" << endl;
	cout << "= 5: Sort Books                        =" << endl;
	cout << "= 6: EXIT the program                  =" << endl;
	cout << "========================================" << endl;
	cout << endl;
}

void showAllBooks() {
	cout << "========================================" << endl;
	cout << "=         Display library              =" << endl;
	cout << "========================================" << endl;
	int counter = 0;
	for (int i = 0; i < totalBooks; i++) {
		if (!myArray[i].isbn.empty() && !myArray[i].title.empty()) {
			cout << "Title: " << myArray[i].title << ", "
				<< "Author: " << myArray[i].author << ", "
				<< "ISBN: " << myArray[i].isbn << ", "
				<< "Available: " << myArray[i].available << endl;
				counter++;
		}
		
	}
	if (counter == 0) {
		cout << "==> There is No books registered in this library." << endl;
	}
	cout << endl;
}

void addNewBooks() {
	cout << "========================================" << endl;
	cout << "=          Add New Books               =" << endl;
	cout << "========================================" << endl;
	string title;
	string author;
	string isbn;
	bool available;
	int index = 0;
	char answer;
	bool addAnotherBook = true;
	while (addAnotherBook) {
		Book book;
		cin.ignore(); // Clear the newline character from the input buffer
		cout << "==> Enter the book's title: ";
		getline(cin, title);
		cout << "==> Enter the book's author: ";
		getline(cin, author);
		cout << "==> Enter the book's ISBN: ";
		getline(cin, isbn);
		/*cout << "==> Is the book available? (1 for Yes, 0 for No): ";
		cin >> available;*/
		book.setBookDetails(title, author, isbn, true);
		myArray[index] = book;
		cout << "==> Book " << book.title << " added successfully!" << endl;
		index++;
		cout << "Do you want to add another book? (Y/N): ";
		cin >> answer;
		if (answer == 'N' || answer == 'n') {
			addAnotherBook = false;
		} else if (answer != 'Y' && answer != 'y') {
			cout << "==> Invalid input. Please enter Y or N." << endl;
			continue; // Ask again
		}
	}
	cout << endl;
}

void sortBooks() {
	cout << "========================================" << endl;
	cout << "=          Sort Books                  =" << endl;
	cout << "========================================" << endl;
	// Simple bubble sort based on book titles
	for (int i = 0; i < totalBooks - 1; i++) {
		for (int j = i + 1; j < totalBooks; j++) {
			if (myArray[i].title > myArray[j].title) {
				Book temp = myArray[i];
				myArray[i] = myArray[j];
				myArray[j] = temp;
			}
		}
	}
	cout << "==> Books sorted successfully!" << endl;
	showAllBooks();
}