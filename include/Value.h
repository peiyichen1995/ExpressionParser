#pragma once

#include "Token.h"

class Value : public Token
{
public:
  Value(double v, std::string s) : Token(Type::VALUE, s), _value(v) {}

  virtual void evaluate(std::vector<double> & eval) { eval.push_back(_value); }

protected:
private:
  double _value;
};
