#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <vector>
#include "term.h"
using std::string;

class Variable : public Term{
	public:
  		Variable ( string s );
		string value () const;
		bool match ( Term &term );
	private:
		string _value; 
		bool _assignable = true; 
		std :: vector < Variable * > _follow;
		Term * _save = 0;
};
#endif
