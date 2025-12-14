CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
SRC = ft_printf.c \
		ft_printf_utils.c \
		ft_printf_flags.c \
		ft_printf_flags2.c

OBJS = ${SRC:.c=.o}
LIBC = ar rcs
RM = rm -f

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all : ${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
