/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:53:27 by yejeon            #+#    #+#             */
/*   Updated: 2021/11/05 21:16:25 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_info(t_win *win)
{
	printf("step : %d  -  item : %d\n", \
		win->player.cnt_step, win->player.cnt_item);
}

void	draw_info(t_win *win)
{
	char	*step;
	char	*item;
	char	*board;
	char	*num;

	num = ft_itoa(win->player.cnt_step);
	step = ft_strjoin("step : ", num);
	free(num);
	num = ft_itoa(win->player.cnt_item);
	item = ft_strjoin(" - item : ", num);
	free(num);
	board = ft_strjoin(step, item);
	if (board)
		mlx_string_put(win->mlx, win->win, 10, 20, MAP_COLOR_TEXT, board);
	free(step);
	free(item);
	free(board);
}
