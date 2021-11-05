/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:10:46 by yejeon            #+#    #+#             */
/*   Updated: 2021/11/05 21:22:27 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	chk_wall(t_win *win)
{
	int	x;
	int	y;

	y = 0;
	while (y < win->map.h)
	{
		if (y == 0 || y == win->map.h - 1)
		{
			x = 0;
			while (x < win->map.w)
			{
				if (MAP_WALL != win->map.buf[win->map.w * y + x])
					win->map_info.wrong_wall = 1;
				x++;
			}
		}
		else
		{
			if (MAP_WALL != win->map.buf[win->map.w * y] || \
				MAP_WALL != win->map.buf[win->map.w * y + win->map.w - 1])
				win->map_info.wrong_wall = 1;
		}
		y++;
	}
}

static int	is_ok_char(char ch)
{
	return (MAP_PLAYER == ch || \
			MAP_ITEM == ch || \
			MAP_BG == ch || \
			MAP_WALL == ch || \
			MAP_GOAL == ch);
}

static void	load_map(t_win *win)
{
	char	ch;
	int	i;

	i = 0;
	while (win->map.buf[i])
	{
		ch = win->map.buf[i];
		if (!is_ok_char(ch))
			win->map_info.wrong_char = 1;
		if (MAP_PLAYER == ch)
		{
			win->player.pos.x = i % win->map.w;
			win->player.pos.y = i / win->map.w;
			win->map_info.cnt_player++;
		}
		if (MAP_ITEM == ch)
			win->map_info.cnt_item++;
		if (MAP_GOAL == ch)
			win->map_info.cnt_goal++;
		i++;
	}
}

static void	chk_map_info(t_win *win)
{
	if (win->map_info.wrong_rect)
		msg_err_to_exit("Wrong - map is not rect.", 0);
	if (win->map_info.wrong_char)
		msg_err_to_exit("Wrong - map type", 0);
	if (win->map_info.wrong_wall)
		msg_err_to_exit("Wrong - wall", 0);
	if (win->map_info.cnt_player != 1)
		msg_err_to_exit("Wrong - player cnt", 0);
	if (win->map_info.cnt_item < 1)
		msg_err_to_exit("Wrong - item cnt", 0);
	if (win->map_info.cnt_goal < 1)
		msg_err_to_exit("Wrong - goal cnt", 0);
}

void	chk_map(t_win *win, char *path)
{
	chk_file(win, path);
	load_map(win);
	chk_wall(win);
	chk_map_info(win);
}
