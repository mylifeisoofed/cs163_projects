#include "header.h"
using namespace std;

// Brian Le
// This program is to demonstrate the Graph data structure using an Adjacency list.

int main()
{
	decision my_decision;
	table my_table;
	int size = 0;
	char user[100];
	char from[100];
	char to[100];
	bool program = true;
	int select = 0;

	cout << "Enter the number of data you want to add: ";
	cin >> size;
	cin.ignore(100, '\n');

	my_table.initialize(size);


	while (program)
	{
		select = menu();

		switch(select)
		{
			case 1:
				cout << "Enter the data: ";
				cin.get(user, 100, '\n');
				cin.ignore(100, '\n');

				my_decision.name = new char[strlen(user) + 1];
				strcpy(my_decision.name, user);
				
				my_table.insert_vertex(my_decision);
				delete [] my_decision.name;
				break;

			case 2:
				cout << "Enter the data you want to connect from: ";
				cin.get(from, 100, '\n');
				cin.ignore(100, '\n');

				cout << "Enter the data you are connecting to: ";
				cin.get(to, 100, '\n');
				cin.ignore(100, '\n');

				my_table.insert_edge(from, to);
				break;
				
			case 3:
				my_table.display();
				break;
			case 4:
				program = false;
				break;
			case 5:
				cout << "Enter the data you want to start the depthfirst search" << endl;
				cin.get(user, 100, '\n');
				cin.ignore(100, '\n');

				cout << "From " << user << " we can go to:" << endl;
				my_table.depth(user);
				break;

			case 6:
				cout << "Enter the data to start with for BFS" << endl;
				cin.get(user, 100, '\n');
				cin.ignore(100, '\n');

				cout << "Starting at " << user << ": " << endl;
				my_table.bfs(user);
				break;
		}
	}

	return 0;
}
