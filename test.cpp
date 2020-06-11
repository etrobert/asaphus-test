#include <cppunit/TestCase.h>
#include <stdexcept>
#include <algorithm>

#include "generateXOString.h"
#include "testXOString.h"

using std::string;
using std::to_string;
using std::ostringstream;
using std::invalid_argument;
using std::min;
using std::max;

class TestXOStringTest : public CppUnit::TestCase
{
  public:
    TestXOStringTest(string name) : CppUnit::TestCase(name) {}

  void runTest()
  {
    // Test with string ""
    CPPUNIT_ASSERT(testXOString(0, 0, ""));
    CPPUNIT_ASSERT(!testXOString(1, 0, ""));
    CPPUNIT_ASSERT(!testXOString(0, 1, ""));
    CPPUNIT_ASSERT(!testXOString(1, 1, ""));
    CPPUNIT_ASSERT(!testXOString(100000, 0, ""));

    // Test with one X
    CPPUNIT_ASSERT(testXOString(1, 0, "X"));
    CPPUNIT_ASSERT(!testXOString(0, 0, "X"));
    CPPUNIT_ASSERT(!testXOString(0, 1, "X"));
    CPPUNIT_ASSERT(!testXOString(1, 1, "X"));

    // Test with incorrect character
    CPPUNIT_ASSERT(!testXOString(0, 0, "V"));
    CPPUNIT_ASSERT(!testXOString(1, 0, "V"));
    CPPUNIT_ASSERT(!testXOString(0, 1, "V"));

    // Test with multiple lenghts of X
    CPPUNIT_ASSERT(testXOString(3, 0, "XXX"));
    CPPUNIT_ASSERT(!testXOString(4, 0, "XXXX"));
    CPPUNIT_ASSERT(!testXOString(5, 0, "XXXXX"));

    // Tests from subject
    CPPUNIT_ASSERT(testXOString(2, 3, "XOOOX"));
    CPPUNIT_ASSERT(testXOString(2, 3, "OXOXO"));
    CPPUNIT_ASSERT(testXOString(6, 1, "XXXOXXX"));
    CPPUNIT_ASSERT(!testXOString(6, 1, "XXOXXXX"));
  }
};

int ceilDivide(int x, int y)
{
  return (x + y - 1) / y;
}

void testGenerate(int countX, int countO)
{
  const int big = max(countX, countO);
  const int small = min(countX, countO);
  // The most extreme count difference is when we have XXXOXXXOXXX...
  // With every three X divided by one O or the other way around
  // In this case we have one O for every three X, minus one
  // Every count difference bigger than that should trigger an exception
  if (ceilDivide(big, 3) > small + 1)
  {
    CPPUNIT_ASSERT_THROW(generateXOString(countX, countO), invalid_argument);
    return;
  }

  string s = generateXOString(countX, countO);
  ostringstream message;
  message << "countX: " << countX << "; countY: " << countO << "; s: " << s;
  CPPUNIT_ASSERT_MESSAGE(message.str(), testXOString(countX, countO, s));
}

class GenerateXOStringTest : public CppUnit::TestCase
{
  public:
    GenerateXOStringTest(string name) : CppUnit::TestCase(name) {}

    void runTest()
    {
      testGenerate(0, 0);
      testGenerate(1, 0);
      testGenerate(0, 1);
      testGenerate(1, 1);

      testGenerate(4, 1);
      testGenerate(1, 4);
      testGenerate(4, 4);


      testGenerate(6, 1);
      testGenerate(1, 6);
      testGenerate(7, 7);
      testGenerate(5, 5);

      testGenerate(90, 45);

      testGenerate(20, 53);

      // Should throw
      testGenerate(4, 0);
      testGenerate(0, 4);
      testGenerate(0, 100);
      testGenerate(10, 53);
    }
};

#include <cppunit/ui/text/TestRunner.h>

int main()
{
  CppUnit::TextUi::TestRunner runner;
  runner.addTest(new TestXOStringTest("TestXOStringTest"));
  runner.addTest(new GenerateXOStringTest("GenerateXOStringTest"));
  runner.run();
}
