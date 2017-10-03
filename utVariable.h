#ifndef UTVARIABLE_H
#define UTVARIABLE_H
#include "include/variable.h"


TEST(Variable, constructor){
  Variable X("X");
  ASSERT_EQ("X", X._symbol);

}

TEST(Variable , matching){
  Atom tom("tom");
  Variable X("X");
  X.match(tom);
  ASSERT_EQ( "tom", X.value());
}
TEST (Variable , haveValue){
  Atom tom ("tom");
  Atom jerry ("jerry");
  Variable X("X");
	cout << "============================\n";
	cout << X.match(tom) << "   " << X.match(jerry);
  ASSERT_TRUE(X.match(tom));
  ASSERT_FALSE(X.match(jerry));
}

#endif
