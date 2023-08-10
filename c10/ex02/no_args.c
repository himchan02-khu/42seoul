/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 06:11:47 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/08 06:32:41 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	no_args(int max, int bufsize)
{
	char	*buf;
	int		len;
	int		len_before;

	buf = (char *)malloc(sizeof(char) * (bufsize));
	len = 1;
	len_before = 0;
	while (len != 0)
	{
		len = read(0, &buf[len_before], bufsize);
		len_before += len;
	}
	if (len_before > max)
		write(1, &buf[len_before - max], max);
	else
		write(1, buf, len_before);
	free(buf);
}

int	print_header(int argc, char *argv[], int i, int tf)
{
	if (i != 3 && argc > 4 && open(argv[i], 0) != -1 && tf == 1)
		write(1, "\n", 1);
	if (open(argv[i], O_RDONLY) != -1 && argc > 4)
	{
		write (1, "==> ", 4);
		write (1, basename(argv[i]), str_len(basename(argv[i])));
		write (1, " <==\n", 5);
		tf = 1;
	}
	return (tf);
}

void	illegal(char *argv, char *input)
{
	write(1, basename(argv), str_len(basename(argv)));
	write(1, ": ", 2);
	write(1, "illegal offset -- ", 18);
	write(1, basename(input), str_len(input));
	write(1, "\n", 1);
}
