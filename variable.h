#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "term.h"
#include <vector>
//#include "struct.h"
//using std::string;
using namespace std;

class Variable : public Term{
	public:
		bool match ( Term &term );
  		Variable (string s);
		string value () const;
		vector <Variable *> _Varlis;//
	private:
		string _value; 
		bool _Varflag = true;
		Term * _Vart={};
};
#endif
