#include "generateXOString.h"
#include <sstream>

using std::string;
using std::ostringstream;

string generateXOString(int countX, int countO)
{
  (void)countX;
  (void)countO;
  ostringstream oss;

  for (int i(0); i < countX; ++i)
    oss << 'X';
  for (int i(0); i < countO; ++i)
    oss << 'O';

  return oss.str();
}
