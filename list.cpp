#include "list.h"
#include "variable.h"
#include <iostream>
using namespace std;
List :: List () : _elements () {}

List :: List (vector<Term *> const & elements):_elements(elements){}

string List :: symbol () const {
	if(_elements.size()>0)
		{
			string retsym = "[";
			for (int i=0;i< _elements.size()-1;i++)
			retsym += _elements[i] -> symbol() + ", ";
			retsym += _elements [_elements.size()-1] -> symbol() + "]"; 
			return retsym;
		}
	else return "[]";
}

string List :: value () const { 
	if (_elements.size()>0)
	{
		string retsym = "[";
		for (int i=0;i<_elements.size()-1;i++)
			retsym += _elements[i] -> value() + ", ";
			retsym += _elements [_elements.size()- 1] -> value() + "]"; 
		return retsym;
	}
	else return "[]";
}

bool List :: match ( Term & term ) {
	List * _ls=dynamic_cast < List * > (&term);
	Variable * _var = dynamic_cast < Variable * > ( & term );
	if(_ls){//cout << (*_ls).symbol() << endl;
	if (_elements.size() != _ls->getElelen()){
		return false;
	}
	else
	{
		for (int i=0;i< _elements.size()-1;i++ )
			_elements[i] -> match((_ls -> liarr(i)));
		return true;	
	}
	}
	if(_var)return _var->match(*_ls);//
	return false;
} 

int List :: getElelen() {return _elements.size();}

Term & List :: liarr (int n) {return *_elements[n];}

Term * List :: head () const { 
	if (_elements.size()>0)
		return _elements[0];
	else
		throw string ("Accessing head in an empty list");
}

List * List :: tail () const {
	if (_elements.size()>0)
	{
		vector < Term * > tail (_elements.begin()+1,_elements.end() );
		return new List (tail);
	}
	else
	{
		throw std :: string ("Accessing tail in an empty list");
	}
}


