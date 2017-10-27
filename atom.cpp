#include <string>
#include "number.h"
#include "atom.h"
#include "variable.h"
#include <sstream>
#include <iostream>
using namespace std;

Atom::Atom(string s):Term(s){}

/*
bool Atom:: match(Number num){
    if(value()!=num.value()){ return false;}
        return true;
}
bool Atom:: match(Atom atom){
    if(symbol()!=atom._symbol){ return false;}
        return true;
}
bool Atom :: match ( Variable &var ){
	return var.match(*this);
}
*/
