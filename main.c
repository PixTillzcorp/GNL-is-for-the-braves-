#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int fd;
	int ret;
	char *line;

	if (argc != 2)
	{
		ft_putstr("wrong number of arguments\n");
		return (0);
	}
	fd = 0;
	if (fd == -1)
	{
		ft_putstr("failed to open\n");
		return (0);
	}
	ret = get_next_line(fd, &line);
	ft_putstr("ret = ");
	ft_putnbr(ret);
	ft_putchar('\n');
	free(line);
	return (0);
}
