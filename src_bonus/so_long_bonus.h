/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:54:24 by yejeon            #+#    #+#             */
/*   Updated: 2021/11/05 21:06:54 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>

# include "../minilibx_opengl/mlx.h"
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

# include "so_long_define_bonus.h"

typedef struct	s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct	s_img
{
	void	*id;
	char	*buf;
	int		w;
	int		h;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_img;

typedef struct	s_player
{
	t_pos	pos;
	int		cnt_step;
	int		cnt_item;
	t_img	img_player;
}				t_player;

typedef struct	s_map
{
	char	*buf;
	int		w;
	int		h;
	int		tail_size;
	int		cnt_item;
	t_img	img_bg;
	t_img	img_enemy;
	t_img	img_goal;
	t_img	img_item;
	t_img	img_wall;
}				t_map;

typedef struct	s_map_info
{
	int		cnt_player;
	int		cnt_enemy;
	int		cnt_item;
	int		cnt_goal;
	int		wrong_wall;
	int		wrong_char;
	int		wrong_rect;
}				t_map_info;

typedef struct	s_win
{
	void		*mlx;
	void		*win;
	size_t		w;
	size_t		h;
	t_player	player;
	t_map		map;
	t_map_info	map_info;
}				t_win;

void	chk_file(t_win *win, char *path);
void	chk_map(t_win *win, char *path);

void	init_game(t_win *win);

int	exit_window(t_win *win);

void	msg_err_to_exit(const char *msg, const char *arg);

int	key_hook(int key, t_win *win);

void	draw_map(t_win *win);

void	move(t_win *win, t_pos pos);

char	get_map_type(t_win *win, t_pos *pos);
void	set_map_type(t_win *win, t_pos *pos, char type);

void	print_info(t_win *win);
void	draw_info(t_win *win);

#endif
