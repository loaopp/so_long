/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:25:31 by yejeon            #+#    #+#             */
/*   Updated: 2021/11/05 21:36:11 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_map(t_win *win)
{
	win->map.cnt_item = win->map_info.cnt_item;
	win->map.tail_size = MAP_TILE_SIZE;
}

static void	load_png(void *mlx, t_img *img, char *path)
{
	img->id = mlx_png_file_to_image(mlx, path, &img->w, &img->h);
	if (0 == img->id)
		msg_err_to_exit("fail : load_png error : ", path);
}

static void	init_texture(t_win *win)
{
	load_png(win->mlx, &win->player.img_player, PATH_IMG_PLAYER);
	load_png(win->mlx, &win->map.img_enemy, PATH_IMG_ENEMY);
	load_png(win->mlx, &win->map.img_bg, PATH_IMG_BG);
	load_png(win->mlx, &win->map.img_wall, PATH_IMG_WALL);
	load_png(win->mlx, &win->map.img_item, PATH_IMG_ITEM);
	load_png(win->mlx, &win->map.img_goal, PATH_IMG_GOAL);
}

static void	init_win(t_win *win)
{
	win->w = win->map.w * win->map.tail_size;
	win->h = win->map.h * win->map.tail_size;
	win->win = mlx_new_window(win->mlx, win->w, win->h, "so_long");
	if (0 == win->win)
		msg_err_to_exit("fail : create window.", 0);
}

void	init_game(t_win *win)
{
	win->mlx = mlx_init();
	init_texture(win);
	init_map(win);
	init_win(win);
}
