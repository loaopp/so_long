/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:43:19 by yejeon            #+#    #+#             */
/*   Updated: 2021/11/05 18:58:27 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	create_map(t_win *win, int fd)
{
	char	*buf;
	char	*temp;
	int	re;

	buf = 0;
	re = get_next_line(fd, &buf);
	if (re <= 0)
	{
		close(fd);
		msg_err_to_exit("fail - load map data.", 0);
	}
	win->map.w = ft_strlen(buf);
	while (0 < re)
	{
		win->map.h++;
		if (win->map.w != (int)ft_strlen(buf))
			win->map_info.wrong_rect = 1;
		temp = ft_strjoin(win->map.buf, buf);
		free(win->map.buf);
		free(buf);
		win->map.buf = temp;
		re = get_next_line(fd, &buf);
	}
	free(buf);
}

static int		is_equal(char *a, char *b)
{
	if (a == NULL || b == NULL)
		return (0);
	return (0 == ft_strncmp(a, b, ft_strlen(a)));
}

void	chk_file(t_win *win, char *path)
{
	int	fd;

	fd = 0;
	if (0 == is_equal(path + ft_strlen(path) - 4, ".ber"))
		msg_err_to_exit("Wrong - file is not .ber", 0);
	fd = open(path, O_RDONLY);
	if (!fd)
		msg_err_to_exit("fail - open map file.", 0);
	create_map(win, fd);
	close(fd);
}

