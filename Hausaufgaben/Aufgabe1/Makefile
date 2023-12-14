SRC = main.c sincos.c
OBJ = $(SRC:.c=.o)

sincos: $(OBJ)
	gcc -Wall -Wextra -o $@ $+

%.o: %.c Makefile
	gcc -MMD -Wall -Wextra -c -o $@ $<

clean:
	rm -f $(OBJ) sincos sincos.d main.d

-include sincos.d main.d
