#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>

/* Brian Le
   The purpose of this header file is to develop the hash table structure.
   */

const int MAX = 100;

struct node // node for our animals.
{
	char * breed;
	char * category; // eg dog, cat, etc.
	char * personality; 
	char * purpose; // eg guard dogs
	char * size;
	char * interest; // eg loyal, stubborn
	int rating; // out of 5

	node * next;
};

class table
{
	public:
		table(int size = 7); // constructor initializing the hashtable size to 7.
		~table(); // destructor
		int add(char breed[], char category[], char personality[], char purpose[], char size[], char interest[], int rating); // function to add animals.
		int display(char keyword[]); // function to display certain animals based on the keyword of interest
		int retrieve(char keyword[], table & petlist); // function to retrieve and copy a hashtable to another based on keyword of interest.

		int remove (char keyword[]); // function to remove based on keyword of interest.
		int remove (char keyword[], node *& head);

		int display_personality(char keyword[]); // function
		int display_personality(char keyword[], node * head);
		int load(); // function to open the external file and load it's contents into the hashtable.

	private:
		int hash_function(char * key);

		node ** hashtable;
		int hashtable_size;
};

int menu(); // client interface
void lowercaser(char convert[]); // function to lowercase array of characters
