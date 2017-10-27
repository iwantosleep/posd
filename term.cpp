#include "term.h"

Term :: Term () : _symbol() {}

Term :: Term ( string s ) : _symbol ( s ) {}

string Term :: symbol () const { return _symbol; }

string Term :: value () const { return symbol(); }

bool Term :: match ( Term & term ) { return _symbol == term.symbol(); }
