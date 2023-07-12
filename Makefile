NAME = so_long
NAME_B = so_long_bonus

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

SRCS_B =	bonus/parsing_bonus.c\
			bonus/main_bonus.c\
			bonus/get_next_line_bonus.c\
			bonus/get_next_line_utils_bonus.c\
			bonus/utils_bonus.c\
			bonus/split_bonus.c\
			bonus/flood_fill_bonus.c\
			bonus/hookah_bonus.c\
			bonus/error_bonus.c\
			bonus/game_bonus.c\
			bonus/utils_1_bonus.c\
			bonus/enemy_hook_bonus.c

HEADER = mandatory/so_long.h
HEADER_B = bonus/so_long_bonus.h

OBJ = $(patsubst %.c, %.o, $(SRCS))
OBJ_B = $(patsubst %.c, %.o, $(SRCS_B))

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -I mlx
MLXFLAG = -L /usr/local/bin -Lmlx -lmlx -framework OpenGL -framework AppKit
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
	$(RM) $(NAME) $(NAME_B)

re : fclean all

rb : fclean bonus

.PHONY: all clean fclean re bonus rb