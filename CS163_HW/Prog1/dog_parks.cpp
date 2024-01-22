#include "dogs_park.h"
using namespace std;

// Brian Le
// These are the function implementations from the .h file. 


DogsParkUnlimited::DogsParkUnlimited() // constructor
{
	park_head = NULL;	
	park_tail = NULL;	
}

DogsParkUnlimited::~DogsParkUnlimited() 
{
	if (park_head != nullptr)
	{
		park_node * park_current = park_head; // pointer to delete the park nodes.
		amenity_node * amenity_current; // pointer to delete the amenity list attached to each node.

		while (park_current != nullptr) // loop to step in to each park nodes.
		{
			if (park_current->name != NULL) // deallocate the park's name.
				delete [] park_current->name;

			amenity_current = park_current->amenity_list; // setting park's amenity traversing pointer.

			while (amenity_current != NULL) // amenity list deallocation
			{
				if (amenity_current->feature != NULL) // deallocate amenity's name
					delete [] amenity_current->feature;

				amenity_current = amenity_current->next;

				if (park_current->amenity_list) // deallocating amenity node
					delete park_current->amenity_list;

				park_current->amenity_list = amenity_current;
			}

			// All contents inside the park node should be deallocated.
			park_current = park_current->next; // finally, delete the park node
			delete park_head;
			park_head = park_current;
		}

		park_head = nullptr;
		park_tail = nullptr;
	}
}


int DogsParkUnlimited::addpark(char park_toadd[]) // function to add to the LLL
{
	park_node * current = park_head;

	// Check to see if the dog park already exists.
	// Must perform these checks before allocating to prevent leaks.
	while (current)
	{
		if (strcmp(current->name, park_toadd) == 0) // if there is a matching node, do not add. return.
			return 0;
		current = current->next;
	}

	current = park_head; // reset it back to head

	// Memory allocation should perform if all is good.
	park_node * park_temp = new park_node; // create a node if no node yet.
	park_temp->name = new char[strlen(park_toadd) + 1]; 
	strcpy(park_temp->name, park_toadd); // copy to allocated string.
	park_temp->amenity_list = nullptr; // This is the 'head' of the amenity list.


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
		return 1;
}

int DogsParkUnlimited::addamenity(char park_name[], char amenity[], int rate) // function to display the list of amenities of that dog park.
{
	bool found = false;
	park_node * current = park_head;
	

	if (park_head == nullptr)
		return 0;

//	 traverse to check if the park entered exists in the list.
	while (current)
	{
		if (strcmp(current->name, park_name) == 0)
			found = true;
		current = current->next;
	}

	if (!found) // if it doesn't exist, exit out.
		return 0;

	current = park_head;

	
	while (strcmp(current->name, park_name) != 0) // traverse to that park.
	{
		current = current->next;
	}
	
	// Create my amenity_node
	amenity_node * temp = new amenity_node;
	temp->feature = new char[strlen(amenity) + 1];
	strcpy(temp->feature, amenity);
	temp->rating = rate;
	temp->next = nullptr;

	// Link the amenity list to the park node.
	if (current->amenity_list == NULL)
	{
		current->amenity_list = temp;
		return 1;
	}

	// If the amenity's rating is better than the one we are adding, put it at the back.
	if (current->amenity_list->rating > temp->rating)
	{
		current->amenity_list->next = temp;
		return 1;
	}

	// If the is an amenity with the same rating or, insert at the front.
	// If the amenity we are adding has a better rating, put it in front.
	if (current->amenity_list->rating < temp->rating
		       	|| current->amenity_list->rating == temp->rating)
	{
		temp->next = current->amenity_list;
		current->amenity_list = temp;
		return 1;
	}

	return 0;
}


int DogsParkUnlimited::display() // Wrapper function
{
	if (!park_head) // no list, no go	
		return 0;

	cout << "\nList of Dog Parks:" << endl;

	return display(park_head, park_tail);
}

int DogsParkUnlimited::display(park_node * head, park_node * tail) // function to display the list of parks iteratively.
{
	int count = 0;
	if (head == NULL) // end of list? pop the stack.
		return 1;

	if (head != NULL)
	{
		cout << head->name << endl;
		count = 0 + display(head->next, tail);
	}

	return count;
}


int DogsParkUnlimited::display_amenities(char park[]) // function to display the list of amenities of that dog park.
{
	park_node * current = park_head;
	amenity_node * amenity_current;

	if (park_head == nullptr) // no list, no output
		return 0;

	while (strcmp(park, current->name) != 0) // traverse to the node
	{
		current = current->next;
	}

	amenity_current = current->amenity_list;

	while (amenity_current)
	{
		cout << amenity_current->feature << '\t' << amenity_current->rating << " star" << endl;
		amenity_current = amenity_current->next;
	}

	return 1;
}

int DogsParkUnlimited::remove(char park_toremove[]) // function to remove the park passed in.
{
	park_node * current;
	park_node * previous;
	amenity_node * a_current;

	if (park_head == nullptr) // no list, dont run
		return 0;

	current = park_head;

	// if the park being removed is the first in the list.
	if (strcmp(current->name, park_toremove) == 0) 
	{
		a_current = current->amenity_list;
		// Delete the amenity list first
		while (a_current)
		{
			if (a_current->feature)
				delete [] a_current->feature;
			a_current = a_current->next;
			delete current->amenity_list;
			current->amenity_list = a_current;
		}

		if (current->next == nullptr) // if this is the onyl node
		{
			if (current->name)
				delete [] current->name;
			delete current;
			park_head = nullptr;
		}

		else // if there are more than one node
		{
			current = current->next;
			if (park_head->name)
				delete [] park_head->name;
			delete park_head;
			park_head = current;
		}
		return 1;
	}

	else
	{
		// traverse
		while (strcmp(current->name, park_toremove) != 0)
		{
			previous = current;
			current = current->next;
		}

		a_current = current->amenity_list;
		// delete the list of amenities.
		while (a_current)
		{
			if (a_current->feature)
				delete [] a_current->feature;
			a_current = a_current->next;
			delete current->amenity_list;
			current->amenity_list = a_current;
		}

		previous->next = current->next; // relink

		// delete
		if (current->name)
			delete [] current->name;
		delete current;
		return 1;
	}
}

