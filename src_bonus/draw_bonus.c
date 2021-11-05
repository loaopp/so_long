/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:20:23 by yejeon            #+#    #+#             */
/*   Updated: 2021/11/05 21:32:56 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	put_img(t_win *win, t_img *img, t_pos *pos)
{
	mlx_put_image_to_window(win->mlx, win->win, img->id, \
		pos->x * MAP_TILE_SIZE, pos->y * MAP_TILE_SIZE);
}

static void	select_img(t_win *win, char type, t_pos *pos)
{
	if (MAP_PLAYER == type)
		put_img(win, &win->player.img_player, pos);
	else if (MAP_ENEMY == type)
		put_img(win, &win->map.img_enemy, pos);
	else if (MAP_WALL == type)
		put_img(win, &win->map.img_wall, pos);
	else if (MAP_GOAL == type)
		put_img(win, &win->map.img_goal, pos);
	else if (MAP_BG == type)
		put_img(win, &win->map.img_bg, pos);
	else if (MAP_ITEM == type)
		put_img(win, &win->map.img_item, pos);
}

void	draw_map(t_win *win)
{
	t_pos	pos;
	char	type;

	pos.y = 0;
	while (pos.y < win->map.h)
	{
		pos.x = 0;
		while (pos.x < win->map.w)
		{
			type = get_map_type(win, &pos);
			if (type != MAP_BG)
				select_img(win, MAP_BG, &pos);
			if (type != MAP_PLAYER)
			select_img(win, type, &pos);
			pos.x++;
		}
		pos.y++;
	}
	select_img(win, MAP_PLAYER, &win->player.pos);
}
