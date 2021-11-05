# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/09 10:45:43 by yejeon            #+#    #+#              #
#    Updated: 2021/05/11 01:44:49 by yejeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libgnl.a
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
SRC		=	get_next_line.c
OBJ		=	$(SRC:.c=.o)

DIR_LIBFT	=	../libft/
LIBFT		=	$(DIR_LIBFT)libft.a

all:	$(NAME)
#	mv	$(NAME) ../$(NAME)

$(NAME):	$(OBJ)
	ar rsc $@ $^

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

fclean:	clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)

re:	fclean all

.PHONY:	all clean fclean re
