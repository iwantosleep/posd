#ifndef UTTERM_H
#define UTTERM_H
#include "include/number.h"
#include "include/atom.h"
#include "include/variable.h"

using namespace std;
//test Number.value()
TEST (Number,ctor) {
	Number num(10);
	cout <<" This is TEST ONE : " << num.value() << endl;
	ASSERT_EQ("10", num.value());
}
//test Number.symbol()
TEST (Number, symbol) {
	Number num(123);
	cout <<" This is TEST TWO : " << num.symbol() << endl;
	ASSERT_EQ("123",num.symbol());
}
//?- 25=25.
//true.
TEST (Number, matchSuccess) {
	Number tom(25);
	Number jerry(25);
	cout <<" This is TEST THREE : " 
		 << "tom.value = " << tom.value()
		 << "  jerry.value = " << jerry.value()
		 << "  (T or F) = " << tom.match(jerry) 
		 << endl;
	ASSERT_TRUE(tom.match(jerry));
}
//?- 25=0.
//false.
TEST (Number, matchFailureDiffValue) {
	Number tom(25);
	Number jerry(0);
	cout <<" This is TEST FOUR : " 
		 << "tom.value = " << tom.value()
		 << "  jerry.value = " << jerry.value()
		 << "  (T or F) = " << tom.match(jerry) 
		 << endl;
	ASSERT_FALSE(tom.match(jerry));	
}
//?- 25=tom.
//false.
TEST (Number, matchFailureDiffConstant) {
	Number jerry(25);
	Atom tom("tom");
	ASSERT_FALSE(jerry.match(tom));
}
//?- 25=X.
//true.
TEST (Number, matchSuccessToVar) {
	Number num(25);
	Variable X("X");
	EXPECT_TRUE(X.match(num));
}

//?- tom=25.
//false.
TEST (Atom, matchFailureDiffConstant) {
	Atom jerry("jerry");
	Number tom(25);
	ASSERT_FALSE(tom.match(jerry));
}

// ?- tom = X.
// X = tom.
TEST (Atom, matchSuccessToVar) {
	Atom tom("tom");
	Variable X("X");
	cout << "tom.match(X) = " << tom.match(X) <<endl;
	//ASSERT_EQ(tom,X);   CCV
	//ASSERT_TRUE(tom.match(X));
}

// ?- X=tom, tom=X.
// X = tom.
TEST (Atom, matchSuccessToVarInstantedToDiffConstant) {
	Variable X("X");
	Atom tom("tom");
	
}

// ?- X=jerry, tom=X.
// false.
TEST (Atom, matchFailureToVarInstantedToDiffConstant) {

}

// ?- X = 5.
// X = 5.
TEST (Var, matchSuccessToNumber) {
	Number X(5);
	ASSERT_EQ("5",X.value());
}

// ?- X=25, X= 100.
// false.
TEST (Var, matchFailureToTwoDiffNumbers) {

}

// ?- X=tom, X= 25.
// false.
//         Atom(V) Number(X)
TEST (Var, matchSuccessToAtomThenFailureToNumber) {

}
//?- tom=X, 25=X.
//false.
TEST (Var, matchSuccessToAtomThenFailureToNumber2) {

}
//?- X=tom, X=tom.
//true.
TEST(Var, reAssignTheSameAtom){

}
#endif
