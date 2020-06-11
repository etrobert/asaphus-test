#include "generateXOString.h"

#include <sstream>
#include <stdexcept>

using std::string;
using std::ostringstream;
using std::invalid_argument;

enum Char { X, O };

string generateXOString(int countX, int countO)
{
  ostringstream oss;

  int counts[2] = { [X]=countX, [O]=countO };

  Char lastChar = X;
  int lastCharCount = 0;

  const auto addChar = [&oss, &counts, &lastChar, &lastCharCount](Char c) {
    if (counts[c] == 0)
      throw invalid_argument("Cannot generate XO string with the given values");
    --counts[c];

    oss << (c == X ? 'X' : 'O');

    if (lastChar == c)
      ++lastCharCount;
    else
    {
      lastCharCount = 1;
      lastChar = c;
    }
  };

  while (counts[X] > 0 || counts[O] > 0)
  {
    const Char highestCountChar = counts[X] > counts[O] ? X : O;
    if (lastChar == highestCountChar && lastCharCount == 3)
      addChar(highestCountChar == X ? O : X);
    else
      addChar(highestCountChar);
  }
  return oss.str();
}
