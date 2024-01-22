#include "header.h"
using namespace std;

/* Brian Le
   The purpose of this file is to provide implementations for client side functions 
   */

int menu()
{
	int menu_choice = 0;
	cout << "Main Menu\n" << endl;
	cout << "1. Add an Animal" << endl;
	cout << "2. Load data from external data file" << endl;
	cout << "3. Display based on interest" << endl;
	cout << "4. Retrieve based on keyword" << endl;
	cout << "5. Delete an animal based on keyword of interest" << endl;
	cout << "6. Display animals based on Personality" << endl;
	cout << "7. Exit Program" << endl;
	cin >> menu_choice;
	cin.ignore(100, '\n');

	return menu_choice;
}

void lowercaser(char convert[])
{
	int length = strlen(convert);
	for (int i = 0; i < length; ++i)
	{
		convert[i] = tolower(convert[i]);
	}
}
