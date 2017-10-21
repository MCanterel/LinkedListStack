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

	Stack& operator=( const Stack& src ) {
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
