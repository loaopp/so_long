/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 08:25:23 by yejeon            #+#    #+#             */
/*   Updated: 2021/05/09 11:03:48 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

int		ft_set_line(char **str, char **line, ssize_t size)
{
	char	*temp;
	char	*pos;

	if (-1 == size)
		return (-1);
	pos = ft_strchr(*str, '\n');
	if (pos)
	{
		*pos = 0;
		temp = *str;
		*line = ft_strdup(*str);
		*str = ft_strdup(pos + 1);
		if (temp)
			free(temp);
		return (1);
	}
	else if (*str)
	{
		*line = *str;
		*str = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*str;
	char		buf[BUFFER_SIZE + 1];
	ssize_t		size;
	char		*temp;

	if (fd < 0 || NULL == line || BUFFER_SIZE < 1)
		return (-1);
	size = 0;
	if (0 == ft_strchr(str, '\n'))
	{
		while (0 < (size = read(fd, buf, BUFFER_SIZE)))
		{
			buf[size] = 0;
			temp = str;
			str = ft_strjoin(str, buf);
			if (temp)
				free(temp);
			if (ft_strchr(buf, '\n'))
				break ;
		}
	}
	return (ft_set_line(&str, line, size));
}
