#ifndef UTTERM_H
#define UTTERM_H
#include "number.h"
#include "atom.h"
#include "variable.h"

using namespace std;
//test Number.value()
TEST (Number,ctor) {
	Number num(10);
	//cout <<" This is TEST ONE : " << num.value() << endl;
	ASSERT_EQ("10", num.value());
}
//test Number.symbol()
TEST (Number, symbol) {
	Number num(123);
	//cout <<" This is TEST TWO : " << num.symbol() << endl;
	ASSERT_EQ("123",num.symbol());
}
//?- 25=25.
//true.
TEST (Number, matchSuccess) {
	Number num1(25);
	Number num2(25);
	/*cout <<" This is TEST THREE : " 
		 << "num1.value = " << num1.value()
		 << "  num2.value = " << num2.value()
		 << "  (T or F) = " << num1.match(jerry) 
		 << endl;*/
	ASSERT_TRUE(num1.match(num2));
}
//?- 25=0.
//false.
TEST (Number, matchFailureDiffValue) {
	Number num1(25);
	Number num2(0);
	/*cout <<" This is TEST FOUR : " 
		 << "num1.value = " << num1.value()
		 << "  num2.value = " << num2.value()
		 << "  (T or F) = " << num1.match(jerry) 
		 << endl;*/
	ASSERT_FALSE(num1.match(num2));	
}
//?- 25=tom.
//false.
TEST (Number, matchFailureDiffConstant) {
	Number num(25);
	Atom tom("tom");
	ASSERT_FALSE(num.match(tom));
}
//?- 25=X.
//true.
/*TEST (Number, matchSuccessToVar) {
	Number num(25);
	Variable X("X");
	EXPECT_TRUE(X.match(num));
}*/

//?- tom=25.
//false.
TEST (Atom, matchFailureDiffConstant) {
	Atom tom("tom");
	Number num(25);
	ASSERT_FALSE(num.match(tom));
}

// ?- tom = X.
// X = tom.
/*TEST (Atom, matchSuccessToVar) {
	Atom tom("tom");
	Variable X("X");
	//cout << "tom.match(X) = " << tom.match(X) <<endl;
	//ASSERT_EQ(tom,X);  
	EXPECT_TRUE(tom.match(X));
	//OK
}*/

// ?- X=tom, tom=X.
// X = tom.
TEST (Atom, matchSuccessToVarInstantedToDiffConstant) {
	Variable X("X");
	Atom tom("tom");
	ASSERT_TRUE(X.match(tom));
	ASSERT_TRUE(tom.match(X));
	//OK
}

// ?- X=jerry, tom=X.
// false.
/*TEST (Atom, matchFailureToVarInstantedToDiffConstant) {
	Variable X("X");
	Atom tom("tom");
	Atom jerry("jerry");
	EXPECT_TRUE(X.match(jerry));
	//cout << X.match(jerry) << tom.match(jerry);
	EXPECT_FALSE(tom.match(jerry));
	//OK
}*/

// ?- X = 5.
// X = 5.
TEST (Var, matchSuccessToNumber) {
	Variable X("X");
	Number num(5);
	ASSERT_TRUE(X.match(num));
	//OK
}

// ?- X=25, X= 100.
// false.
TEST (Var, matchFailureToTwoDiffNumbers) {
	Variable X("X");
	Number num1(25);
	Number num2(100);
	X.match(num1);
	//cout << X.match(num1) << X.match(num2);
	ASSERT_FALSE(X.match(num2));
	//OK
}

// ?- X=tom, X= 25.
// false.
//         Atom(V) Number(X)
TEST (Var, matchSuccessToAtomThenFailureToNumber) {
	Variable X("X");
	Atom tom("tom");
	Number num(25);
	X.match(tom);
	ASSERT_FALSE(X.match(num));
	//cout << X.match(tom) << X.match(num);
	//OK
}
//?- tom=X, 25=X.
//false.
TEST (Var, matchSuccessToAtomThenFailureToNumber2) {
	Atom tom("tom");
	Variable X("X");
	Number num(25);
	tom.match(X);
	ASSERT_FALSE(num.match(X));
}
//?- X=tom, X=tom.
//true.
TEST(Var, reAssignTheSameAtom){
	Variable X("X");
	Atom tom("tom");
	X.match(tom);
	ASSERT_TRUE(X.match(tom));
}
#endif
