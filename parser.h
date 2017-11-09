#ifndef PARSER_H
#define PARSER_H
#include <string>
using std::string;

#include "atom.h"
#include "variable.h"
#include "global.h"
#include "scanner.h"
#include "struct.h"
#include "number.h"
#include "list.h"
class Parser{
public:
  Parser(Scanner scanner) : _scanner(scanner){}
  Term* createTerm(){
    int token = _scanner.nextToken();
    if(token == VAR)
    {
      return new Variable(symtable[_scanner.tokenValue()].first);
    }
    else if(token == NUMBER)
    {
      return new Number(_scanner.tokenValue());
    }
    else if(token == ATOM)
    {
        Atom* atom = new Atom(symtable[_scanner.tokenValue()].first);
        if(_scanner.currentChar() == '(' ) 
        {
          _scanner.nextToken() ;
          vector<Term*> terms = {};
		   if(_scanner.currentChar() == ')'){
            _scanner.nextToken();
            return new Struct(*atom, terms);
          }	
		  terms = getArgs();
          if(_currentToken == ')')
            return new Struct(*atom, terms);
        }
        else
          return atom;
    }
    ///
    else if(token == ATOMSC)//ATOMSC
    {
        Atom* atom = new Atom(symtable[_scanner.tokenValue()].first);
        if(_scanner.currentChar() != '(' )return atom; 
        else
          {
          _scanner.nextToken() ;
          vector<Term*> terms ={};
		   if(_scanner.currentChar() == ')'){
            _scanner.nextToken();
            return new Struct(*atom, terms);
          }	
		  terms = getArgs();
          if(_currentToken == ')')
            return new Struct(*atom, terms);
        }
    }
    ////add like ATOM
	else if ( token == '[' ){
		if ( _scanner.currentChar() != ']');
		else{
			_scanner.nextToken();
			return new List ();
		}	
		vector < Term * > terms = getArgs();
		if ( _currentToken != ')' )
			return new List ( terms );
		else 
			throw string ( "unexpected token" );
	}
	/////////////
    return nullptr;
  }

  vector<Term*> getArgs()
  {
    Term* term = createTerm();
    vector<Term*> args;
    if(term)
      args.push_back(term);
    while((_currentToken = _scanner.nextToken()) == ',') {
      args.push_back(createTerm());
    }
    return args;
  }



private:
  Scanner _scanner;
  int _currentToken;
};
#endif