#include "Stack.h"

//void Stack::Print ( )
//{
//	Element *p = head;
//	if ( p == nullptr ) {
//		std::cout << "The stack is empty." << std::endl;
//	}
//	std::cout << "Stack contents: " << std::endl;
//	while ( p != nullptr ) {
//		std::cout << p->val << ", ";
//		p = p->next;
//	}
//}

void Stack::Push ( int val )
{
	Element *temp = new Element ( val );

	if ( head == nullptr ) {
		head = temp;
		tail = temp;
	}
	else {
		tail->next = temp;
		tail = temp;
	}
}

int Stack::Pop ( )
{
	int val = -1;
	if ( head == nullptr ) {
		std::cout << "Nothing in the stack." << std::endl;
	}
	else if ( tail == head && head != nullptr ) {
		val = head->val;
		delete head;
		tail = nullptr;
		head = nullptr;
	}
	else
	{
		Element *temp = head;
		Element *tempPrev = head;
		while ( temp != tail ) {
			tempPrev = temp;
			temp = temp->next;
		}
		val = temp->val;
		delete temp;
		tail = tempPrev;
		tempPrev->next = nullptr;
	}
	return val;
}

int Stack::Size ( ) const
{
	if ( head == nullptr ) {
		return 0;
	}
	else {
		int count = 1;
		Element *temp = head;
		while ( temp->next != nullptr ) {
			temp = temp->next;
			count++;
		}
		return count;
	}
}

bool Stack::Empty ( ) const
{
	return ( head == nullptr && tail == nullptr );
}
