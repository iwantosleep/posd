#include <iostream>
#include "parser.h"
using namespace std;

int main(int argc, char **argv)
{
  string input, context = "";
  Parser * p;
  while(true){
    do{
        if(context == "")
            cout << "?- ";
        else cout << "|  ";
        getline(cin, input);
        if(input != ""){
        while(input[0] == ' '){
            input = input.substr(1, input.size() - 1);
        }
        context += input;
        }
    }while(input == "" || context.back() != '.');
    if(context == "halt.") break;
    p = new Parser(Scanner(context));
    //cout << p->buildExpression()->evaluate() << endl;
    cout << p->buildExpression()->getResult() << endl;
    //cout << p->buildExpression()->getResult() << endl;
    context = "";
  };
}