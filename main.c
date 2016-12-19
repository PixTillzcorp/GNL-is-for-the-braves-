/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 17:15:27 by heinfalt          #+#    #+#             */
/*   Updated: 2016/12/19 17:15:29 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int		main(int argc, char **argv)
{
	int fd;
	int ret;
	char *line;

	if (argc != 2)
		return (0);
	fd = open("swag.txt", O_RDONLY, S_IRUSR);
	while (ret != 0 && ret != -1)
	{
		line = NULL;
		line = (char *)malloc(sizeof(char) * 512);
		ret = get_next_line(fd, &line);
		printf("%s\n", line);
	}
	return (0);
}
