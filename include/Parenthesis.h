#pragma once

#include "Token.h"

class Parenthesis : public Token
{
public:
  Parenthesis(bool left, std::string s) : Token(Type::PARENTHESIS, s), _left(left) {}

  bool left() { return _left; }

  virtual void evaluate(std::vector<double> & /*eval*/) {}

protected:
private:
  bool _left;
};
