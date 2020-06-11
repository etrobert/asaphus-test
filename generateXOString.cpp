#include "generateXOString.h"

#include <sstream>

using std::string;
using std::ostringstream;

enum Char { X, O };

string generateXOString(int countX, int countO)
{
  ostringstream oss;

  int counts[2];
  counts[X] = countX;
  counts[O] = countO;

  Char lastChar = X;
  int lastCharCount = 0;

  auto addChar = [&oss, &counts, &lastChar, &lastCharCount](Char c) {
    if (counts[c] == 0)
      throw "Error"; // TODO throw exception
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
    Char highestCountChar = counts[X] > counts[O] ? X : O;
    if (lastChar == highestCountChar && lastCharCount == 3)
      addChar(highestCountChar == X ? O : X);
    else
      addChar(highestCountChar);
  }
  return oss.str();
}
