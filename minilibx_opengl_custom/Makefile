# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/09 10:13:12 by yejeon            #+#    #+#              #
#    Updated: 2021/05/11 01:45:17 by yejeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## This Makefile is from original minilibx (opengl ver.)


## You should change ../mlx_opengl to your minilibx (opengl ver.) path.
ORG=../minilibx_opengl
NAME = libmlx.a
NOM=$(ORG)/$(NAME)
SRC=mlx_get_screen_size.m
OBJ=$(SRC:.m=.o)
CC=gcc
CFLAGS+=-O2 -w
RM=rm -f
#Add -w option to remove warning from compiling minilibx

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

all: $(NOM)
#	mv $(NOM) ../$(NAME)

$(NOM):	$(OBJ)
	make -C $(ORG)
	ar r $(NOM) $(OBJ)

clean:
	rm -f $(OBJ)
	make clean -C $(ORG)

re: clean all
