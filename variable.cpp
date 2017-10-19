#include <string>
#include "number.h"
#include "atom.h"
#include "variable.h"
#include <sstream>
#include <iostream>
using namespace std;


Variable::Variable(string s):_symbol(s){}

string Variable:: symbol() const {return _symbol;}

void Variable:: getsymbol(string s)
{
    _symbol=s;
}
/*string Variable::  value() const {
    if(!_Vart)return symbol();
    else return _Vart -> value();
}*///test
string Variable :: value () const { 
	if ( temp != 0)
		return temp ->value();
	else
		return _value;
}
void Variable:: getvalue(string s)
{
    _value=s;
} 
/*
bool Variable::match(Term &term){
//not good match
}*/

bool Variable :: match ( Term &term ) {
	Variable * _var = dynamic_cast < Variable * > ( &term );
	Struct * _str = dynamic_cast < Struct * > ( &term );
	
    // cout << "term.symbol()" << term.symbol() << endl;k
    if (_symbol!=term.symbol())cout <<"";
	else return true; 

	if ( _Varflag || _value == term.symbol() ){
		if (_var!=NULL){//compare Var
			if(_var->_Varflag){ //have no match now
				_value = _var ->value();
                (_var->Varlis).push_back (this);
                Varlis.push_back (_var);
                 // cout << "_value" << _value << endl;k
				if (Varlis.size()>0) { 
                    //
                    int i=Varlis.size()-1;
                    int count=0;
                    while(i)
                    {
                        (_var->Varlis).push_back (Varlis[count]);
                        count++;
                        i--;
                    }//
				}
				if (Varlis.size()>0){ 
                    //
                    int i=Varlis.size()-1;
                    while(i)
                    {
                        int count=0;
                        Varlis.push_back(Varlis[count]);
                        count++;
                        i--;
                    }//
				}	
			}
			else{//match over
				_value=_var->value();
				_Varflag=false;
			}
			return true;
		}
		if(_str>0){
			temp=_str;//30
			return true; 
		}
        //need match sbol
        // cout << "term.symbol()" << term.symbol() << endl;
        // cout << "term.value()" << term.value() << endl;
		_value = term.symbol();
        
		if ( Varlis.size()>0) {
            //
            int i=Varlis.size();
            int count=0;
                    while(i)
                    {
                        Varlis[count] -> _value = term.symbol();
                        count++;
                        i--;

                    }//
		}	
        _Varflag = false;//flg0
		return true;//cout << "value()" << value()<<endl;
	}
	return false;
}
/*
bool Variable :: _Varflag () { return _Varflag; }
void Variable :: set_Varflag ( bool d ) { _Varflag = d; }??
*/