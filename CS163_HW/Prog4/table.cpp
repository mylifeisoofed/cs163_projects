#include "header.h"

table::table()
{
	// initializing root to null. empty tree.
	root = nullptr;
}

table::~table()
{
	remove_all();
}

int table::add(char breed[], char category[], char personality[], char purpose[], char size[], char interest[], int rating)
{
	if (!breed || !category || !personality || !purpose || !size || !interest)
		return 0;

	return add(breed, category, personality, purpose, size, interest, rating, root);
}


int table::add(char breed[], char category[], char personality[], char purpose[], char size[], char interest[], int rating, node *& root)
{
	if (!root)
	{
		root = new node;
		root->left = nullptr;
		root->right = nullptr;
		
		root->Animal.breed = new char[strlen(breed) + 1];
		strcpy(root->Animal.breed, breed);

		root->Animal.category = new char[strlen(category) + 1];
		strcpy(root->Animal.category, category);

		root->Animal.personality = new char[strlen(personality) + 1];
		strcpy(root->Animal.personality, personality);

		root->Animal.purpose = new char[strlen(purpose) + 1];
		strcpy(root->Animal.purpose, purpose);

		root->Animal.size = new char[strlen(size) + 1];
		strcpy(root->Animal.size, size);

		root->Animal.interest = new char[strlen(interest) + 1];
		strcpy(root->Animal.interest, interest);

		root->Animal.rating = rating;

		return 1;
	}

	if (strcmp(breed, root->Animal.breed) < 0)
	{
		add(breed, category, personality, purpose, size, interest, rating, root->left);
	}

	else if (strcmp(breed, root->Animal.breed) == 0)
	{
		if (strcmp(personality, root->Animal.personality) < 0)
			add (breed, category, personality, purpose, size, interest, rating, root->left);
		else
			add (breed, category, personality, purpose, size, interest, rating, root->right);
	}

	else
	{
		add(breed, category, personality, purpose, size, interest, rating, root->right);
	}

	return 1;
}

int table::display_all()
{
	if (!root)
		return 0; // empty tree

	return display_all(root);
}

int table::display_all(node * root)
{
	int count = 0;

	if (!root)
		return 0;

	count = 1 + display_all(root->left);

	cout << "Breed: " << root->Animal.breed << endl;
	cout << "Category: " << root->Animal.category << endl;
	cout << "Personality: " << root->Animal.personality << endl;
	cout << "Purpose: " << root->Animal.purpose << endl;
	cout << "Size: " << root->Animal.size << endl;
	cout << "Interest: " << root->Animal.interest << endl;
	cout << "Rating: " << root->Animal.rating << endl;
	cout << '\n';

	count = count + display_all(root->right);

	return count;
}

int table::display(char breed[])
{
	if (!root)
		return 0;

	return display(breed, root);
}

int table::display(char breed[], node * root)
{
	if (!root)
		return 0;

	if (strcmp(breed, root->Animal.breed) == 0)
	{
		display_all(root);
		return 1;
	}

	return display(breed, root->left) + display(breed, root->right);

}

int table::remove_all()
{
	if (!root)
		return 0;

	return remove_all(root);
}

int table::remove_all(node *& root)
{
	int count = 0;

	if (!root)
		return 0;

	count = 1 + remove_all(root->left);

	count = count + remove_all(root->right);

	if (root->Animal.breed)
		delete [] root->Animal.breed;

	if (root->Animal.category)
		delete [] root->Animal.category;

	if (root->Animal.personality)
		delete [] root->Animal.personality;

	if (root->Animal.purpose)
		delete [] root->Animal.purpose;
	
	if (root->Animal.size)
		delete [] root->Animal.size;

	if (root->Animal.interest)
		delete [] root->Animal.interest;
	root->Animal.rating = 0;
	delete root;
	root = nullptr;

	return count;
}

int table::retrieve(const table & copy_from, char breed[], char personality[])
{
	if (!copy_from.root)
		return 0;

	return retrieve(root, copy_from.root, breed, personality);
}

int table::retrieve(node *& dest_root, node * source_root, char breed[], char personality[])
{
	int count = 0;

	if (!source_root)
		return 0;

	if (!dest_root && strcmp(source_root->Animal.breed, breed) == 0 && strcmp(source_root->Animal.personality, personality) == 0)
	{
		add(source_root->Animal.breed, source_root->Animal.category, source_root->Animal.personality, source_root->Animal.purpose, 
				source_root->Animal.size, source_root->Animal.interest, source_root->Animal.rating);
	}

	count = 1 + retrieve(dest_root->left, source_root->left, breed, personality);
	count = count + retrieve(dest_root->right, source_root->right, breed, personality);

	return count;
}


int table::remove(char breed[])
{
	if (!root)
		return 0;

	return remove(breed, root);
}

int table::remove(char breed[], node *& root)
{
	if (!root)
		return 0;

	if (strcmp(breed, root->Animal.breed) == 0) // we are at the node we want to delete
	{
		// Case 1: This leaf has no child
		if (!root->left && !root->right)
		{
			remove_node(root->Animal);
			delete root;
			return 1;
		}

		// Case 2: There is one child node
		else if (root->left && !root->right)
		{
			remove_node(root->Animal);
			node * hold = root->left;
			delete root;
			root = hold;
			return 1;
		}

		else if (!root->left && root->right)
		{
			remove_node(root->Animal);
			node * hold = root->right;
			delete root;
			root = hold;
			return 1;
		}

		// Case 3: There are two child nodes
		else if (root->left && root->right)
		{
			// Finding the In Order Successor:
			// Step 1: Go the the right subtree
			ios_finder(root->right, root->Animal);
			return 1;
		}

	}

	return remove(breed, root->left) + remove(breed, root->right);
}

int table::ios_finder(node *& ios, animal & tobereplaced)
{
	if (!ios->left) // at the end
	{
		copy_node(tobereplaced, ios->Animal);
		// then delete this node
		remove_node(ios->Animal);
		delete ios;
		return 1;
	}

	ios_finder(ios->left, tobereplaced);

}

int table::copy_node(animal & copyinto, animal & copyfrom)
{
	strcpy(copyinto.breed, copyfrom.breed);	
	strcpy(copyinto.category, copyfrom.category);	
	strcpy(copyinto.personality, copyfrom.personality);	
	strcpy(copyinto.purpose, copyfrom.purpose);	
	strcpy(copyinto.size, copyfrom.size);	
	strcpy(copyinto.interest, copyfrom.interest);	
	copyinto.rating = copyfrom.rating;
	return 1;
}

int table::remove_node(animal & toremove)
{
	delete [] toremove.breed;
	delete [] toremove.category;
	delete [] toremove.personality;
	delete [] toremove.purpose;
	delete [] toremove.size;
	delete [] toremove.interest;
	return 1;
}

int table::display_size(char size[])
{
	if (!root)
		return 0;

	return display_size(root, size);
}

int table::display_size(node * root, char size[])
{
	if (!root)
		return 0;

	if (strcmp(root->Animal.size, size) == 0)
	{
		cout << "Breed: " << root->Animal.breed << endl;
		cout << "Category: " << root->Animal.category << endl;
		cout << "Personality: " << root->Animal.personality << endl;
		cout << "Purpose: " << root->Animal.purpose << endl;
		cout << "Size: " << root->Animal.size << endl;
		cout << "Interest: " << root->Animal.interest << endl;
		cout << "Rating: " << root->Animal.rating << endl;
		cout << '\n';
	}

	return display_size(root->left, size) + display_size(root->right, size);
}


	
// client side functions
int menu()
{
	int user = 0;
	cout << "Main Menu\n\n";

	cout << "1) Add a Pet\n"
		"2) Display all in sorted order\n"
		"3) Display all of a given breed\n"
		"4) Retrieve the information\n"
		"5) Remove all of a particular Breed\n"
		"6) Display all of a particular size\n"
		"7) Display retrieved pets\n"
		"8) Exit\n" << endl;

	cin >> user;
	cin.ignore(100, '\n');

	return user;
}

