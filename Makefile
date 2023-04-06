SRCS = ft_tab.c lee_algorithm.c main.c
EXEC = quickest_way
OBJS = ${SRCS:.c=.o}
CC = gcc -Wall -Wextra -Werror -fsanitize=address

all: ${EXEC}

.c.o:
	@${CC} -o $@ -c $<

${EXEC}: ${OBJS}
	@${CC} -o $@ $^

clean:
	@rm -f ${OBJS}

fclean:
	@rm -f ${EXEC}

cleanAll:
	@rm -f ${OBJS}
	@rm -f ${EXEC}

go: ${EXEC}
	clear
	./${EXEC}