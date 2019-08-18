#pragma once

#include "Token.h"
#include <math.h>
#include <cmath>
#include <algorithm>

class Function : public Token
{
public:
  Function(std::string s) : Token(Type::FUNCTION, s) {}

  virtual void evaluate(std::vector<double> & eval)
  {
    size_t n = eval.size();
    if (_content.compare("sin") == 0)
      eval[n - 1] = sin(eval[n - 1]);
    else if (_content.compare("cos") == 0)
      eval[n - 1] = sin(eval[n - 1]);
    else if (_content.compare("max") == 0)
    {
      eval[n - 2] = std::max(eval[n - 2], eval[n - 1]);
      eval.erase(eval.begin() + n - 1);
    }
    else if (_content.compare("min") == 0)
    {
      eval[n - 2] = std::min(eval[n - 2], eval[n - 1]);
      eval.erase(eval.begin() + n - 1);
    }
    else if (_content.compare("factorial") == 0)
      eval[n - 1] = factorial(eval[n - 1]);
  }

  double factorial(double n)
  {
    double ans = 1;
    for (double i = n; i > 0; i -= 1)
    {
      ans *= i;
    }
    return ans;
  }

protected:
private:
};
