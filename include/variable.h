#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>

//using std::string;
using namespace std;

class Atom;
class Number;

class Variable{
public:
  Variable(string s);//:_symbol(s){}
  string  _symbol;
  string symbol();
  string value();//{ return _value; }
  
  bool match( Atom atom );/*{
    bool ret = _assignable;
    if(_assignable){
      _value = atom._symbol ;
      _assignable = false;
    }
    return ret;
  }*/
	
  bool match( Number num );/*{
    bool ret = _assignable;
    if(_assignable){
      _value = num._symbol ;
      _assignable = false;
    }
    return ret;
  }*/
  bool match( Variable Var );
  
  bool assignable();
  void setAssignable (bool d);
  

private:
  string _value;
  bool _assignable = true;
};

#endif
