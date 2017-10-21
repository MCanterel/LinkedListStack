#pragma once
#include <iostream>

class Stack {
private:
	class Element {
	public:

		Element ( int val, Element* pNext ) 
			:val ( val ), pNext ( pNext ) {};

		Element ( const Element& src )
			:val ( src.val )
		{
			if ( src.pNext != nullptr ) {
				pNext = new Element ( *src.pNext );  //whoah
			}
		}

		~Element ( ) {
			delete pNext;  //this is recursive
			pNext = nullptr;
		}

		int GetValue ( ) const;
		Element* Detach ( );
		int CountElements ( ) const;
	private:
		int val;
		Element *pNext = nullptr;
	};

private:
	Element *pTop = nullptr;

public:
	Stack ( ) = default;

	Stack ( const Stack& src ) {
		*this = src;
	}

	~Stack ( ) {
		delete pTop;
		pTop = nullptr;
	}

	Stack& operator=( const Stack& src ) {

		if ( !Empty ( ) ) {  //need this if we try to copy assign on top of existing value
			delete pTop;
			pTop = nullptr;
		}
		if ( !src.Empty ( ) ) {
			pTop = new Element ( *src.pTop );
		}
		return *this;
	}

	void Push ( int val );
	int Pop ( );
	int Size ( ) const;
	bool Empty ( ) const;
	//void Print ( );

};
