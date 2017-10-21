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
	pTop = new Element ( val, pTop );

}

int Stack::Pop ( )
{
	if ( Empty ( ) ) {
		return -1;
	}
	else {
		const int tempVal = pTop->GetValue ( );
		const auto pTemp = pTop;
		pTop = pTop->Detach ( );
		delete pTemp;
		return tempVal;
	}
}

int Stack::Size ( ) const
{
	if ( Empty ( ) ) {
		return 0;
	}
	else {
		return ( pTop->CountElements ( ) );
	}
}

bool Stack::Empty ( ) const
{
	return ( pTop == nullptr );
}


int Stack::Element::GetValue ( ) const
{
	return val;
}

Stack::Element* Stack::Element::Detach ( )
{
	auto pTemp = pNext;
	pNext = nullptr;
	return pTemp;
}

int Stack::Element::CountElements ( ) const
{
	if ( pNext != nullptr ) {
		return pNext->CountElements ( ) + 1;
	}
	else {
		return 1;
	}
}
