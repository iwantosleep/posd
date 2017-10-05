#ifndef ATOM_H
#define ATOM_H

#include <string>

//
//using std::string;
using namespace std;

class Number;
class Variable;

class Atom {
public:
  Atom (string s);
  bool operator ==(Atom a) {return _symbol == a._symbol;}
  string _symbol;
//////////////////////////////////////////////////
	
	string symbol();//{return _symbol;}
	string  value();//{return _value;}
	
	bool match(Number num);/*{
		//if(value()!=num.value()) return false;
		if(symbol()!=num.symbol()) return false;
		else
			return true;
	}*/
	
	//atom SYMBOL  MATCH
	//here use _matchValue replace "matchSymbol"
	bool match(Atom atom);/*{
		if(symbol()!=atom._symbol) return false;
			else
				return true;
	}*/

	bool match(Variable &var);
	bool assignable();
	void setAssignable (bool d);
private:

	string _value;
	bool _assignable = true;
//////////////////////
};
#endif
