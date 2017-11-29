#include "term.h"
#include "atom.h"
#include "variable.h"
#include <string>
#include <sstream>
#include <iostream>
#include <typeinfo>
bool Term::match(Term &a){
    return _symbol == a.symbol();
  }

