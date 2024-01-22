#include "queue.h"
#include "functions.h"
using namespace std;

// Brian Le
// The purpose of this program is to test the data structure's functions.

int main()
{
	char author[100];
	char title[100];
	char publisher[100]; 
	int page;
	int choice;
	bool program = true;

	char classroom[100];
	char assignment[100];
	char date[100];
	int test;

	book my_book;
	book my_peek;

	stack my_stack;
	queue my_queue;

	while (program)
	{

		choice = menu();

		switch (choice)
		{
			case 1:
				cout << "Enter the author: ";
				cin.get(author, 100, '\n');
				cin.ignore(100, '\n');

				cout << "Enter the title: ";
				cin.get(title, 100, '\n');
				cin.ignore(100, '\n');

				cout << "Enter the publisher: ";
				cin.get(publisher, 100, '\n');
				cin.ignore(100, '\n');

				cout << "Enter the bookmarked page: ";
				cin >> page;
				cin.ignore(100, '\n');

				my_book.create_book(author, title, publisher, page);
				my_stack.push(my_book);
				break;
			case 2:
				my_stack.display();
				break;
			case 3:
				my_stack.pop();
				break;
			case 4:
				my_stack.peek(my_peek);
				my_peek.display();
				break;
			case 5:
				cout << "Enter the name of the class" << endl;
				cin.get(classroom, 100, '\n');
				cin.ignore(100, '\n');

				cout << "Enter the name of the assignment" << endl;
				cin.get(assignment, 100, '\n');
				cin.ignore(100, '\n');

				cout << "Enter the due date" << endl;
				cin.get(date, 100, '\n');
				cin.ignore(100, '\n');

				my_queue.enqueue(my_stack, classroom, assignment, date);
				break;
			case 6:
				my_queue.display();
				break;
			case 7:
				my_queue.dequeue();
				break;
			case 8:
				my_queue.peek();
				break;
			case 10:
				program = false;
				break;
					
		}
	}

	return 0;
}
