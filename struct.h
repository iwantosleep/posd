#ifndef STRUCT_H
#define STRUCT_H

#include "atom.h"
#include <vector>
#include <string>
#include "term.h"

using std::string;

template <class T>
class Iterator;

class Struct: public Term {
public:
  
  Struct(Atom name, std::vector<Term *> args);
  bool match( Term &term );  

  Term * args(int index) ;

  Atom & name();
  string symbol() const ;
  string value() const;
  int arity() const;

  Iterator<Term*> * createIterator();
  Iterator<Term*> * createDFSIterator();
  Iterator<Term*> * createBFSIterator();
private:
  Atom _name;
  std::vector<Term *> _args;
};

#endif
