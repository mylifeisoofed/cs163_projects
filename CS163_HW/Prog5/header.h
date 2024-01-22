#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
#include <list>

struct decision
{
	char * name;
};

struct vertex // we will make an adjacency list of vertices.
{
	decision option;
	struct node * head;
};

struct node // these will represent the vertices that are part of the another vertex in the adj list.
{
	vertex * adjacent;

	node * next;
};

class table
{
	public:
		table(); // may need to dynamically allocate later.
		~table();
		int initialize(int size);
		int insert_vertex(const decision & to_add); // insert vertex
		int findloc(char key[]); // location finder
		int insert_edge(char current[], char to_attach[]); // attatch a vertex to an existing vertex.
		int display();
		int copy(const decision & source, decision & copy_to);
		int depth(char key[]);
		int bfs(char key[]);

	private:
		vertex * list;
		bool * flag;
		int list_size;

		int remove(node * & head);

		int display(node * head);

		int depth(node * head, int loc);

		int bfs(node * head, int loc);
};


int menu();
	
