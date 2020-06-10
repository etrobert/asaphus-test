#include <cppunit/TestCase.h>
#include "generateXOString.h"

using std::string;

class GenerateXOStringTest : public CppUnit::TestCase
{
  public:
    GenerateXOStringTest(string name) : CppUnit::TestCase(name) {}

    void runTest()
    {
      CPPUNIT_ASSERT(generateXOString(0, 0) == "");
      CPPUNIT_ASSERT(generateXOString(0, 0) == "");
    }
};

#include <cppunit/ui/text/TestRunner.h>

int main()
{
  CppUnit::TextUi::TestRunner runner;
  runner.addTest(new GenerateXOStringTest("GenerateXOStringTest"));
  runner.run();
}
