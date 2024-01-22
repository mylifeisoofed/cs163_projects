#include <iostream>
#include <cctype>
#include <cstring>

// Brian Le
// The purpose of this code is to assemble the Book object from the client program


#ifndef BOOK
#define BOOK

// Constants
const int MAX {5}; // For each node, there will be a maximum of 5 books.

class book
{
	public:
		book(); // Constructor
		~book(); // Destructor

		// Function to create a book with its data:
		int create_book(char author[], char title[], char publisher[], int page);

		// Function to copy book that can be invoked by other classes:
		int copy_book(const book & new_book);

		// Function to display the book's author, title, etc:
		int display();
	private:
		char * author;
		char * title;
		char * publisher;
		int page;
};
		
#endif
