#pragma once

#include "Token.h"
#include <math.h>

class Operator : public Token
{
public:
  Operator(std::string s) : Token(Type::OPERATOR, s)
  {
    if (s.compare("+") == 0)
    {
      _precedence = 2;
      _associativity = Associativity::LEFT;
    }
    else if (s.compare("-") == 0)
    {
      _precedence = 2;
      _associativity = Associativity::LEFT;
    }
    else if (s.compare("*") == 0)
    {
      _precedence = 3;
      _associativity = Associativity::LEFT;
    }
    else if (s.compare("/") == 0)
    {
      _precedence = 3;
      _associativity = Associativity::LEFT;
    }
    else if (s.compare("^") == 0)
    {
      _precedence = 4;
      _associativity = Associativity::RIGHT;
    }
    else
    {
      _precedence = -1;
      _associativity = Associativity::UNKNOWN;
    }
  }

  Associativity associativity() { return _associativity; }
  int precedence() { return _precedence; }

  virtual void evaluate(std::vector<double> & eval)
  {
    size_t n = eval.size();
    double A;
    if (_content.compare("+") == 0)
      A = eval[n - 2] + eval[n - 1];
    else if (_content.compare("-") == 0)
      A = eval[n - 2] - eval[n - 1];
    else if (_content.compare("*") == 0)
      A = eval[n - 2] * eval[n - 1];
    else if (_content.compare("/") == 0)
      A = eval[n - 2] / eval[n - 1];
    else if (_content.compare("^") == 0)
      A = pow(eval[n - 2], eval[n - 1]);

    eval.erase(eval.end() - 2, eval.end());
    eval.push_back(A);
  }

protected:
private:
  Associativity _associativity;
  int _precedence;
};
