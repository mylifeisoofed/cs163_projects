#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>

// Brian Le
// This header file contains the data structure that will be performing data abstraction. The Dogs Park
// Unlimited class will be handling my data structure.

// Structs
struct amenity_node // The list of amenities that will be give to each park node.
{
	char * feature;
	int rating;
	amenity_node * next;
};

struct park_node // For every node of dog parks, it will contain (or point) to a list of ammenities!
{
	char * name;
	park_node * next;
	amenity_node * amenity_list; // This is for pointing to the list of ammenities.
};

// Class
class DogsParkUnlimited // Class that will be handling the data structure.
{
	public:
		DogsParkUnlimited(); // constructor
		~DogsParkUnlimited(); // destructor
		int addpark(char park_toadd[]); // function to add parks and amenities to the LLL
		int addamenity(char park_name[], char amenity[], int rating); // function to add amenities to the LLL
		int display(); // wrapper function.
		int display(park_node * head, park_node * tail); // function to recursively display.
		int display_amenities(); // function to display the list of amenities of that dog park.
		int remove(char park_toremove[]); // function to remove nodes in the LLL
		
	private:
		park_node * park_head; // head for parks
		park_node * park_tail; // tail for parks
};

// Functions
void menu(); // Function to display the main menu and the list of options.



