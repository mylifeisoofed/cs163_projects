#include "header.h"

int main()
{
	table my_table;
	table ret;
	char breed[SIZE];
	char category[SIZE];
	char personality[SIZE];
	char purpose[SIZE];
	char size[SIZE];
	char interest[SIZE];
	int rating;
	int test = 0;
	bool program = true;
	
	while (program)
	{
		switch (menu())
		{
			case 1: 
				cout << "Enter the breed: ";
				cin.get(breed, SIZE, '\n');
				cin.ignore(SIZE, '\n');

				cout << "Enter the category: ";
				cin.get(category, SIZE, '\n');
				cin.ignore(SIZE, '\n');

				cout << "Enter the personality: ";
				cin.get(personality, SIZE, '\n');
				cin.ignore(SIZE, '\n');

				cout << "Enter the purpose: ";
				cin.get(purpose, SIZE, '\n');
				cin.ignore(SIZE, '\n');

				cout << "Enter the size: ";
				cin.get(size, SIZE, '\n');
				cin.ignore(SIZE, '\n');

				cout << "Enter the interest: ";
				cin.get(interest, SIZE, '\n');
				cin.ignore(SIZE, '\n');
				
				cout << "Enter the rating: ";
				cin >> rating;
				cin.ignore(SIZE, '\n');

				my_table.add(breed, category, personality, purpose, size, interest, rating);

				break;
			case 2:
				my_table.display_all();
				break;
			case 3:
				cout << "Enter the breed you want to display" << endl;
				cin.get(breed, SIZE, '\n');
				cin.ignore(SIZE, '\n');

				my_table.display(breed);
				break;
			case 4:
				cout << "Enter the breed you want to retrieve: ";
				cin.get(breed, SIZE, '\n');
				cin.ignore(SIZE, '\n');
				cout << "Enter the personality you want to retrieve of this breed: ";
				cin.get(personality, SIZE, '\n');
				cin.ignore(100, '\n');

				ret.retrieve(my_table, breed, personality);		
				break;
			case 5:
				cout << "Enter a breed you want to remove: ";
				cin.get(breed, SIZE, '\n');
				cin.ignore(100, '\n');
				my_table.remove(breed);
				break;
			case 6:
				cout << "Enter the size you want to find: ";
				cin.get(size, SIZE, '\n');
				cin.ignore(100, '\n');

				my_table.display_size(size);
				break;
			case 7:
				ret.display_all();
				break;
			case 8:
				program = false;
				break;
		}
	}


	return 0;
}
