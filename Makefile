CXX=g++
CFLAGS=-Wall -Werror -Wextra
LDLIBS=-lcppunit
NAME=asaphus-test

SRCS=test.cpp testXOString.cpp generateXOString.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

.PHONY: run all clean

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDLIBS)

test.o: test.cpp testXOString.h generateXOString.h

testXOString.o: testXOString.cpp testXOString.h

generateXOString.o: generateXOString.cpp generateXOString.h

clean:
	rm -f $(OBJS)

run: $(NAME)
	./$(NAME)
