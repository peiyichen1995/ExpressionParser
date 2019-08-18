#include "ExpressionParser.h"
#include "Tokenizer.h"

int main(int argc, char const *argv[]) {
  // Tokenizer A("1 + 2   - 3 *    sin ( 5 )");
  // A.tokenize();
  // A.print();

  if (argc != 2) {
    std::cout << "Usage: ./ExpressionParser file_name.txt\n";
    return -1;
  }

  ExpressionParser A(argv[1]);
  A.evaluate();

  return 0;
}
