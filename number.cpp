#include <string>
#include "number.h"
#include "atom.h"
#include "variable.h"
#include <sstream>
#include <iostream>
using namespace std;


string InttoString(double _INT);//副程式

Number::Number(double s):_symbol(InttoString(s)),_value(InttoString(s)){}

string Number:: symbol()const{return _symbol;}

string Number::  value()const{return _value;}


string InttoString(double _INT)
{
    stringstream ss;
    string retTostring;
    ss << _INT;
    ss >> retTostring;
    return retTostring;
}
