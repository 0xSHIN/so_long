SRCS		=	converters/c.c	\
			converters/d_i.c	\
			converters/s.c \
			utils/flags.c	\
			converters/p.c		\
			converters/percent.c 	\
			converters/u.c				\
			converters/x.c \
			converters/X.c \
			utils/check.c \
			utils/flags.c \
			utils/ft_count.c \
			utils/ft_print.c \
			ft_printf.c \

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

RM			=	rm -f

CFLAGS		= 	-Wall -Wextra -Werror

NAME		= 	libftprintf.a

all:		$(NAME)

$(NAME):	$(OBJS)
	@echo $(HEADER)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re bonus

