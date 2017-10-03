#include <string>
#include "include/number.h"
#include "include/atom.h"
#include "include/variable.h"
#include <sstream>
#include <iostream>
using namespace std;


string InttoString(int _INT);//副程式

Number::Number(int s):_symbol(InttoString(s)),_value(InttoString(s)){}

string Number:: symbol(){return _symbol;}

string Number::  value(){return _value;}

bool Number:: match(Number num){
    if(value()!=num.value()) return false;
    else
        return true;
}

bool Number:: match(Atom atom){
    if(symbol()!=atom._symbol) return false;
        else
            return true;
}

bool Number:: match(Variable var){
    if(symbol()!=var._symbol) return false;
        else
            return true;
}

string InttoString(int _INT)
{
    stringstream ss;
    string retTostring;
    ss << _INT;
    ss >> retTostring;
    return retTostring;
}
