#pragma once

#include "Tokenizer.h"
#include <fstream>
#include <iostream>

class ExpressionParser
{
public:
  ExpressionParser(std::string f) : _filename(f) {}

  void evaluate()
  {
    std::ifstream file(_filename);
    std::string line;
    unsigned int i = 0;
    while (std::getline(file, line))
    {
      if (!line.empty() && line.find_first_not_of(' ') != std::string::npos)
      {
        i++;
        _t.setInput(line);
        _t.tokenize();
        std::vector<Token *> RPN = _t.toPostFix();
        std::cout << "line " << i << ": \n";
        _t.printTokens();
        // _t.printRPN();

        // evaluate RPN
        for (unsigned int i = 0; i < RPN.size(); i++)
          RPN[i]->evaluate(_eval);

        std::cout << "= " << _eval[0] << std::endl;

        _eval.clear();
      }
    }

    return;
  }

protected:
private:
  Tokenizer _t;
  std::string _filename;
  std::vector<double> _eval;
};
