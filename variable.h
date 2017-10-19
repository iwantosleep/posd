#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "term.h"
//using std::string;
using namespace std;

class Atom;
class Number;

class Variable : public Term {
public:
  Variable(string s);//:_symbol(s){}
  string  _symbol;
  string symbol() const;
  string value() const;//{ return _value; }
  
bool match(Term &term);

private:
  string _value;
  bool _assignable = true;
  Term *_Varpt=NULL;
};

#endif
