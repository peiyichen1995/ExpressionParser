#pragma once

#include "ParserEnum.h"
#include <string>

class Token
{
public:
  Token(Type t, std::string s) : _type(t), _content(s) {}

  virtual ~Token() {}

  friend std::ostream & operator<<(std::ostream & os, const Token & t);

  const std::string content() const { return _content; }

  std::string content() { return _content; }

  Type type() { return _type; }

  virtual void evaluate(std::vector<double> & eval) = 0;

protected:
  Type _type;
  std::string _content;

private:
};

inline std::ostream &
operator<<(std::ostream & os, const Token & t)
{
  std::cout << t.content();
  return os;
}
