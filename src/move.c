/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:08:18 by yejeon            #+#    #+#             */
/*   Updated: 2021/11/05 21:42:07 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	move_defore(t_win *win, t_pos *pos)
{
	if (pos->x < 0 || win->map.w <= pos->x)
		return (0);
	if (pos->y < 0 || win->map.h <= pos->y)
		return (0);
	return (MAP_WALL != get_map_type(win, pos));
}

static void	go(t_win *win, t_pos *pos)
{
	win->player.pos.x = pos->x;
	win->player.pos.y = pos->y;
	win->player.cnt_step++;
}

static int	chk_quest(t_win *win)
{
	return (win->map.cnt_item == win->player.cnt_item);
}

static void	move_after(t_win *win)
{
	char	type;

	type = get_map_type(win, &win->player.pos);
	if (MAP_GOAL == type && chk_quest(win))
	{
		ft_putstr_fd("SUCCESS!!\n", STDOUT_FILENO);
		exit_window(win);
	}
	else if (MAP_ENEMY == type)
	{
		ft_putstr_fd("YOU DIE\n", STDOUT_FILENO);
		exit_window(win);
	}
	else if (MAP_ITEM == type)
	{
		set_map_type(win, &win->player.pos, MAP_BG);
		win->player.cnt_item++;
	}
}

void	move(t_win *win, t_pos pos)
{
	if (!move_defore(win, &pos))
		return ;
	go(win, &pos);
	move_after(win);
	print_info(win);
}
