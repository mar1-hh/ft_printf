NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_printf_utils.c

SRCS_BONUS = ft_printf_bonus.c ft_printf_utils_bonus.c ft_printf_utils2_bonus.c

OBJ = ${SRCS:.c=.o}

OBJ_BONUS = ${SRCS_BONUS:.c=.o}

AR = ar rcs

BONUS_F = .bonus

all: ${NAME}

${NAME}: ${OBJ}
	${AR} $@ $?

bonus: ${BONUS_F}

${BONUS_F}: ${OBJ_BONUS}
	${AR} ${NAME} $?
	@touch $@

%.o: %.c ft_printf.h ft_printf_bonus.h
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJ} ${OBJ_BONUS} ${BONUS_F}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: clean