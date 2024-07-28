SRC = big_sort.c error.c moves2.c moves3.c moves.c parse.c sorting.c sorting_tools.c split.c main.c utils.c validarg.c
OBJ = $(SRC:.c=.o)
CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

.PHONY : re fclean all bonus clean
.SECONDARY : ${OBJ}

%.o : %.c
	$(CC) $(CFLAGS) $< -c -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all : $(NAME)


clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
