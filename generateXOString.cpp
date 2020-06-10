#include "generateXOString.h"
#include <sstream>

using std::string;
using std::stringstream;

string generateXOString(int countX, int countO)
{
  (void)countX;
  (void)countO;
  stringstream ss;

  for (int i(0); i < countX; ++i)
    ss << 'X';
  for (int i(0); i < countO; ++i)
    ss << 'O';

  return ss.str();
}
