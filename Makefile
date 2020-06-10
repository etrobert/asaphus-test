CFLAGS=-Wall -Werror -Wextra
LDFLAGS=-lcppunit
NAME=asaphus-test

.PHONY: run

$(NAME): generateXOString.cpp test.cpp testXOString.cpp
	g++ -o $@  $^ $(CFLAGS) $(LDFLAGS)

run: $(NAME)
	./$(NAME)
