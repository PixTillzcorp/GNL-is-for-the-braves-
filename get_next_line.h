/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 10:22:17 by heinfalt          #+#    #+#             */
/*   Updated: 2016/12/15 10:22:18 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10
# define MAX_FD 4096

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

int		get_next_line(const int fd, char **line);

#endif
