#ifndef NODE_H
#define NODE_H

#include "variable.h"

enum Operators {SEMICOLON, COMMA, EQUALITY, TERM};

class Node {
public:
  Node(Operators op):payload(op), term(0), left(0), right(0) {}
  Node(Operators op, Term *t, Node *l, Node *r):payload(op), term(t), left(l), right(r) {}

  bool evaluate() {
    if(payload == Operators::EQUALITY){
      return left->term->match(*(right->term));
    }
    else if(payload == Operators::COMMA){
      bool l = left->evaluate();
      bool r = right->evaluate();
      return l||r;
    }
    else if(payload == Operators::SEMICOLON){
      bool l = left->evaluate();
      bool r = right->evaluate();
          return true;
    }
  }

  Operators payload;
  Term * term;
  Node * left;
  Node * right;
};

#endif
