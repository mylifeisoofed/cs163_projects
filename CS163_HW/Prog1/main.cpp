#include "dogs_park.h"
using namespace std;

// Brian Le
// This is the client program that will be testing my class's functions and operations.

int main()
{
	DogsParkUnlimited list;
	char user;
	int select;
	char park[100];
	char amenity[100];
	int done = 0;
	bool program = true;
	int rate;

	while (program) // The program.
	{
		menu();
		cin >> select;
		cin.ignore(100, '\n');

		switch (select)
		{
			case 1: // adding dog park
				done = 0;
				while (done == 0)
				{
					cout << "Enter the name of the dog park you want to add" << endl;
					cin.get(park, 100, '\n');
					cin.ignore(100, '\n');

					done = list.addpark(park);

					if (done == 0)
						cout << "The dog park already exists, please try again" << endl;
					else
					{
						cout << "Add more parks? (y/n): ";
						cin >> user;
						cin.ignore(100, '\n');

						
						if (user == 'y')
							done = 0;
					}
				}
				break;

			case 2: // adding amenity to a dog park
				list.display();
				cout << "Enter the name of the dog park you want to add amenities to" << endl;
				cin.get(park, 100 ,'\n');
				cin.ignore(100, '\n');

				cout << "Enter the amenity to add to this dog park" << endl;
				cin.get(amenity, 100, '\n');
				cin.ignore(100, '\n');

				cout << "Give a rating on scale from 1 to 5" << endl;
				cin >> rate;
				cin.ignore(100, '\n');

				done = list.addamenity(park, amenity, rate);

				if (done == 0)
					cout << "Operation failed. Please try again" << endl;
				break;

			case 3: // display a list of dog parks
				list.display();
				break;

			case 4: // display list of amenities of a dog park
				list.display();
				cout << "Enter the name of the dog park" << endl;
				cin.get(park, 100, '\n');
				cin.ignore(100, '\n');

				list.display_amenities(park);
				break;

			case 5: // removing a dog park.
				list.display();
				cout << "Enter the name of the dog park you want to remove" << endl;
				cin.get(park, 100, '\n');
				cin.ignore(100, '\n');
				list.remove(park);

				break;

			case 6: // exiting the program
				cout << "Thank's for testing the program" << endl;
				program = false;
				break;
			default:
				break;
		}
	}

	return 0;
}
