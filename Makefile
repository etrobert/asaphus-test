CFLAGS=-Wall -Werror -Wextra
LDFLAGS=-lcppunit
NAME=asaphus-test

$(NAME): generateXOString.cpp test.cpp testXOString.cpp
	g++ -o $@  $^ $(CFLAGS) $(LDFLAGS)
