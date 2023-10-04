/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 01:50:57 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/08 13:48:02 by hchoo            ###   ########.fr       */
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

int	check_error_file(char *argv, char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(1, basename(argv), str_len(basename(argv)));
		write(1, ": ", 2);
		write(1, filename, str_len(filename));
		write(1, ": ", 2);
		write(1, strerror(errno), str_len(strerror(errno)));
		write(1, "\n", 1);
		return (0);
	}
	return (1);
}

void	end_buf_return(int c_x, char *argv, char *buf, int *count)
{
	int		len_fd_tf[3];

	len_fd_tf[1] = open(argv, O_RDONLY);
	len_fd_tf[0] = str_len(buf);
	len_fd_tf[0] += read(len_fd_tf[1], &buf[str_len(buf)], 16 - str_len(buf));
	while (len_fd_tf[0] >= 16)
	{
		if (ft_strcmp(buf, &buf[17]) != 0)
		{
			ft_print_memory(buf, len_fd_tf[0], c_x, *count);
			buf[34] = 1;
		}
		else if (ft_strcmp(buf, &buf[17]) == 0 && buf[34] == 1)
		{
			buf[34] = 0;
			write (1, "*\n", 2);
		}
		while (--len_fd_tf[0] >= 0)
			buf[len_fd_tf[0] + 17] = buf[len_fd_tf[0]];
		len_fd_tf[0] = read(len_fd_tf[1], buf, 16);
		*count += 1;
	}
	close(len_fd_tf[1]);
	buf[len_fd_tf[0]] = 0;
}

void	file_print(int c_x, char *argv[])
{
	int		f_index;
	char	*buf;
	int		count;

	f_index = 1;
	count = 0;
	if (c_x == 1)
		f_index++;
	buf = (char *)malloc(sizeof(char) * 35);
	buf[16] = 0;
	buf[33] = 0;
	buf[34] = 0;
	while (argv[f_index] != 0)
	{
		if (!check_error_file(argv[0], argv[f_index]))
			f_index++;
		else
			end_buf_return(c_x, argv[f_index++], buf, &count);
	}
	if (str_len(buf) != 0)
		ft_print_memory(buf, str_len(buf), c_x, count);
	if (count != 0 || str_len(buf) != 0)
		print_memory(str_len(buf) + (count * 16), "0123456789abcdef", c_x, 0);
	if (count != 0 || str_len(buf) != 0)
		write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	int	c_x;
	int	index;

	c_x = 0;
	if (argc == 1)
		no_args(0);
	else if (argc == 2 && check_op(argv[1][0], argv[1][1]))
		no_args(1);
	else if (argc >= 2)
		c_x = check_op(argv[1][0], argv[1][1]);
	if (argc != 1 && !(argc == 2 && check_op(argv[1][0], argv[1][1])))
	{
		index = 1;
		while (open(argv[index + c_x], 0) == -1 && argv[index + c_x] != 0)
			index++;
		if (index + c_x == argc)
		{
			index = 1;
			while (argv[index + c_x] != 0)
				check_error_file(argv[0], argv[index++ + c_x]);
			illegal(argv[0], argv[index + c_x - 1]);
		}
		else
			file_print(c_x, argv);
	}
}
