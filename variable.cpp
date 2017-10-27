#include "variable.h"
#include "struct.h"
#include "list.h"

Variable :: Variable ( string s ) : Term ( s ) , _value ( s ) {}

string Variable :: value () const { 
	if ( _save != 0)
		return _save ->value();
	else
		return _value;
}

bool Variable :: match ( Term &term ) {
	Variable * var = dynamic_cast < Variable * > ( &term );
	Struct * ss = dynamic_cast < Struct * > ( &term );
	List * ls = dynamic_cast < List * > ( &term );	

	if ( _symbol == term.symbol() ) 
		return true; 

	if ( _assignable || _value == term.symbol() ){
		if ( var ){// match is variable
			if ( var -> _assignable ){ // other is not match 
				_value = var -> value();
				( var -> _follow ).push_back ( this );
				_follow.push_back ( var );

				if ( _follow.size() ) { // exist each other follow this
					for (int i = 0 ; i < _follow.size()-1 ; i++)
						( var -> _follow ).push_back ( _follow[i] );
				}
				if ( ( var -> _follow ).size() ){ // exist each other follow var
					for (int i = 0 ; i < ( var -> _follow ).size()-1 ; i++)
						_follow.push_back ( ( var -> _follow )[i] );
				}	
			}
			else{// other is match
				_value = var -> value();
				_assignable = false;
			}
			return true;
		}
		// match not variable
		if ( ss ){
			_save = ss;
			return true; 
		}
		if ( ls ){
			for ( int i = 0 ; i < ( ls -> getElelen() ) ; i++ ) {
				if ( ( ls -> liarr(i) ).symbol() == _symbol) 
					return false;
			}
			_save = ls;
			return true;
		}
		_value = term.symbol();
		if ( _follow.size() ) {
			for (int i = 0 ; i < _follow.size()-1 ; i++)
				_follow[i] -> _value = term.symbol();
		}
		_assignable = false;	
		return true;
	}
	return false;
}
