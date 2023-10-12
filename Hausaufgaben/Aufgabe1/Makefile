SRC = main.c sincos.c
OBJ = $(SRC:.c=.o)

sincos: $(OBJ)
	gcc -o $@ $+

%.o: %.c Makefile
	gcc -Wall -Wextra -c -o $@ $<

clean:
	rm -f $(OBJ)
