#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

// Brian Le
// The purpose of this file is to provide the client program with the functions needed.


// Functions
int menu()
{
	int choice = 0;

	cout << "Main Menu" << endl;
	cout << "1) Add a book to an assignment.\n"
		"2) Display all books\n"
		"3) Remove the most recent book\n"
		"4) Display the book the most recent book added\n"
		"5) Create Assignment\n"
		"6) Display Assignments\n"
		"7) Remove Oldest Assignment\n"
		"8) Display the Oldest Assignment\n"
		"10) Exit program\n";


	cin >> choice;
	cin.ignore(100, '\n');

	return choice;
}

