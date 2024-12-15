SRC	=	src/main.c\
		src/mem_allocation.c\
		src/nqueen_solving.c

OBJ	=	$(SRC:.c=.o)

NAME	=	nqueen

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
