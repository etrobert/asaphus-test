#include "testXOString.h"

using std::string;

bool testXOString(int countX, int countO, string s)
{
  int actualCountX(0);
  int actualCountO(0);

  char previousChar = s[0];
  int currentCharCount = 0;

  for (char c: s)
  {
    if (c == 'X')
      ++actualCountX;
    else if (c == 'O')
      ++actualCountO;
    else
      return false;

    if (c == previousChar)
    {
      if (currentCharCount == 3)
        return false;
      ++currentCharCount;
    } else {
      previousChar = c;
      currentCharCount = 1;
    }
  }
  if (actualCountX != countX || actualCountO != countO)
    return false;
  return true;
}
