#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
using namespace std;
/* Brian Le
   The purpose of this header file is to plan and prototype the data structure.
   The data structure I am using is the BST
   */


const int SIZE {100};

struct animal
{
	char * breed;
	char * category;
	char * personality;
	char * purpose;
	char * size;
	char * interest;
	int rating;
};

struct node
{
	animal Animal;
	node * left;
	node * right;
};

class table // this is the bst class
{
	public:
		table(); // constructor
		~table(); // destructor
		
		//int add(char breed[], char category[], char personality[],
		//		char purpose[], char size[], char interest[], int rating);

		int add(char breed[], char category[], char personality[], char purpose[], char size[], char interest[], int rating);


		int display_all(); // display in sorted order
		int display(char breed[]); // display all animals within the breed
		int display_size(char size[]);
		
		int retrieve(const table & copy_from, char breed[], char personality[]); // Still figuring what array to pass in here?

		int remove(char breed[]); // remove node
		int remove_node(animal & toremove); // removing the individual node.
		int copy_node(animal & copyinto, animal & copyfrom); 
		int ios_finder(node *& iosanimal, animal & tobereplaced);

		int remove_all(); // remove entire bst. should be called by destructor.

	private:
		node * root;

		int add(char breed[], char category[], char personality[], char purpose[], char size[], char interest[], int rating, node *& root);

		int display_all(node * root);

		int display(char breed[], node * root); // recursive call

		int display_size(node * root, char size[]);

		int retrieve(node *& dest_root, node * source_root, char breed[], char personality[]); // recursive call.

		int remove(char breed[], node *& root); // 

		int remove_all(node *& root); // recursive call

};


int menu();


