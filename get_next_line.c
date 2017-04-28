/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 16:04:03 by heinfalt          #+#    #+#             */
/*   Updated: 2017/02/20 16:04:05 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strjoin_free(char *s1, char *s2, char flag)
{
	char		*out;

	out = ft_strjoin(s1, s2);
	if (flag == 'l' || flag == 'b')
		free(s1);
	if (flag == 'r' || flag == 'b')
		free(s2);
	return (out);
}

int				fill_buffer(int fd, char **line, char **stock)
{
	char		*buff;
	char		*chr;
	int			ret;

	if (!(buff = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) != 0)
	{
		if (ret < 0)
			return (-1);
		buff[ret] = 0;
		if (!(chr = ft_strchr(buff, '\n')))
			*line = ft_strjoin_free(*line, buff, 'l');
		else
		{
			*chr++ = 0;
			if (stock[fd])
				ft_memdel((void**)&(stock[fd]));
			stock[fd] = ft_strdup(chr);
			*line = ft_strjoin_free(*line, buff, 'b');
			return (1);
		}
	}
	free(buff);
	return (ft_strlen(*line) == 0 ? 0 : 1);
}

int				extract_stock(int fd, char **line, char **stock)
{
	char		*chr;
	int			ret;

	chr = ft_strchr(stock[fd], '\n');
	if (!chr)
	{
		*line = ft_strjoin_free(*line, stock[fd], 'l');
		ft_memdel((void**)&(stock[fd]));
		ret = fill_buffer(fd, line, stock);
		return (ret);
	}
	else
	{
		*chr++ = 0;
		*line = ft_strjoin_free(*line, stock[fd], 'l');
		stock[fd] = ft_strdup(chr);
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char	*stock[MAX_FD];
	int			ret;
	int			i;

	i = 0;
	ret = 0;
	if (fd < 0 || line == NULL)
		return (-1);
	*line = ft_strdup("");
	if (!stock[fd])
		ret = fill_buffer(fd, line, stock);
	else
		ret = extract_stock(fd, line, stock);
	if (ret <= 0)
	{
		ft_strdel(line);
		ft_memdel((void**)&(stock[fd]));
	}
	return (ret);
}
