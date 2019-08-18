#pragma once

enum class Type
{
  VALUE,
  FUNCTION,
  OPERATOR,
  PARENTHESIS,
  UNKNOWN
};

enum class Associativity
{
  LEFT,
  RIGHT,
  BOTH,
  UNKNOWN
};
