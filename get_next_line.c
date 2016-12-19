/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 10:22:11 by heinfalt          #+#    #+#             */
/*   Updated: 2016/12/15 10:22:13 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

static void			apd_lst(t_list **alst, t_list *new)
{
	if (alst && new)
	{
		while ((**alst).next)
			*alst = (**alst).next;
		(**alst).next = new;
	}
}

static t_list		*init_lst(t_list **elem, const int fd)
{
	while (fd != (**elem).content->fd)
		*elem = (**elem).next;
	return (*elem);
}

static char			**apd_line(char **line, int *head, int *check, char *buf)
{
	int i;

	i = 0;
	while (buf[i] != '\n' && buf[i])
		*line[*head++] = buf[i++];
	if (buf[i] == '\n')
		*check += 1;
	return (line);
}

static int			lecture(const int fd, char **line, t_list **elem)
{
	char			*buf;
	int				check;
	int				nbr_chr_rd;

	check = 0;
	nbr_chr_rd = BUFF_SIZE;
	buf = (char *)ft_memalloc(sizeof(char) * BUFF_SIZE + 1);
	while (nbr_chr_rd == BUFF_SIZE && check != 1)
	{
		nbr_chr_rd = read(fd, buf, BUFF_SIZE);
		if (nbr_chr_rd == -1)
		{
			free(buf);
			return (-1);
		}
		buf[nbr_chr_rd] = '\0';
		apd_line(line, &((**elem).content->head), &check, buf);
	}
	if (check)
		(**elem).content->save_buf = buf;
	free(buf);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static	t_list	**elem;
	t_list			**save;
	t_fd_n_save 	*data;
	int				ret;

	save = elem;
	data->fd = fd;
	data->head = 0;
	data->save_buf = NULL;
	if ((**elem).next == NULL)
		*elem = ft_lstnew(data, sizeof(t_fd_n_save));
	else if (fd != (**elem).content->fd)
		apd_lst(elem, ft_lstnew(data, sizeof(t_fd_n_save)));
	elem = save;
	*elem = init_lst(elem, fd);
	return (lecture(fd, line, elem));
}
