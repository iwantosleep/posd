#include "struct.h"
#include "iterator.h"

Struct::Struct(Atom name, std::vector<Term *> args): _name(name) {
    _args = args;
  }  

bool Struct :: match(Term &term) {
        Struct * s = dynamic_cast<Struct *>(&term);
        if (s){
                if(_args.size()== s->_args.size())
                        return true;
                if (!_name.match(s->_name))
                        return false;           
                for(int i=0;i<_args.size();i++){
                        if(_args[i]->symbol() == s->_args[i]->symbol())
                                return true;
                        }return false;                        
                }
        return false;
}
Atom & Struct::name() {
    return _name;
  }

string Struct::symbol() const {
    if(_args.empty())
    return  _name.symbol() + "()";
    string ret = _name.symbol() + "(";
    std::vector<Term *>::const_iterator it = _args.begin();
    for (; it != _args.end()-1; ++it)
      ret += (*it)->symbol()+", ";
    ret  += (*it)->symbol()+")";
    return ret;
  }

string Struct::value() const {
    string ret = _name.symbol() + "(";
    std::vector<Term *>::const_iterator it = _args.begin();
    for (; it != _args.end()-1; ++it)
      ret += (*it)->value()+", ";
    ret  += (*it)->value()+")";
    return ret;
  }

Term * Struct::args(int index) {
    return _args[index];
  }

int Struct::arity() const {return _args.size();}




Iterator<Term*> * Struct :: createIterator()
{
  return new StructIterator<Term*>(this);
}

Iterator<Term*> * Struct :: createDFSIterator()
{
  return new DFSearchIterator<Term*>(this);
}

Iterator<Term*> * Struct :: createBFSIterator()
{
  return new BFSearchIterator<Term*>(this);
}

