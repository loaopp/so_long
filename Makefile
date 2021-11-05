# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/04 18:57:03 by yejeon            #+#    #+#              #
#    Updated: 2021/11/05 21:24:32 by yejeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

FRAMEWORK	=	-framework OpenGL \
				-framework AppKit \
				-lz

DIR_SRC			=	./src/
DIR_OBJ			=	./obj/
DIR_SRC_BONUS	=	./src_bonus/
DIR_OBJ_BONUS	=	./obj_bonus/

DIR_LIBFT	=	./libft/
DIR_GNL		=	./gnl/
DIR_CUSTOM	=	./minilibx_opengl_custom/
DIR_MLX		=	./minilibx_opengl/

LIB_FT		=	libft.a
LIB_GNL		=	libgnl.a
LIB_MLX		=	libmlx.a

SRCS		=	main.c \
				file.c \
				init.c \
				hook_key.c \
				draw.c \
				map.c \
				map_util.c \
				move.c \
				print.c \
				util.c

OBJS		=	$(SRCS:%.c=$(DIR_OBJ)%.o)
OBJS_BONUS	=	$(SRCS:%.c=$(DIR_OBJ_BONUS)%_bonus.o)

LIBS		=	$(DIR_LIBFT)$(LIB_FT) \
				$(DIR_GNL)$(LIB_GNL) \
				$(DIR_MLX)$(LIB_MLX)

VPATH	=	$(DIR_SRC):$(DIR_SRC_BONUS)

all:	$(NAME)

$(NAME):	$(DIR_OBJ) $(LIBS) $(OBJS)
	@$(CC) $(CFLAGS) $(FRAMEWORK) -o $@ $(LIBS) $(OBJS)

bonus:		$(DIR_OBJ_BONUS) $(LIBS) $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(FRAMEWORK) -o $(NAME) $(LIBS) $(OBJS_BONUS)

$(DIR_OBJ)%.o:	$(DIR_SRC)%.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(DIR_OBJ_BONUS)%.o:	$(DIR_SRC_BONUS)%.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(DIR_OBJ):
	@mkdir -p $@

$(DIR_OBJ_BONUS):
	@mkdir -p $@

$(LIBS):
	@make -C $(DIR_LIBFT)
	@make -C $(DIR_GNL)
	@make -C $(DIR_CUSTOM)

fclean:	clean
	@make fclean -C $(DIR_LIBFT)
	@make fclean -C $(DIR_GNL)
	@make clean -C $(DIR_CUSTOM)
	@rm -f $(NAME)

clean:
	@rm -rf $(DIR_OBJ)
	@rm -rf $(DIR_OBJ_BONUS)
	@rm -f *.o

re:		fclean all

reb:	fclean bonus

norm:
	@norminette $(DIR_SRC)*.[ch] $(DIR_SRC_BONUS)*.[ch]

.PHONY:	all fclean clean re norm a
