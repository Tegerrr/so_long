NAME = push_swap
NAME_B = checker

SRCS =	mandatory/parsing.c\
		mandatory/main.c\

SRCS_B =	

HEADER = mandatory/push_swap.h
HEADER_B = bonus/push_swap_bonus.h

OBJ = $(patsubst %.c, %.o, $(SRCS))
OBJ_B = $(patsubst %.c, %.o, $(SRCS_B))

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -Imlx

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

bonus :
	make OBJ="$(OBJ_B)" HEADER="$(HEADER_B)" NAME="$(NAME_B)" all

clean :
	rm -f $(OBJ) $(OBJ_B)

fclean : clean
	$(RM) $(NAME)

re : fclean all

rb : fclean bonus

.PHONY: all clean fclean re bonus rb