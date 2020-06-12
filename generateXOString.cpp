#include "generateXOString.h"

#include <sstream>
#include <stdexcept>

using std::string;
using std::ostringstream;
using std::invalid_argument;

enum Char { X, O };

string generateXOString(unsigned int countX, unsigned int countO)
{
  ostringstream oss;
  oss.exceptions(ostringstream::failbit | ostringstream::badbit);

  unsigned int counts[2] = { [X]=countX, [O]=countO };

  Char lastChar = X;
  unsigned int lastCharCount = 0;

  const auto addChar = [&oss, &counts, &lastChar, &lastCharCount](Char c) {
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
    // We will attempt to add the Char that still has the highest count
    const Char highestCountChar = counts[X] > counts[O] ? X : O;
    // Except if the last 3 characters were the highest count char
    // in which case we try to add the lowest count char
    if (lastChar == highestCountChar && lastCharCount == 3)
    {
      const Char lowestCountChar = highestCountChar == X ? O : X;
      if (counts[lowestCountChar] == 0)
        throw invalid_argument("Cannot generate XO string with the given values");
      addChar(lowestCountChar);
    }
    else
      addChar(highestCountChar);
  }
  return oss.str();
}
