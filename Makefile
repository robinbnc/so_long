
SRCS	=	./srcs/get_next_line.c ./srcs/get_next_line_utils.c ./srcs/maps_checker.c\
			./srcs/window.c ./srcs/image.c ./srcs/draw_game.c ./srcs/game_initialisation.c\
			./srcs/gameplay.c ./srcs/main.c ./srcs/exit.c

SRCS_BONUS = ./bonus/get_next_line_bonus.c ./bonus/get_next_line_utils_bonus.c ./bonus/maps_checker_bonus.c\
			./bonus/window_bonus.c ./bonus/image_bonus.c ./bonus/draw_game_bonus.c ./bonus/game_initialisation_bonus.c\
			./bonus/gameplay_bonus.c ./bonus/main_bonus.c ./bonus/exit_bonus.c ./bonus/utils_bonus.c ./bonus/enemy_bonus.c

OBJS	=	${SRCS:.c=.o}

OBJS_BONUS	=	${SRCS_BONUS:.c=.o}


NAME	=	so_long

CC	=		gcc

CFLAGS	=	-Wall -Wextra -Werror

LFLAGS = ./minilibx/libmlx_Linux.a -lXext -lX11 -I ./minilibx/include

RM	=		rm -f

.c.o:	so_long
		$(CC) $(CFLAGS) -I. -c $< -o $@

$(NAME): $(OBJS) mlx
	$(CC) -o $(NAME) $(OBJS) $(LFLAGS)

bonus: $(OBJS_BONUS) mlx
	$(CC) -o $(NAME) $(OBJS_BONUS) $(LFLAGS)

all:		${NAME}

clean:
			${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

mlx:
	make -C ./minilibx

.PHONY:		all clean fclean re