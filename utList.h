#ifndef UTLIST_H
#define UTLIST_H

#include <string>
//using std::string;

#include "list.h"
#include "struct.h"
#include "atom.h"
#include "number.h"
#include "variable.h"
using namespace std;
// When create a new list without any item
// Then #symbol() of the list should return "[]"
TEST ( List , constructor ) {
  	List list;
	EXPECT_EQ ( "[]" , list.symbol() );
}

// Given there are two perfect numbers: 8128, 496
// When create a new list with the perfect Number
// Then #symbol() of the list should return "[8128]"
TEST ( List , Numbers ) {
	Number n1(8128),n2(496);
  	List list(vector<Term *>{&n1, &n2});
	EXPECT_EQ ( "[8128, 496]" , list.symbol() );
}

// Given there are two atoms: "terence_tao", "alan_mathison_turing"
// When create a new list with the Atoms
// Then #symbol() of the list should return "[terence_tao, alan_mathison_turing]"
TEST ( List , Atoms ) {
	Atom a1 ("terence_tao"),a2("alan_mathison_turing");
	List list(vector<Term *>{&a1, &a2});
	EXPECT_EQ ( "[terence_tao, alan_mathison_turing]" , list.symbol() );
}

// Given there are two variables: X, Y
// When create a new list with the variables
// Then #symbol() of the list should return "[X, Y]"
TEST ( List , Vars ) {
	Variable X ( "X" ) , Y ( "Y" );
	List list(vector<Term *>{&X, &Y});
	EXPECT_EQ ( "[X, Y]" , list.symbol() );
}

// ?- tom = [496, X, terence_tao].
// false.
TEST ( List , matchToAtomShouldFail ) {
	Atom a1 ( "tom" ) ,a2 ( "terence_tao" );
	Number num ( 496 );
	Variable X ( "X" );
	List list(vector<Term *>{&num, &X, &a2});
	EXPECT_FALSE (a1.match(list));	
}

// ?- 8128 = [496, X, terence_tao].
// false.
TEST ( List , matchToNumberShouldFail ) {
	Number num1 ( 8128 ) , num2 ( 496 );
	Variable X( "X" );
	Atom a ( "terence_tao" );
	List list(vector<Term *>{&num1, &X, &a});
	EXPECT_FALSE (num1.match (list));
}

// ?- s(X) = [496, X, terence_tao].
// false.
TEST ( List , matchToStructShouldFail ) {
	Variable X ( "X" );
	std :: vector < Term * > v = { &X };
	Struct hobby ( Atom ( "s" ) , v );
	Number num ( 496 );
	Atom a ( "terence_tao" );
	List list(vector<Term *>{&num, &X, &a});
	EXPECT_FALSE ( hobby.match (list) );
}

// ?- Y = [496, X, terence_tao].
// Y = [496, X, terence_tao].
TEST ( List , matchToVarShouldSucceed ) {
	Variable Y("Y"), X("X");
	Number num(496);
	Atom a( "terence_tao" );
	List list(vector<Term *>{&num, &X, &a});
	EXPECT_TRUE (Y.match (list));
}

// ?- X = [496, X, terence_tao].
// false.
TEST ( List , matchToVarOccuredInListShouldFail ) {
	Variable X ( "X" );
	Number num ( 496 );
	Atom a ( "terence_tao" );
	List list(vector<Term *>{&num, &X, &a});
	EXPECT_FALSE (X.match (list));
}

// ?- [496, X, terence_tao] = [496, X, terence_tao].
// true.
TEST ( List , matchToSameListShouldSucceed ) {
	Variable X ( "X" );
	Number num ( 496 );
	Atom a ( "terence_tao" );
	vector < Term * > args = {&num,&X,&a};
  	List list1 (args);
	List list2 (args);
	EXPECT_TRUE (list1.match(list2));
}

// ?- [496, X, terence_tao] = [496, Y, terence_tao].
// true.
TEST ( List , matchToSameListWithDiffVarNameShouldSucceed ) {
	Atom a ("terence_tao");
	Variable X ("X") , Y ("Y");
	Number num (496);
	vector < Term * > args1 = { &num , &X , &a };
	vector < Term * > args2 = { &num , &Y , &a };
  	List list1 (args1);
	List list2 (args2);
	EXPECT_TRUE (list1.match(list2));	
}

// ?- [496, X, terence_tao] = [496, 8128, terence_tao].
// X = 8128.
TEST ( List , matchToVarToAtominListShouldSucceed ) {
	Variable X ("X");
	Number n1 (496) , n2 (8128);
	Atom a ("terence_tao");
	vector < Term * > args1 = { &n1 , &X , &a };
	vector < Term * > args2 = { &n1 , &n2 , &a };
  	List list1 (args1);
	List list2 (args2);
	list1.match (list2);
	EXPECT_EQ ("8128" , X.value());	
}

// ?- Y = [496, X, terence_tao], X = alan_mathison_turing.
// Y = [496, alan_mathison_turing, terence_tao],
// X = alan_mathison_turing.
TEST ( List , matchVarinListToAtomShouldSucceed ) {
	Variable X ( "X" ) , Y ( "Y" );
	Number n ( 496 );
	Atom a1 ( "terence_tao" ) , a2 ( "alan_mathison_turing" );
	vector < Term * > args = { &n , &X , &a1 };
  	List list ( args );
	Y.match (list);
	X.match (a2);
	EXPECT_EQ ( "[496, alan_mathison_turing, terence_tao]" , Y.value() );	
	EXPECT_EQ ( "alan_mathison_turing" , X.value() );
}

// Example: 
// ?- [first, second, third] = [H|T].
// H = first, T = [second, third].
TEST ( List, headAndTailMatching1 ) {
	Atom f ( "first" ) , s ( "second" ) , t ( "third" );
  	List list(vector<Term *>{&f, &s, &t});
	EXPECT_EQ ( string ( "first" ) , list.head() -> value() );
  	EXPECT_EQ ( string ( "[second, third]" ) , list.tail() -> value() );
}

// Example:
// ?- [first, second, third] = [first, H|T].
// H = second, T = [third].
TEST ( List , headAndTailMatching2 ) {
	Atom f ( "first" ) , s ( "second" ) , t ( "third" );
  	List list(vector<Term *>{&f, &s, &t});
  	EXPECT_EQ ( string("second") , list.tail() -> head() -> value() );
  	EXPECT_EQ ( string("[third]") , list.tail() -> tail() -> value() );
}

// ?- [[first], second, third] = [H|T].
// H = [first], T = [second, third].
TEST ( List , headAndTailMatching3 ) {
	Atom f ( "[first]" ) , s ( "second" ) , t ( "third" );
  	List list(vector<Term *>{&f, &s, &t});
  	EXPECT_EQ ( string("[first]") , list.head() -> value() );
  	EXPECT_EQ ( string("[second, third]") , list.tail() -> value() );
}

// ?- [first, second, third] = [first, second, H|T].
// H = third, T = [].
TEST ( List , headAndTailMatching4 ) {
	Atom f ( "first" ) , s ( "second" ) , t ( "third" );
  	List list(vector<Term *>{&f, &s, &t});
  	EXPECT_EQ ( string("third") , list.tail() -> tail() -> head() -> value() );
  	EXPECT_EQ ( string("[]") , list.tail() -> tail() -> tail() -> value() );
}
 
// Given there is a empty list
// When client still want to get the head of list
// Then it should throw a string: "Accessing head in an empty list" as an exception.
TEST ( List , emptyExecptionOfHead ) {
  	List l;
	try {
		l.head();
	}catch (string s){
  		EXPECT_EQ ( "Accessing head in an empty list" , s);
	}
}

// Given there is a empty list
// When client still want to get the tail of list
// Then it should throw a string: "Accessing tail in an empty list" as an exception.
TEST ( List , emptyExecptionOfTail ) {
	List l;
	try {
		l.tail();
	}catch (string s){
  		EXPECT_EQ ( "Accessing tail in an empty list" , s);
	}
}
#endif
