#include "stack.h"
// Brian Le
// The purpose of this header file is to create a CLL with queue data structure.

// Constants

// Struct
struct q_node
{
	char * classroom;
	char * assignment;
	char * date;
	stack list_of_books;

	q_node * next;
};

// Class
class queue
{
	public:
		queue();
		~queue();
		int enqueue(stack & to_enqueue, char classname[], char assignment[], char date[]); // function to enqueue the stack into the CLL node.
		int dequeue(); // function to dequeue the oldest node of the CLL
		int peek(stack & to_peek); // function to peek the latest node of the CLL
		int copy(stack & copy_to); // function to copy the passed in stack into the queue's stack object.

		int display(); // recursive function to display the stack.
		int display(q_node * front, q_node * rear);
		
		int peek(); // function to peek the stack. No need to pass in a queue object unlike the stack.
	private:
		q_node * rear;
		int top_index;
};

