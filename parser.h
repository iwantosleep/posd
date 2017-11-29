#ifndef PARSER_H
#define PARSER_H
#include <string>
using std::string;

#include "atom.h"
#include "variable.h"
#include "global.h"
#include "scanner.h"
#include "struct.h"
#include "list.h"
#include "utParser.h"
#include "node.h"

class Parser{
public:
  Parser(Scanner scanner) : _scanner(scanner), _terms(){}

  Term* createTerm(){
    int token = _scanner.nextToken();
    _currentToken = token;
    if(token == VAR){
      return new Variable(symtable[_scanner.tokenValue()].first);
    }else if(token == NUMBER){
      return new Number(_scanner.tokenValue());
    }else if(token == ATOM || token == ATOMSC){
      Atom* atom = new Atom(symtable[_scanner.tokenValue()].first);
      if(_scanner.currentChar() == '(' ) {
        return structure();
      }
      else
        return atom;
    }
    else if(token == '['){
      return list();
    }

    return nullptr;
  }



  Term * structure() {
    Atom structName = Atom(symtable[_scanner.tokenValue()].first);
    int startIndexOfStructArgs = _terms.size();
    _scanner.nextToken();
    createTerms();
    if(_currentToken == ')')
    {
      vector<Term *> args(_terms.begin() + startIndexOfStructArgs, _terms.end());
      _terms.erase(_terms.begin() + startIndexOfStructArgs, _terms.end());
      return new Struct(structName, args);
    } else {
      throw string("unexpected token");
    }
  }

  Term * list() {
    int startIndexOfListArgs = _terms.size();
    createTerms();
    if(_currentToken == ']')
    {
      vector<Term *> args(_terms.begin() + startIndexOfListArgs, _terms.end());
      _terms.erase(_terms.begin() + startIndexOfListArgs, _terms.end());
      return new List(args);
    } else {
      throw string("unexpected token");
    }
  }

  vector<Term *> & getTerms() {
    return _terms;
  }
  //find the node
  void matchings()
{
    Term* term = createTerm();
    if(term==nullptr);
    else//none null
    { 
      if(isCOMMA!=0){
        Term * getTerm  = find(term);
        if(getTerm  != nullptr){term->match(*getTerm);}
      }_terms.push_back(term);
      while((_currentToken = _scanner.nextToken()) == ',' ||  _currentToken=='='|| _currentToken == ';') {
        if (_currentToken == '=') {isCOMMA = 0;
          //NOT COMMA
          Node * left = new Node(TERM, _terms.back(), nullptr, nullptr);
          _terms.push_back(createTerm());          
          Node * right = new Node(TERM, _terms.back(), nullptr, nullptr);
          Node * root = new Node(EQUALITY, nullptr, left, right);
          _theTree = root;
        }
        else if(_currentToken == ','){
          isCOMMA = 1;
          Node * left = _theTree;
          matchings();
          Node * root = new Node(COMMA, nullptr, left, expressionTree());
          _theTree = root;
          
        }
        else if(_currentToken == ';'){//;'s tree
          isCOMMA = 0;
          Node * Sleft = _theTree;
          matchings();
          Node * Sroot = new Node(SEMICOLON, nullptr, Sleft, expressionTree());
          _theTree = Sroot;
        }
      }
    }
}

  Term * find(Term * term){
    for(int index = 0; index < _terms.size() ; index++){
      while(_terms[index]->symbol() == term->symbol()) 
      {
        return _terms[index];
      }
      Struct * s = dynamic_cast<Struct*>(_terms[index]);
      while(s) 
      {
        return Findstruct(s,term);
      }
    }
    return nullptr;
  }

  Term * Findstruct(Struct * s, Term * term){
    for(int i = 0; i < s->arity() ; i++){
      while(s->args(i)->symbol() == term->symbol()) return s->args(i);
      Struct * ss = dynamic_cast<Struct*>(s->args(i));
      while(ss) {
        return Findstruct(ss,term);
      }
    }
    return nullptr;
  }


  Node * expressionTree(){
    return _theTree;
  }

private:
  FRIEND_TEST(ParserTest, createArgs);
  FRIEND_TEST(ParserTest,ListOfTermsEmpty);
  FRIEND_TEST(ParserTest,listofTermsTwoNumber);
  FRIEND_TEST(ParserTest, createTerm_nestedStruct3);

  void createTerms() {
    Term* term = createTerm();
    if(term!=nullptr)
    {
      _terms.push_back(term);
      while((_currentToken = _scanner.nextToken()) == ',') {
        _terms.push_back(createTerm());
      }
    }
  }

  vector<Term *> _terms;
  Scanner _scanner;
  int _currentToken;
  Node * _theTree;
  int isCOMMA = 0;
};
#endif
