#include "list.h"

List :: List () : _elements () {}

List :: List ( vector < Term * > const & elements ) : _elements ( elements ) {}

string List :: symbol () const {
	if ( !_elements.size() )
		return "[]";
	else {
		string ret = "[";
		for ( int i = 0 ; i < _elements.size() - 1 ; i++ )
			ret += _elements[i] -> symbol() + ", ";
		ret += _elements [ _elements.size() - 1 ] -> symbol() + "]"; 
		return ret;
	}
}

string List :: value () const { 
	if ( !_elements.size() )
		return "[]";
	else {
		string ret = "[";
		for ( int i = 0 ; i < _elements.size() - 1 ; i++ )
			ret += _elements[i] -> value() + ", ";
		ret += _elements [ _elements.size() - 1 ] -> value() + "]"; 
		return ret;
	}	
}

int List :: getSize() { return _elements.size(); }

Term & List :: single ( int i ) { return *_elements[i]; }

Term * List :: head () const { 
	if ( !_elements.size() )
		throw std :: string ( "Accessing head in an empty list" );
	else
		return _elements[0]; 
}

List * List :: tail () const {
	if ( !_elements.size() )
		throw std :: string ( "Accessing tail in an empty list" );
	else{
		std :: vector < Term * > tail ( _elements.begin() + 1 , _elements.end() );
		return new List (tail);
	}
}

bool List :: match ( Term & term ) {
	List * ls = dynamic_cast < List * > ( &term );
	if ( _elements.size() == ls -> getSize() ) {
		for ( int i = 0 ; i < _elements.size() - 1 ; i++ )
			_elements[i] -> match ( ( ls -> single(i)) );
		return true;
	}
	else
		return false;	
} 
