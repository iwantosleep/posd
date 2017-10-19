#include <string>
#include "number.h"
#include "atom.h"
#include "variable.h"
#include <sstream>
#include <iostream>
using namespace std;


Variable::Variable(string s):_symbol(s){}

string Variable:: symbol()const {return _symbol;}

string Variable::  value()const {
    if(!_Varpt)return symbol();
    else return _Varpt -> value();
}



bool Variable::match(Term &term){
    if(&term!=this)
    {
        if(_Varpt)return _Varpt -> match(term);
        else{_Varpt =&term;return true;}
    }
    else 
        return true;
}

/*bool Variable::match(Term &term){
    if(&term == this)
    {
        return true;
    }
    else{
      if(!_Varpt){
        _Varpt = &term;
        return true;
      }
      else
        return _Varpt ->match(term);
    }
  }*/


/*
bool Variable :: assignable () { return _assignable; }
void Variable :: setAssignable ( bool d ) { _assignable = d; }
*/