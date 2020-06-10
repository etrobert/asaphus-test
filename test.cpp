#include <cppunit/TestCase.h>
#include "generateXOString.h"
#include "testXOString.h"

using std::string;

class TestXOStringTest : public CppUnit::TestCase
{
  public:
    TestXOStringTest(string name) : CppUnit::TestCase(name) {}

  void runTest()
  {
    CPPUNIT_ASSERT(testXOString(0, 0, ""));
    CPPUNIT_ASSERT(!testXOString(1, 0, ""));
    CPPUNIT_ASSERT(!testXOString(0, 1, ""));
    CPPUNIT_ASSERT(!testXOString(1, 1, ""));
    CPPUNIT_ASSERT(!testXOString(100000, 0, ""));

    CPPUNIT_ASSERT(testXOString(1, 0, "X"));
    CPPUNIT_ASSERT(!testXOString(0, 0, "X"));
    CPPUNIT_ASSERT(!testXOString(0, 1, "X"));
    CPPUNIT_ASSERT(!testXOString(1, 1, "X"));

    CPPUNIT_ASSERT(!testXOString(0, 0, "V"));
    CPPUNIT_ASSERT(!testXOString(1, 0, "V"));
    CPPUNIT_ASSERT(!testXOString(0, 1, "V"));

    CPPUNIT_ASSERT(testXOString(3, 0, "XXX"));
    CPPUNIT_ASSERT(!testXOString(4, 0, "XXXX"));
    CPPUNIT_ASSERT(!testXOString(5, 0, "XXXXX"));

    CPPUNIT_ASSERT(testXOString(2, 3, "XOOOX"));
    CPPUNIT_ASSERT(testXOString(2, 3, "OXOXO"));
    CPPUNIT_ASSERT(testXOString(6, 1, "XXXOXXX"));
    CPPUNIT_ASSERT(!testXOString(6, 1, "XXOXXXX"));
  }
};

class GenerateXOStringTest : public CppUnit::TestCase
{
  public:
    GenerateXOStringTest(string name) : CppUnit::TestCase(name) {}

    void runTest()
    {
      CPPUNIT_ASSERT(testXOString(0, 0, generateXOString(0, 0)));
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
