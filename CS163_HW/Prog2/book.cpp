#include "book.h"
using namespace std;

// Brian Le
// The purpose of this file is to implement the book's member function

book::book()
{
	title = nullptr;
	author = nullptr;
	publisher = nullptr;
	page = 0;
}

book::~book()
{
	if (title)
		delete [] title;
	if (author)
		delete [] author;
	if (publisher)
		delete [] publisher;

	title = nullptr;
	publisher = nullptr;
	author = nullptr;


	page = 0;
}

int book::create_book(char author[], char title[], char publisher[], int page)
{
	if (!title || !author || !publisher)
		return 0;

	if (this->author)
		delete [] this->author;
	if (this->title)
		delete [] this->title;
	if (this->publisher)
		delete [] this->publisher;

	this->author = new char[strlen(author) + 1];
	this->title = new char[strlen(title) + 1];
	this->publisher = new char[strlen(publisher) + 1];
	this->page = page;
	strcpy(this->author, author);
	strcpy(this->title, title);
	strcpy(this->publisher, publisher);
	return 1;
}

int book::display()
{
	if (!title || !author || !publisher)
		return 0;

	cout << "Title: " << title << endl;
	cout << "Written by: " << author << endl;
	cout << "Published by: " << publisher << endl;
	cout << "Bookmarked page: " << page << endl;	

	return 1;
}


int book::copy_book(const book & new_book)
{
	// Can access the new_book's private data members here.
	return create_book(new_book.author, new_book.title, new_book.publisher, new_book.page);
}
