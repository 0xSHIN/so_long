SRCS		= srcs/so_long.c			 \
			srcs/init_img.c 		\
			srcs/parse_map.c 		\
			srcs/parse_map_sup.c 		\
			srcs/utils.c		 \
			srcs/move_player.c		 \
			srcs/move_player_sup.c		 \
			srcs/flood_fill.c		 \
			srcs/handle_error.c		 \
			srcs/handle_error_sup.c		 \
			libft/get_next_line.c		 \
			libft/get_next_line_utils.c		 \
			libft/ft_itoa.c	\
			libft/ft_calloc.c	\
			srcs/find_player.c		 \
			srcs/map_validity.c		 \
			ft_printf/converters/c.c	\
			ft_printf/converters/d_i.c	\
			ft_printf/converters/s.c \
			ft_printf/converters/p.c		\
			ft_printf/converters/percent.c 	\
			ft_printf/converters/u.c				\
			ft_printf/converters/x.c \
			ft_printf/converters/X.c \
			ft_printf/utils/check.c \
			ft_printf/utils/flags.c \
			ft_printf/utils/ft_count.c \
			ft_printf/utils/ft_print.c \
			ft_printf/ft_printf.c \

OBJS		=	$(SRCS:.c=.o)
NAME		=	so_long
CC		=	gcc -g3
FLAGS		=	-Wall -Wextra -Werror
MLX			= 	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
RM			=	rm -f

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
	@make -C ./mlx_linux
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)	

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re
