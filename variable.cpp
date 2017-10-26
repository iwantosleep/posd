#include "variable.h"
#include "struct.h"
#include "list.h"
#include <iostream>
using namespace std;

Variable :: Variable ( string s ) : Term ( s ) , _value ( s ) {}

string Variable :: value () const { 
	if (_Vart!= 0)
		return _Vart ->value();
	else
		return _value;
}

bool Variable :: match ( Term &term ) {
	Variable * _var = dynamic_cast < Variable * > ( &term );
	Struct * _str = dynamic_cast < Struct * > ( &term );
	List * _ls = dynamic_cast < List * > ( &term );	

	if (_symbol!=term.symbol())cout <<"";
		else return true; 

	if ( _Varflag || _value == term.symbol() ){
		if (_var!=NULL){//compare Var
			if(_var->_Varflag){ //have no match now
				_value = _var ->value();
                (_var->_Varlis).push_back (this);
                _Varlis.push_back (_var);

				if (_Varlis.size()>0) { 
                    //
                    int i=_Varlis.size()-1;
                    int count=0;
                    while(i)
                    {
                        (_var->_Varlis).push_back (_Varlis[count]);
                        count++;
                        i--;
                    }//
				}
				if (_Varlis.size()>0){ 
                    //
                    int i=_Varlis.size()-1;
                    while(i)
                    {
                        int count=0;
                        _Varlis.push_back(_Varlis[count]);
                        count++;
                        i--;
                    }//
				}
			}
			else{//match over
				_value = _var -> value();
				_Varflag = false;
			}
			return true;
		}
		if (_str>0){
			_Vart = _str;
			return true; 
		}
		if (_ls>0){
			for ( int i = 0 ; i < ( _ls -> getElelen() ) ; i++ ) {
				if ( ( _ls -> liarr(i) ).symbol() == _symbol) 
					return false;
			}
			_Vart = _ls;
			return true;
		}
		_value = term.symbol();
		if ( _Varlis.size()>0) {
            //
            int i=_Varlis.size();
            int count=0;
                    while(i)
                    {
                        _Varlis[count] -> _value = term.symbol();
                        count++;
                        i--;
                    }//
		}	
		_Varflag = false;	
		return true;
	}
	return false;
}
