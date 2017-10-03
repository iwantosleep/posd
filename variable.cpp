#include <string>
#include "include/number.h"
#include "include/atom.h"
#include "include/variable.h"
#include <sstream>
#include <iostream>
using namespace std;


Variable::Variable(string s):_symbol(s){}

string Variable:: symbol(){return _symbol;}

string Variable::  value(){return _value;}

/*bool Variable:: match(Number num){
    if(value()!=num.value()) return false;
    else
        return true;
}*/
bool Variable :: match ( Number num ){
	if ( _assignable || ( _value == num.symbol() ) ){
		_value = num.symbol();
		_assignable = false;	
		return true;
	}
	return false;
}

/*bool Variable:: match(Atom atom){
    if(symbol()!=atom._symbol) return false;
        else
            return true;
}*/
bool Variable :: match ( Atom atom ){
	if ( _assignable || ( _value == atom.symbol() ) ){
		_value = atom.symbol();
		_assignable = false;	
		return true;
	}
	return false;
}

bool Variable:: match(Variable var){
    if(symbol()!=var._symbol) return false;
        else
            return true;
}

bool Variable :: assignable () { return _assignable; }
void Variable :: setAssignable ( bool d ) { _assignable = d; }
