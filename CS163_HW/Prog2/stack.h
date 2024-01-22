#include "book.h"
using namespace std;

// Brian Le
// The purpose of this file is to create our stack of books.
//

// Constants



// Structs

struct s_node 
{
	// This node can be seen as "Reading Assignments".
	
	book * s_books;
	s_node * next;
};


// Class

class stack
{
	public:
		stack(); // Constructor
		~stack(); // Deestructor
		int push(const book & to_add); // function to push the book into the stack.
		int pop(); // function to pop the top of the stack.
		int peek(book & to_peek); // function to peek the top of the stack
		int copy_stack(stack & copy_to); // function to copy this stack into the passed in arguement stack.	

		int display(); // recursive function to display.
		int display(s_node * head, int top_index);
	private:
		s_node * head; // The top of the list.
		int top_index; // Here to manage the stack
};


// Prototypes

