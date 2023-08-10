/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:28:48 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/08 06:32:33 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	str_len(char *str)
{
	int	size;

	size = 0;
	while (str[size] != '\0')
		size++;
	return (size);
}

void	print_error(char *argv, char *filename)
{
	write(1, basename(argv), str_len(basename(argv)));
	write(1, ": ", 2);
	write(1, filename, str_len(filename));
	write(1, ": ", 2);
	write(1, strerror(errno), str_len(strerror(errno)));
	write(1, "\n", 1);
	return ;
}

void	print_file(char *argv, char *filename, int tail_size, int bufsize)
{
	int		fd;
	char	*buf;
	int		len;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_error(argv, filename);
	else
	{
		buf = (char *)malloc(sizeof(char) * (bufsize));
		len = read(fd, buf, bufsize);
		if (len == bufsize)
			print_file(argv, filename, tail_size, (bufsize * 2));
		else
		{
			if (len < tail_size)
				write(1, buf, len);
			else
				write(1, &buf[len - tail_size], tail_size);
		}
		free(buf);
		close(fd);
		return ;
	}
}

int	check_nb(char *str)
{
	int	save;
	int	i;

	save = 0;
	i = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		save = save * 10 + (str[i] - 48);
		i++;
	}
	if (i == 0)
		return (-1);
	return (save);
}

int	main(int argc, char *argv[])
{
	int		len;
	int		i;
	int		tf;

	len = check_nb(argv[2]);
	if (len == -1)
		illegal(argv[0], argv[2]);
	else if (argc < 4 && len != -1)
		no_args(len, 100000);
	else
	{
		i = 3;
		tf = 0;
		while (argv[i] != 0)
		{
			tf = print_header(argc, argv, i, tf);
			print_file(argv[0], argv[i++], len, 1);
		}
	}
	return (0);
}
