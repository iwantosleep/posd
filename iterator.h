#ifndef ITERATOR_H
#define ITERATOR_H

#include "struct.h"
#include "list.h"
#include <queue>

template <class T>
class Iterator {
public:
  virtual void first() = 0;
  virtual void next() = 0;
  virtual T currentItem() const = 0;
  virtual bool isDone() const = 0;
};

template <class T>
class NullIterator :public Iterator<T>{
public:
  NullIterator(T n){}
  void first(){}
  void next(){}
  T currentItem() const{
      return nullptr;
  }
  bool isDone() const{
    return true;
  }
};

template <class T>
class StructIterator :public Iterator<T> {
public:
  friend class Struct;
  void first() {
    _index = 0;
  }
  Term* currentItem() const {
    return _s->args(_index);
  }
  bool isDone() const {
    return _index >= _s->arity();
  }
  void next() {
    _index++;
  }
   StructIterator(Struct *s): _index(0), _s(s) {}
private:
  int _index;
  Struct* _s;
};

template <class T>
class ListIterator :public Iterator<T> {
public:
  ListIterator(List *list): _index(0), _list(list) {}
  void first() {
    _index = 0;
  }
  Term* currentItem() const {
    return _list->args(_index);
  }
  bool isDone() const {
    return _index >= _list->arity();
  }
  void next() {
    _index++;
  }
private:
  int _index;
  List* _list;
};


//BFSiterator
template <class T>
class BFSearchIterator :public Iterator<T> {
public:
  BFSearchIterator(Term* term): _term(term){}
  void first() {
    _index = 1;
    _element.clear();//container clear
    STranversal(_term);
  }
  Term * currentItem() const {
    return _element[_index];
  }
  void STranversal(Term* term) 
  {
    Term * pmt; 
    queue<Term*> que;
    que.push(_term);
    while(!que.empty()) 
    {
      pmt = que.front();
      que.pop();
      _element.push_back(pmt);
      Struct *dst = dynamic_cast<Struct *>(pmt);
      List *dlst = dynamic_cast<List *>(pmt);
      if (dst)
      {
      int count=dst->arity(),j=0;
        while(count)
        {
          que.push(dst->args(j));
          count--;
            j++;
        }
      }        
      if (dlst) 
      {
      int count=dlst->arity(),j=0;
        while(count)
        {
          que.push(dlst->args(j));
          count--;
            j++;
        }
      } 
    }
  } 
  void next() {
    _index++;
  }
  bool isDone() const {
    return _index >= _element.size() - 1;
  }  
private:
  int _index;
  Term* _term;
  vector<T> _element;
};


//DFSiterator
template <class T>
class DFSearchIterator :public Iterator<T> {
public:
  DFSearchIterator(Term* term): _term(term) { }
    
  void first() {
    _index = 1;
    DTranversal(_term);
  }
  Term* currentItem() const {
    return _elements[_index];
  }
  void DTranversal(Term* term) 
  {
    _elements.push_back(term);
    Struct *dst = dynamic_cast<Struct*>(term);
    List *dlst = dynamic_cast<List*>(term);
    if(!dlst)
    {;;}
    else
    {
      int count=dlst->arity(),j=0;
      while(count)
      {
	      DTranversal(dlst->args(j)); 
	      count--;
        j++;
      }
    }
    if (!dst)
    {;;}
    else
    {
      int count=dst->arity(),j=0;
      while(count)
      {
	      DTranversal(dst->args(j));
	      count--;
        j++;
      }
    }  
  }
  bool isDone() const {
    return _index >= _elements.size()-1;
  }
  void next() {
    _index++;
  }
private:
  int _index=0;
  int flag;
  Term* _term;
  vector<T> _elements;
};



#endif
