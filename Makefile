NAME = so_long
NAME_B = checker

SRCS =	mandatory/parsing.c\
		mandatory/main.c\
		mandatory/get_next_line.c\
		mandatory/get_next_line_utils.c\
		mandatory/utils.c\
		mandatory/split.c\
		mandatory/flood_fill.c\
		mandatory/hookah.c\
		mandatory/error.c\
		mandatory/game.c\
		mandatory/utils_1.c

SRCS_B =	

HEADER = mandatory/so_long.h
HEADER_B = bonus/push_swap_bonus.h

OBJ = $(patsubst %.c, %.o, $(SRCS))
OBJ_B = $(patsubst %.c, %.o, $(SRCS_B))

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -I mlx
MLXFLAG = -L /usr/local/bin -Lmandatory/mlx -lmlx -framework OpenGL -framework AppKit
all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(MLXFLAG) $(OBJ) -o $(NAME)

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