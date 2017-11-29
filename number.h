#ifndef NUMBER_H
#define NUMBER_H

#include "variable.h"
#include <string>
#include <sstream>
using std::string;
class Number : public Term
{
public:
  Number(double db) : Term(db) {
    isNumber = true;
  }
 
  
  bool match(Term &a)
  {
    if (!a.isList)
    {
    return _symbol == a.symbol();
    }else{
    return false;      
    }
  }
  
};

#endif