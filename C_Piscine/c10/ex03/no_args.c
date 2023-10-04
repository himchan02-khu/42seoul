/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 06:11:47 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/08 03:16:23 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	buf_return(int c_x, char *buf, int *count, int buflen)
{
	int		len_fd_tf[3];

	len_fd_tf[0] = read(0, &buf[buflen], 16 - buflen) + buflen;
	if (buflen == len_fd_tf[0])
		return ;
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
		len_fd_tf[0] = read(0, buf, 16);
		*count += 1;
	}
	buf[len_fd_tf[0]] = 0;
	if (len_fd_tf[0] > 0)
		buf_return(c_x, buf, count, str_len(buf));
}

void	no_args(int c_x)
{
	char	*buf;
	int		count;

	buf = (char *)malloc(sizeof(char) * (35));
	count = 0;
	buf[16] = 0;
	buf[33] = 0;
	buf[34] = 0;
	buf_return(c_x, buf, &count, str_len(buf));
	if (str_len(buf) != 0)
		ft_print_memory(buf, str_len(buf), c_x, count);
	if (count != 0 || str_len(buf) != 0)
		print_memory(str_len(buf) + (count * 16), "0123456789abcdef", c_x, 0);
	if (count != 0 || str_len(buf) != 0)
		write(1, "\n", 1);
}

void	illegal(char *argv, char *input)
{
	write(1, basename(argv), str_len(basename(argv)));
	write(1, ": ", 2);
	write(1, basename(input), str_len(input));
	write(1, ": Bad file descriptor", 21);
	write(1, "\n", 1);
}
