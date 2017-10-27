#ifndef LIST_H
#define LIST_H

#include "term.h"

#include <vector>
using std::vector;

class List : public Term {
	public:
		string symbol() const;
		string value() const;
		int getSize();
		Term & single ( int i );
		bool match(Term & term);
	public:
  		List ();
  		List (vector<Term *> const & elements);
  		Term * head() const;
  		List * tail() const;

	private:
  		vector<Term *> _elements;
};
#endif
