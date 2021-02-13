NAME = libft.a
SRC = *.c
OBJ = *.o
CC = gcc
RANLIB = ranlib
ARRC = ar rc
REMOVE = @/bin/rm -f
FLAGS = -c -Wall -Werror -Wextra -I.

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC)
	$(ARRC) $(NAME) $(OBJ)
	$(RANLIB) $(NAME)

clean:
	$(REMOVE) $(OBJ)
	$(REMOVE) *~

fclean:
	$(REMOVE) $(OBJ) $(NAME)
	$(REMOVE) *~

re: fclean all