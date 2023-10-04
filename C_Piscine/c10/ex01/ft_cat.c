/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:28:48 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/09 17:15:06 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

int	str_len(char *str)
{
	int	size;

	size = 0;
	while (str[size] != '\0')
		size++;
	return (size);
}

void	print_file(char *argv, char *filename, int len)
{
	int		fd;
	char	buf[1024];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(1, basename(argv), str_len(basename(argv)));
		write(1, ": ", 2);
		write(1, filename, str_len(filename));
		write(1, ": ", 2);
		write(1, strerror(errno), str_len(strerror(errno)));
		write(1, "\n", 1);
		return ;
	}
	while (len != 0)
	{
		len = read(fd, buf, 1024);
		write(1, buf, len);
	}
	close(fd);
}

int	main(int argc, char *argv[])
{
	char	buf[1024];
	int		len;

	len = 1;
	if (argc == 1)
	{
		while (len != 0)
		{
			len = read(0, buf, 1024);
			write (1, buf, len);
		}
	}
	else
		while (argv[len] != 0)
			print_file(argv[0], argv[len++], 1);
	return (0);
}
