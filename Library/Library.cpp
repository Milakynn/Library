#include "Book.h"

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
	book5.setBookDetails("The Lord Of The Rings", " J R R Tolkien", "ZIA1102", false);

	Book myArray[5];
	myArray[0] = book1;
	myArray[1] = book2;
	myArray[2] = book3;
	myArray[3] = book4;
	myArray[4] = book5;

	string isbnToBorrow = "";
	while (isbnToBorrow != "0") {
		cout << "Input the book's ISBN you want to borrow: ";
		cin >> isbnToBorrow;

		for (int i = 0; i < 5; i++) {

			if (myArray[i].isbn == isbnToBorrow) {
				if (myArray[i].borrowBook()) {
					cout << "Don't forget to return the book: " << myArray[i].title << " Written by " << myArray[i].author << endl;
				}
				else { //we couldn't borrow the book
					cout << "The book " << myArray[i].title << " is unavailable" << endl;
				}
			}
		}
	}

}