#include "header.h"
using namespace std;
/* Brian Le
   The purpose of this program is to test the hash table data astructure.
   */

int main()
{
	char breed[MAX];
	char category[MAX];
	char personality[MAX];
	char purpose[MAX];
	char size[MAX];
	char interest[MAX];
	char koi[MAX];
	int rating {0};
	bool program = true;
	int choice;

	table my_table;
	table my_pet; 

	while (program)
	{
		choice = menu();

		switch (choice)
		{
			case 1:
				cout << "Enter the breed: ";
				cin.get(breed, 100, '\n');
				cin.ignore(100, '\n');
				lowercaser(breed);

				cout << "Enter the category: ";
				cin.get(category, 100, '\n');
				cin.ignore(100, '\n');
				lowercaser(category);


				cout << "Enter the personality: ";
				cin.get(personality, 100, '\n');
				cin.ignore(100, '\n');
				lowercaser(breed);

				cout << "Enter the purpose: ";
				cin.get(purpose, 100, '\n');
				cin.ignore(100, '\n');
				lowercaser(purpose);

				cout << "Enter the size: ";
				cin.get(size, 100, '\n');
				cin.ignore(100, '\n');
				lowercaser(size);

				cout << "Enter the interest: ";
				cin.get(interest, 100, '\n');
				cin.ignore(100, '\n');
				lowercaser(interest);

				cout << "Enter the rating: ";
				cin >> rating;
				cin.ignore(100, '\n');

				my_table.add(breed, category, personality, purpose, size, interest, rating);
				break;
				
			case 2:
				my_table.load();
				break;
				
			case 3:

				cout << "Enter the keyword of interest you want to find: ";
				cin.get(koi, 100, '\n');
				cin.ignore(100, '\n');

				cout << '\n';
				my_table.display(koi);
				break;

			case 4:

				my_table.retrieve(koi, my_pet);
				my_pet.display(koi);
				break;
				
			case 5:
				cout << "Enter the keyword of interest that you want to delete: ";
				cin.get(koi, 100, '\n');
				cin.ignore(100, '\n');

				my_table.remove(koi);
				break;

			case 6:
				cout << "Enter the keyword of personality you want to display" << endl;
				cin.get(koi, 100, '\n');
				cin.ignore(100, '\n');
				my_table.display_personality(koi);

			case 7:
				program = false;
				break;
		}

	}

	return 0;
}

