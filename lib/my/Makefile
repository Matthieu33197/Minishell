##
## EPITECH PROJECT, 2019
## make
## File description:
## files
##

SRC	=	my.c				\
		directory.c			\
		command.c			\
		check.c				\
		path_exe.c			\
		my2.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-Wall -W -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
clean:
		rm -rf *.o
		rm -rf $(NAME)

fclean:		clean
