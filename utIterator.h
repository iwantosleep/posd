#ifndef UTITERATOR_H
#define UTITERATOR_H

#include "struct.h"
#include "variable.h"
#include "atom.h"
#include "list.h"
#include "iterator.h"
#include "number.h"
#include "term.h"

TEST(iterator, first) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    Struct s(Atom("s"), { &one, &t, &Y });
    Iterator<Term*> *itStruct = s.createIterator();
    itStruct->first();
    EXPECT_EQ("1", itStruct->currentItem()->symbol());
    EXPECT_FALSE(itStruct->isDone());
    itStruct->next();
    EXPECT_EQ("t(X, 2)", itStruct->currentItem()->symbol());
    EXPECT_FALSE(itStruct->isDone());
    itStruct->next();
    EXPECT_EQ("Y", itStruct->currentItem()->symbol());
    itStruct->next();
    EXPECT_TRUE(itStruct->isDone());
}

TEST(iterator, nested_iterator) {
  Number one(1);
  Variable X("X");
  Variable Y("Y");
  Number two(2);
  Struct t(Atom("t"), { &X, &two });
  Struct s(Atom("s"), { &one, &t, &Y });
  StructIterator<Term*> it(&s);
  it.first();
  it.next();
  Struct *s2 = dynamic_cast<Struct *>(it.currentItem());

  StructIterator<Term*> it2(s2);
  it2.first();
  EXPECT_EQ("X", it2.currentItem()->symbol());
  EXPECT_FALSE(it2.isDone());
  it2.next();
  EXPECT_EQ("2", it2.currentItem()->symbol());
  EXPECT_FALSE(it2.isDone());
  it2.next();
  EXPECT_TRUE(it2.isDone());
}

TEST(iterator, firstList) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    List l({ &one, &t, &Y });
    ListIterator<Term*> it(&l);
    Iterator<Term*>* itList = &it;
    itList->first();
    EXPECT_EQ("1", itList->currentItem()->symbol());
    EXPECT_FALSE(itList->isDone());
    itList->next();
    EXPECT_EQ("t(X, 2)", itList->currentItem()->symbol());
    EXPECT_FALSE(itList->isDone());
    itList->next();
    EXPECT_EQ("Y", itList->currentItem()->symbol());
    itList->next();
    EXPECT_TRUE(itList->isDone());
}

TEST(iterator, NullIterator){
  Number one(1);
  NullIterator<Term*> nullIterator(&one);
  nullIterator.first();
  EXPECT_TRUE(nullIterator.isDone());
  Iterator<Term*> * it = one.createIterator();
  it->first();
  EXPECT_TRUE(it->isDone());
}

//1
TEST(iterator, DFSTreeListEmpty){
	vector<Term*> v = {};
	List t(v);
	Iterator<Term*> *it = t.createDFSIterator();
	it->first();
	ASSERT_TRUE(it->isDone());
}
//2
TEST(iterator, DFSTreeStructEmpty){
	vector<Term*> v = {};
	Struct t(Atom("t"), v);
	Iterator<Term*> *it = t.createDFSIterator();
	it->first();
	ASSERT_TRUE(it->isDone());
}
//3
TEST(iterator, DFSTreeStructFirst) {// s(1, Y, t(X, 1))
  Number num1(1);
  Variable Y("Y");
  Variable X("X");
  Number num2(1);
  Struct t(Atom("t"), { &X, &num2 });
  Struct s(Atom("s"), { &num1, &Y, &t });
  Iterator<Term*> *it = s.createDFSIterator();
  it->first();
  EXPECT_EQ("1", it->currentItem()->symbol());
  it->next();
  EXPECT_EQ("Y", it->currentItem()->symbol());
  it->next();
  EXPECT_EQ("t(X, 1)", it->currentItem()->symbol());
  it->next();
  EXPECT_EQ("X", it->currentItem()->symbol());
  it->next();
  EXPECT_EQ("1", it->currentItem()->symbol());
  EXPECT_TRUE(it->isDone());
}

//4
TEST(iterator, DFSTreeListFirst) { 
//[[1, X, 3], Y, 2]
// [1, X, 3] -> 1, X, 3 -> Y -> 2
  Number num1(1);
  Number num2(2);
  Number num3(3);
  Variable X("X");
  Variable Y("Y");
  List l1({&num1,&X,&num3});
  List l2({&l1,&Y,&num2});
  Iterator<Term*> *it = l2.createDFSIterator();
  it->first();
  EXPECT_EQ("[1, X, 3]", it->currentItem()->symbol());
  it->next();
  EXPECT_EQ("1", it->currentItem()->symbol());
  it->next();
  EXPECT_EQ("X", it->currentItem()->symbol());
  it->next();
  EXPECT_EQ("3", it->currentItem()->symbol());
  it->next();
  EXPECT_EQ("Y", it->currentItem()->symbol());
  it->next();
  EXPECT_EQ("2", it->currentItem()->symbol());
  EXPECT_TRUE(it->isDone());
}
#endif
