#include "number.h"
#include <sstream>

string doubleToString (double db) {
	std :: stringstream ss;
	ss << db;
	return ss.str();
}

Number :: Number ( double db ) : Term ( doubleToString ( db ) ) {}
