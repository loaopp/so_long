/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:53:51 by yejeon            #+#    #+#             */
/*   Updated: 2021/11/05 21:11:42 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	loop_main(t_win *win)
{
	draw_map(win);
	draw_info(win);
	return (0);
}

int	main(int argc, char **argv)
{
	t_win	win;

	if (2 != argc)
	{
		ft_putstr_fd("Invalid number of arguments.", STDOUT_FILENO);
		return (0);
	}
	ft_memset(&win, 0, sizeof(t_win));
	chk_map(&win, argv[1]);
	init_game(&win);
	mlx_loop_hook(win.mlx, loop_main, &win);
	mlx_key_hook(win.win, key_hook, &win);
	mlx_hook(win.win, CLOSE_BUTTON, 0, exit_window, &win);
	mlx_loop(win.mlx);
	return (0);
}
