CFLAGS=-Wall -Werror -Wextra
LDFLAGS=-lcppunit
NAME=asaphus-test

$(NAME): generateXOString.cpp test.cpp
	g++ -o $@  $^ $(CFLAGS) $(LDFLAGS)
