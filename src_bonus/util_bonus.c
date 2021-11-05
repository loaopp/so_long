/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:07:44 by yejeon            #+#    #+#             */
/*   Updated: 2021/11/05 21:41:35 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	msg_err_to_exit(const char *msg, const char *arg)
{
	printf("\033[40;31mERROR : \033[0m");
	printf(msg, arg);
	printf("\n");
	exit(EXIT_FAILURE);
}

static void	destroy_img(t_win *win)
{
	mlx_destroy_image(win->mlx, win->player.img_player.id);
	mlx_destroy_image(win->mlx, win->map.img_enemy.id);
	mlx_destroy_image(win->mlx, win->map.img_bg.id);
	mlx_destroy_image(win->mlx, win->map.img_goal.id);
	mlx_destroy_image(win->mlx, win->map.img_item.id);
	mlx_destroy_image(win->mlx, win->map.img_wall.id);
}

int	exit_window(t_win *win)
{
	free(win->map.buf);
	destroy_img(win);
	mlx_destroy_window(win->mlx, win->win);
	ft_putstr_fd("exit so_long bye!\n", STDOUT_FILENO);
	exit(EXIT_SUCCESS);
	return (0);
}
