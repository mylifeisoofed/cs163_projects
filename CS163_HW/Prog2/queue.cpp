#include "queue.h"
using namespace std;

// Brian Le
// The purpose of this file is to implement the queue's member function

queue::queue()
{
	rear = nullptr;	
	top_index = 0;
}

queue::~queue()
{
	if (!rear)
		return;

	q_node * current = rear->next;
	q_node * temp;
	rear->next = nullptr;

	while (current)
	{
		temp = current;
		current = current->next;
		if (temp->classroom)
		{
			delete [] temp->classroom;
		}
		if (temp->assignment)
			delete [] temp->assignment;
		if (temp->date)
			delete [] temp->date;
		if (temp)
			delete temp;
	}

	rear = nullptr;
}

int queue::enqueue(stack & to_enqueue, char classname[], char assignment[], char date[])
{
	if (!rear)
	{
		rear = new q_node;
		
		to_enqueue.copy_stack(rear->list_of_books);

		rear->classroom = new char[strlen(classname) + 1];
		rear->assignment = new char[strlen(assignment) + 1];
		rear->date = new char[strlen(date) + 1];
		strcpy(rear->classroom, classname);
		strcpy(rear->assignment, assignment);
		strcpy(rear->date, date);

		rear->next = rear;
		return 1;
	}

	q_node * temp = rear->next;
	rear->next = new q_node;
	rear = rear->next;

	rear->classroom = new char[strlen(classname) + 1];
	rear->assignment = new char[strlen(assignment) + 1];
	rear->date = new char[strlen(date) + 1];
	strcpy(rear->classroom, classname);
	strcpy(rear->assignment, assignment);
	strcpy(rear->date, date);

	to_enqueue.copy_stack(rear->list_of_books);

	rear->next = temp;
	return 1;
}

int queue::display()
{
	if (!rear)
		return 0;

	return display(rear->next, rear);
}

int queue::display(q_node * head, q_node * rear)
{
	if (!head->classroom || !head->assignment || !head->date)
		return 0;

	if (head == rear)
	{
		cout << "\nClass: " << head->classroom << endl;
		cout << "Assignment: " << head->assignment << endl;
		cout << "Due Date: " << head->date << endl;
		cout << "\nAssigned books:\n";
		head->list_of_books.display();
		return 1;
	}

	cout << "\nClass: " << head->classroom << endl;
	cout << "Assignment: " << head->assignment << endl;
	cout << "Due Date: " << head->date << endl;
	cout <<"\nAssigned books:\n";
	head->list_of_books.display();
	return 1 + display(head->next, rear);
}

int queue::dequeue()
{
	q_node * current = rear->next;
	q_node * hold = current->next;

	if (current)
	{
		delete [] current->assignment;
		delete [] current->date;
		delete [] current->classroom;
		delete current;
	}
	rear->next = hold;
	return 1;
}
	
int queue::peek()
{
	rear->list_of_books.display();
	return 1;
}
