/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_util_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:27:19 by yejeon            #+#    #+#             */
/*   Updated: 2021/11/05 21:06:30 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	get_map_type(t_win *win, t_pos *pos)
{
	return (*(win->map.buf + (pos->y * win->map.w) + pos->x));
}

void	set_map_type(t_win *win, t_pos *pos, char type)
{
	*(win->map.buf + (pos->y * win->map.w) + pos->x) = type;
}
