/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 13:00:15 by heinfalt          #+#    #+#             */
/*   Updated: 2017/03/08 13:00:17 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	char *line;
	int fd;

	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
		ft_strdel(&line);
	}
	return (0);
}
