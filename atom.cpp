#include <string>
#include "number.h"
#include "atom.h"
#include "variable.h"
#include <sstream>
#include <iostream>
using namespace std;



Atom::Atom(string s):_symbol(s){}

string Atom:: symbol(){return _symbol;}

string Atom::  value(){return _symbol;}

bool Atom:: match(Number num){
    if(value()!=num.value()){ return false;}
        return true;
}

bool Atom:: match(Atom atom){
    if(symbol()!=atom._symbol){ return false;}
        return true;
}

/*bool Atom:: match(Variable var){
    if(symbol()!=var._symbol) return false;
        else
            return true;
}*/
bool Atom :: match ( Variable var ){
	if ( _assignable || _value == var.symbol() ){
		_value = var.symbol();
		_assignable = false;
		return true;
	}
	return false;
}


