#ifndef NUMBER_H
#define NUMBER_H

#include <string>
//////////////////////

//#include <sstream>
//using std::string;
using namespace std;
string InttoString(int _INT);

class Atom;
class Variable;

class Number{
public :
	Number (int s);//:_symbol(InttoString(s)),_value(InttoString(s)){}
	
	string _symbol;
	string symbol();//{return _symbol;}
	
	/*string setValue(string s){ 
		_value = s;
		}*/
	string  value();//{return _value;}
	
	
	/*bool match(){
	return ;
	}*/

	//VALUE'S MATCH
	bool match(Number num);/*{
		if(value()!=num.value()) return false;
		else
			return true;
	}*/
	

	//atom SYMBOL  MATCH
	//here use _matchValue replace "matchSymbol"
	bool match(Atom atom);/*{
		if(symbol()!=atom._symbol) return false;
			else
				return true;
	}*/
	

	bool match(Variable &var);/*{
		if(symbol()!=var._symbol) return false;
			else
				return true;
	}*/
	
	
	/*bool match( Atom atom ){
     bool ret = _assignable;
     if(_assignable){
       _value = atom._symbol ;
       _assignable = false;
     }
    return ret;
  }*/
	 
	
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