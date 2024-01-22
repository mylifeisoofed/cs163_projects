#include "header.h"
using namespace std;

table::table()
{
	list_size = 0;
	list = nullptr;
	flag = nullptr;
}

table::~table()
{
	if (!list)
		return;

	for (int i =0; i < list_size; ++i)
	{
		delete [] list[i].option.name;
		remove(list[i].head);
	}

	delete [] list;
	delete [] flag;
}

int table::initialize(int size)
{
	list_size = size;
	list = new vertex[list_size];
	flag = new bool[list_size];

	for (int i = 0; i < list_size; ++i)
	{
		list[i].head = nullptr;
		list[i].option.name = nullptr;
		flag[i] = false;
	}

	return size;
}

int table::findloc(char key[]) // finds and returns the index of the adjacency list.
{
	// This function is mainly used to check if the data the user wants to find really exists.
	int spot = 0;
	bool match = false;

	if (!list)
		return 0;


	for (int i = 0; i < list_size && !match; ++i)
	{
		if (list[i].option.name && strcmp(list[i].option.name, key) == 0)
		{
			spot = i;
			match = true;
		}
	}

	if (!match)
		return -1;
	return spot;
}

int table::copy(const decision & source, decision & copy_to)
{
	// Simply copies the data
	if (!source.name)
		return 0;

	if (!copy_to.name)
	{
		copy_to.name = new char[strlen(source.name) + 1];
		strcpy(copy_to.name, source.name);
	}
	
	return 1;
}

int table::insert_vertex(const decision & to_add) // Inserts a vertex
{
	if (!list)
		return 0;

	bool added = false;
	int i = 0;
	// go through the adjacency list and make sure there does not exist
	// this data being inserted.
	for (i = 0; i < list_size && !added; ++i)
	{
		if (list[i].option.name == nullptr) // if a spot in the adj list is not occupied, insert it in.
		{
			copy(to_add, list[i].option);
			added = true;
		}
	}

	if (i == list_size)
		return 0;
	return 1;
}

int table::insert_edge(char current[], char to_attach[]) // making a connection between two vertices.
{
	// the edges has to be in the list that the user have entered in the first place.
	int currentloc = findloc(current);
	int attachloc = findloc(to_attach);

	if (currentloc < 0 || attachloc < 0)
		return 0;

	node * temp = list[currentloc].head;
	list[currentloc].head = new node;
	list[currentloc].head->next = temp;

	list[currentloc].head->adjacent = &list[attachloc]; // adjacent is still a pointer pointing to null, so we have it
	// point to the address of the vertex in the adj list that  we want it to connect.
	return 1;
}

int table::display()
{
	int count = 0;
	for (int i = 0; i < list_size; ++i) // we will first iterate the adj list
	{
		cout << list[i].option.name << " is adjacent to: " << endl;
		count = display(list[i].head);
		cout << '\n';
	}

	return count;
}

int table::display(node * head) // displays the vertices that are adjacent
{
	if (!head)
		return 0;

	cout << head->adjacent->option.name << endl;

	return 1 + display(head->next);
}

int table::remove(node *& head) // deallocation
{
	int count = 0;
	if (!head)
		return count;

	count = count + remove(head->next);

	delete head;
	return count;
}

int table::depth(char key[]) // DFS
{
	if (!list)
		return 0;

	node * current = list[findloc(key)].head;

	while (current && !flag[findloc(current->adjacent->option.name)])
	{
		cout << current->adjacent->option.name << '\t';
		flag[findloc(current->adjacent->option.name)] = true;
		depth(current->adjacent->option.name);
		cout << '\n';
		current = current->next;
	}

	for (int i = 0; i < list_size; ++i)
		flag[i] = false;

	return 1;
}

int table::bfs(char key[]) // BFS
{
	if (!list)
		return 0;

	std::list<char*> queue;
	char colors[list_size] = {'g'}; // g = gray, w = white, b = black
	int s = findloc(key);
	node * current = list[s].head;

	flag[s] = true; // visit flags
	queue.push_back(list[s].option.name);

	while(!queue.empty())
	{
		cout << list[findloc(queue.front())].option.name << " ";
		current = list[findloc(queue.front())].head;
		queue.pop_front();

		while (current != nullptr)
		{
			int visited = findloc(current->adjacent->option.name);
			if (!flag[visited])
			{
				flag[visited] = true;
				queue.push_back(list[visited].option.name);
			}

			current = current->next;
		}
	}


	for (int i = 0; i < list_size; ++i)
		flag[i] = false;

	return 1;
}



int menu()
{
	int user = 0;

	cout << "1) Insert\n"
		"2) Connect data\n"
		"3) Display\n"
		"4) Exit Program\n"
		"5) Depth First Search\n" 
		"6) Breadth First Search" << endl;

	cin >> user;
	cin.ignore(100, '\n');

	return user;
}






	
	
