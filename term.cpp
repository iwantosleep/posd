#include "term.h"
#include "iterator.h"


Term::Term ():_symbol(""){}
Term::Term (string s):_symbol(s) {}
Term::Term(double db){
    std::ostringstream strs;
    strs << db;
    _symbol = strs.str();
  }
Iterator<Term*> * Term::createIterator()
{
  return new NullIterator<Term*>(this);
}
