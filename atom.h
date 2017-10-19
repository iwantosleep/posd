#ifndef ATOM_H
#define ATOM_H

#include <string>
#include "term.h"
//
//using std::string;
using namespace std;

class Number;
class Variable;

class Atom : public Term{

  public:
  Atom (string s);
  string _symbol;
	string symbol() const;
	string value() const;
	
	/*bool match(Number num);
	bool match(Atom atom);
	bool match(Variable &var);*/

  private:
	string _value;
	bool _assignable = true;
//////////////////////
};
#endif
