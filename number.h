#ifndef NUMBER_H
#define NUMBER_H

#include <string>
//////////////////////
#include "term.h"
//#include <sstream>
//using std::string;
using namespace std;
//string InttoString(double _INT);


class Variable;

class Number : public Term{
public :
	Number (double s);
	
	string _symbol;
	string  symbol() const;

	string value() const ;

	
private:

	string _value;
	bool _assignable = true;
	//bool _matchValue = true;
};
//##int -> string
	/*string InttoString(int _INT)
	{
		stringstream ss;
		string retTostring;
		ss << _INT;
		ss >> retTostring;
		return retTostring;
	}*/

#endif