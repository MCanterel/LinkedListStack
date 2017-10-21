#pragma once
#include <iostream>

class Stack {
private:
	class Element {
	public:
		int val;
		Element *next;
		Element ( ) : next ( nullptr ) {};
		Element ( int val ) :val ( val ), next ( nullptr ) {};
		/*~Element ( ) {
			delete next;
			next = nullptr;
		}*/
	};
private:
	Element *head;
	Element *tail;
public:
	Stack ( ) {
		head = nullptr;
		tail = nullptr;
	}
	Stack ( const Stack& source ) {
		head = source.head;
		tail = source.tail;
	}
	/*Stack& operator=( const Stack& source ) {

	}*/

	~Stack ( ) {
		//delete head;
		//delete tail;
		//head = nullptr;
		//tail = nullptr;
	}
	//void Print ( );

	void Push ( int val );
	int Pop ( );  //not done...
	int Size ( ) const;
	bool Empty ( ) const;
};
