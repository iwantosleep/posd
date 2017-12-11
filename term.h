#ifndef TERM_H
#define TERM_H
#include <string>
#include <sstream>
using namespace std;

template <class T>
class Iterator;

class Term{
public:
  virtual string symbol() const {return _symbol;}
  virtual string value() const {return symbol();}
  virtual bool match(Term & a);
  virtual Iterator<Term*> * createIterator();
protected:
  Term ();
  Term (string s);
  Term(double db);
  string _symbol;
};
#endif
