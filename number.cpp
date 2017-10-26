#include "number.h"
#include <sstream>
#include <string> 
#include <iostream>

using namespace std;
string InttoString(double s)
{
    stringstream ss;
    string retTostring;
    ss << s;
    //ss >> retTostring;
    return ss.str();//retTostring;
}

Number :: Number(double s):Term (InttoString (s)){}
