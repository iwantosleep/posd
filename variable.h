#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "term.h"
#include <vector>
#include "struct.h"
//using std::string;
using namespace std;

class Atom;
class Number;

class Variable : public Term {
public:
  bool match(Term &term);
  Variable(string s);//:_symbol(s){}
  string  _symbol;
  string symbol() const;
  void getsymbol(string s);
  string value() const;//{ return _value; }
  void getvalue(string s);
  vector <Variable *> Varlis; 
  Struct *temp = 0;
  
  
private:
  string _value =_symbol;// <-will error about same symbol
  bool _Varflag = true;
  Term *_Vart={};
 
};

#endif
