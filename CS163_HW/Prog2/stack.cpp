#include "stack.h"
using namespace std;

// Brian Le
// The purpose of this file is to implement the stack's memeber functions
// Stacks are designed where the top_index is the head of this LLL implemented stack.
// We can imagine an LLL and when we push, we add in front of head and that becomes the new top index and head.

stack::stack()
{
	head = nullptr;
	top_index = 0;
}

stack::~stack()
{
	s_node * current = head;
	
	while (current)
	{
		current = current->next;

		if (head->s_books)
			delete [] head->s_books;
		if (head)
			delete head;
		head = current;
	}

	head = nullptr;
}

int stack::push(const book & to_add)
{
	if (!head || top_index == MAX) // case where the list is empty or when the stack is full.
	{
		top_index = 0;

		s_node * temp = head;
		head = new s_node;
		head->next = temp;

		head->s_books = new book[MAX];
		head->s_books[top_index].copy_book(to_add);
		++top_index;

		return 1;
	}

	else 
	{
		head->s_books[top_index].copy_book(to_add);
		++top_index;
		return 1;
	}
}

int stack::peek(book & to_peek)
{
	if (!head)		
		return 0;

	if (top_index == 0)
		return 0;

	else
	{
		to_peek.copy_book(head->s_books[top_index - 1]);
		return 1;
	}
}


int stack::display()
{
	if (!head)
		return 0;

	return display(head, top_index);
}

int stack::display(s_node * head, int top_index)
{
	if (!head)
		return 0;

	if (top_index <= 0)
	{
		if (head->next)
			top_index = MAX;

		return display(head->next, top_index);
	}

	if (top_index > 0)
	{
		head->s_books[top_index - 1].display();
		--top_index;
		return 1 + display(head, top_index);
	}	

	return 0;
}

int stack::pop()
{
	if (!head)
		return 0;

	if (top_index == 0)
	{
		s_node * temp = head->next;

		if (head->s_books)
			delete [] head->s_books;
		delete head;
		head = temp;
		if (temp)
			top_index = MAX;
		return 1;
	}

	else
	{
		--top_index;
		return 1;
	}
}

int stack::copy_stack(stack & to_copy)
{
	// working with the stack that we ant to copy into.
	if (!head)
		return 0;

	if (!to_copy.head)
		to_copy.head = new s_node;
	
	to_copy.head->s_books = new book[MAX];
	
	s_node * current = head;
	s_node * new_current = to_copy.head;
	
	while  (current)
	{
		for (int i = 0; i < MAX; ++i)
		{
			to_copy.push(current->s_books[i]);
		}
		
		current = current->next;
		if (!current)
			new_current->next = nullptr;
		else
		{
			new_current = new_current->next;
			new_current = new s_node;
			new_current->s_books = new book[MAX];
			new_current->next = nullptr;
		}
	}

	return 1;
}


