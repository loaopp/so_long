/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:56:54 by yejeon            #+#    #+#             */
/*   Updated: 2021/11/05 21:35:07 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	move_up(t_win *win)
{
	t_pos	pos;

	pos.x = win->player.pos.x;
	pos.y = win->player.pos.y - 1;
	move(win, pos);
}

static void	move_down(t_win *win)
{
	t_pos	pos;

	pos.x = win->player.pos.x;
	pos.y = win->player.pos.y + 1;
	move(win, pos);
}

static void	move_left(t_win *win)
{
	t_pos	pos;

	pos.x = win->player.pos.x - 1;
	pos.y = win->player.pos.y;
	move(win, pos);
}

static void	move_right(t_win *win)
{
	t_pos	pos;

	pos.x = win->player.pos.x + 1;
	pos.y = win->player.pos.y;
	move(win, pos);
}

int	key_hook(int key, t_win *win)
{
	if (key == KEY_W || key == KEY_ARROW_UP)
		move_up(win);
	else if (key == KEY_S || key == KEY_ARROW_DOWN)
		move_down(win);
	else if (key == KEY_A || key == KEY_ARROW_LEFT)
		move_left(win);
	else if (key == KEY_D || key == KEY_ARROW_RIGHT)
		move_right(win);
	else if (key == KEY_ESC || key == KEY_Q)
		exit_window(win);
	return (0);
}
