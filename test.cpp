#include <cppunit/TestCase.h>
#include "generateXOString.h"
#include "testXOString.h"

using std::string;
using std::to_string;
using std::stringstream;

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

void testGenerate(int countX, int countO)
{
  string s = generateXOString(countX, countO);
  stringstream errorss;
  errorss << "countX: " << countX << "; countY: " << countO << "; s: " << s;
  CPPUNIT_ASSERT_MESSAGE(errorss.str(), testXOString(countX, countO, s));
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

      // Should throw
      // testGenerate(4, 0);
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
