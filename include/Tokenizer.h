#pragma once

#include <bits/stdc++.h>
#include <exception>
#include <iostream>
#include <stdio.h>
#include <string>
#include "Operator.h"
#include "Value.h"
#include "Parenthesis.h"
#include "Function.h"

class Tokenizer
{
public:
  Tokenizer() : _input("") {}
  Tokenizer(std::string s) : _input(s) {}

  void tokenize()
  {
    std::stringstream check(_input);
    std::string intermediate;
    while (getline(check, intermediate, ' '))
    {
      if (!intermediate.empty())
      {
        // Check enum
        bool is_number;
        double parsed;
        try
        {
          parsed = std::stod(intermediate, NULL);
          is_number = true;
        }
        catch (std::exception & e)
        {
          is_number = false;
        }

        Token * tmp;
        std::string operator_list = "+-*/^";

        if (is_number)
          tmp = new Value(parsed, intermediate);
        else
        {
          if (intermediate.compare("(") == 0)
            tmp = new Parenthesis(true, intermediate);
          else if (intermediate.compare(")") == 0)
            tmp = new Parenthesis(false, intermediate);
          else if (operator_list.find(intermediate) != std::string::npos)
            tmp = new Operator(intermediate);
          else
            tmp = new Function(intermediate);
        }
        _tokens.push_back(tmp);
      }
    }
  }

  std::vector<Token *> & toPostFix()
  {
    for (unsigned int i = 0; i < _tokens.size(); i++)
    {
      if (_tokens[i]->type() == Type::VALUE)
        _RPN.push_back(_tokens[i]);
      else if (_tokens[i]->type() == Type::FUNCTION)
        _operators.insert(_operators.begin(), _tokens[i]);
      else if (_tokens[i]->type() == Type::OPERATOR)
      {
        if (_operators.empty())
          _operators.push_back(_tokens[i]);
        else
        {
          while (
              (_operators[0]->type() == Type::FUNCTION ||
               static_cast<Operator *>(_operators[0])->precedence() >
                   static_cast<Operator *>(_tokens[i])->precedence() ||
               (static_cast<Operator *>(_operators[0])->precedence() ==
                    static_cast<Operator *>(_tokens[i])->precedence() &&
                static_cast<Operator *>(_operators[0])->associativity() == Associativity::LEFT)) &&
              _operators[0]->content().compare("(") != 0)
          {
            _RPN.push_back(_operators[0]);
            _operators.erase(_operators.begin());

            if (_operators.empty())
              break;
          }

          _operators.insert(_operators.begin(), _tokens[i]);
        }
      }

      if (_tokens[i]->type() == Type::PARENTHESIS)
      {
        if (static_cast<Parenthesis *>(_tokens[i])->left())
          _operators.insert(_operators.begin(), _tokens[i]);
        else
        {
          while (_operators[0]->type() != Type::PARENTHESIS ||
                 (_operators[0]->type() == Type::PARENTHESIS &&
                  !static_cast<Parenthesis *>(_operators[0])->left()))
          {
            _RPN.push_back(_operators[0]);
            _operators.erase(_operators.begin());
            if (_operators.empty())
              std::cout << "Parenthesis mismatch." << std::endl;
          }
          if (_operators[0]->type() == Type::PARENTHESIS &&
              static_cast<Parenthesis *>(_operators[0])->left())
          {
            _operators.erase(_operators.begin());
            if (_operators[0]->type() == Type::FUNCTION)
            {
              _RPN.push_back(_operators[0]);
              _operators.erase(_operators.begin());
            }
          }
        }
      }

      std::cout << "Added " << _tokens[i]->content() << std::endl;
      printRPN();
      printOperators();
      std::cout << "----------------------------\n";
    }

    if (!_operators.empty())
    {
      _RPN.insert(_RPN.end(), _operators.begin(), _operators.end());
      _operators.clear();
    }

    return _RPN;
  }

  void setInput(std::string s)
  {
    clear();
    _input = s;
  }

  void printTokens()
  {
    std::cout << "Tokens: ";
    for (unsigned int i = 0; i < _tokens.size(); i++)
      std::cout << *_tokens[i] << " ";
    std::cout << '\n';
  }

  void printRPN()
  {
    std::cout << "RPN: ";
    for (unsigned int i = 0; i < _RPN.size(); i++)
      std::cout << *_RPN[i] << " ";
    std::cout << '\n';
  }

  void printOperators()
  {
    std::cout << "Operators: ";
    for (unsigned int i = 0; i < _operators.size(); i++)
      std::cout << *_operators[i] << " ";
    std::cout << '\n';
  }

  void clear()
  {
    _input = "";

    for (auto it = _tokens.begin(); it != _tokens.end(); it++)
      delete *it;

    _tokens.clear();
    _RPN.clear();
    _operators.clear();
  }

protected:
private:
  std::vector<Token *> _tokens;
  std::string _input;
  std::vector<Token *> _RPN;
  std::vector<Token *> _operators;
};
