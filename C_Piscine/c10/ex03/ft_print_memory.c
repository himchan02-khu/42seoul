/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 00:16:32 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/08 13:47:41 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

void	print_memory(long long iaddr, char *tr, int c_x, unsigned int size)
{
	int		i;
	char	rev_l[9];

	i = 0;
	rev_l[8] = '\0';
	while (i < 7 + c_x)
	{
		rev_l[6 + c_x - i] = tr[iaddr % 16];
		iaddr /= 16;
		i++;
	}
	if (c_x == 0)
		rev_l[7] = 0;
	write (1, rev_l, i);
	if (size != 0 && c_x == 1)
		write (1, "  ", 2);
	else if (size != 0 && c_x == 0)
		write (1, " ", 1);
}

void	print_text_16(unsigned char *c, int size, int index, char *tr)
{
	if (size < index + 1)
		write(1, "  ", 2);
	else
	{
		write(1, &tr[(int)c[index % 16] / 16], 1);
		write(1, &tr[(int)c[index % 16] % 16], 1);
	}
}

void	print_text(unsigned char *c, unsigned int size, int index, int c_x)
{
	int				i;
	unsigned char	ch;

	i = 0;
	if (c_x != 1)
	{
		write(1, "\n", 1);
		return ;
	}
	ch = '.';
	write(1, " |", 2);
	while (i < 16)
	{
		if ((int)size - index - i == 0)
			break ;
		if (c[index + i] < ' ' || c[index + i] > '~')
		{
			write (1, ".", 1);
			i++;
			continue ;
		}
		write(1, &c[index + i], 1);
		i++;
	}
	write(1, "|\n", 2);
}

void	ft_print_memory(void *addr, unsigned int size, int c_x, int count)
{
	unsigned char		*c;
	unsigned int		j;
	char				*tr;

	c = (unsigned char *) addr;
	tr = "0123456789abcdef";
	print_memory((long long)count * 16, tr, c_x, size);
	j = 0;
	while (j < 16 && size != 0)
	{
		print_text_16(c, (int)size, (int)j, tr);
		if (c_x >= 1 || (j != 15 && c_x == 0))
			write(1, " ", 1);
		if (j == 7 && c_x >= 1)
			write (1, " ", 1);
		j++;
	}
	if (size != 0)
		print_text(c, size, 0, c_x);
	return ;
}
