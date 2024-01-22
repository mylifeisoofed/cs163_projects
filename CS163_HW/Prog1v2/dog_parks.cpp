#include "dogs_park.h"
using namespace std;

// Brian Le
// These are the function implementations from the .h file. 


DogsParkUnlimited::DogsParkUnlimited() // constructor
{
	park_head = NULL;	
	park_tail = NULL;
}

DogsParkUnlimited::~DogsParkUnlimited() // destructor
{
	if (park_head == nullptr)
		return;

	park_node * park_current = park_head; // pointer to delete the park nodes.

	while (park_current)
	{
		if (park_current->name != NULL) // delete the alocated name of the park
			delete [] park_current->name;

		park_current = park_current->next;
		delete park_head;
		park_head = park_current;
	}
}

int DogsParkUnlimited::addpark(char park_toadd[]) // function to add to the LLL
{
	park_node * park_temp = new park_node; // create a node if no node yet.
	park_temp->name = new char[strlen(park_toadd) + 1]; 
	strcpy(park_temp->name, park_toadd); // copy to allocated string.

	if (park_head == NULL) // If no list, create a node.
	{
		// Creating a node for the dog park.
		park_head = park_temp;
		park_head->next = NULL;
		park_tail = park_head;
		return 1;
	}

	if (park_head != NULL) // If there is an existing list append.
	{
		park_tail->next = park_temp;
		park_tail = park_tail->next;
		park_tail->next = NULL;
		return 1;
	}

	else
		return 0;
}

int DogsParkUnlimited::addamenity(char park_name[], char amenity[], int rate) // function to display the list of amenities of that dog park.
{
	bool done = false;
	park_node * current = park_head;

	if (park_head == nullptr)
		return 0;

	while (strcmp(current->name, park_name) != 0)
	{
		current = current->next;
	}

	/*
	// create the amenity node	
	amenity_node * temp = new amenity_node;
	temp->feature = new char[strlen(amenity) + 1];
	strcpy(temp->feature, amenity);
	temp->rating = rate;
	temp->next = nullptr;

	// Link.
	if (current->amenity_list == nullptr)
	{
		current->amenity_list = temp;
		return 1;
	}

	if (current->amenity_list->rating < temp->rating)
	{
		current->amenity_list->next = temp;
		return 1;
	}

	if (current->amenity_list->rating > temp->rating)
	{
		temp->next = current->amenity_list;
		current->amenity_list = temp;
		return 1;
	}
	*/

	return 1;
}


int DogsParkUnlimited::display() // Wrapper function
{
	if (!park_head) // no list, no go	
		return 0;

	return display(park_head, park_tail);
}

int DogsParkUnlimited::display(park_node * head, park_node * tail) // function to display the list of parks iteratively.
{
	int count = 0;
	if (head == NULL) // end of list? pop the stack.
		return 1;

	if (head != NULL)
		cout << head->name << endl;
		count = 0 + display(head->next, tail);

	return count;
}


int display_amenities(int selection) // function to display the list of amenities of that dog park.
{
	
}




