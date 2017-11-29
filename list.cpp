#include "list.h"
#include "term.h"
#include "number.h"
#include "variable.h"
#include <iostream>
#include <vector>


bool List::match(List &list)
  {

    if (this == &list)
    {
      return true;
    }
    else
    {
      if (this->size() == list.size())
      {
        for (int i = 0; i < list.size(); i++)
        {
          if (_elements[i]->isNumber == true && list._elements[i]->isVariable == true)
          {
            // list._elements[i]->_symbol =_elements[i]->symbol();
            return true;
          }
          else if (_elements[i]->match(*list._elements[i]) == false)
          {
            return false;
          }
        }
        return true;
      }
      else
      {
        return false;
      }
    }
  }
bool List::match(Variable &var)
  {
    for (int i = 0; i < this->size(); i++)
    {
      if (this->count(i).symbol() == var.symbol())
      {
        return false;
      }
    }

    if (!var._inst)
    {
      var._inst = this;
      return true;
    }
    return var._inst->match(*this);
  }