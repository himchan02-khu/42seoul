/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 00:16:32 by hchoo             #+#    #+#             */
/*   Updated: 2023/07/26 19:17:24 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_memory(long long iaddr, char *tr)
{
	unsigned int	i;
	char			rev_l[17];

	i = 0;
	rev_l[16] = '\0';
	while (i < 16)
	{
		rev_l[15 - i] = tr[iaddr % 16];
		iaddr /= 16;
		i++;
	}
	write (1, rev_l, 16);
	write (1, ": ", 2);
}

void	print_text_16(unsigned char *c, int size, int index, char *tr)
{
	if (size < index + 1)
		write(1, "  ", 2);
	else
	{
		write(1, &tr[(int)c[index] / 16], 1);
		write(1, &tr[(int)c[index] % 16], 1);
	}
}

void	print_text(unsigned char *c, unsigned int size, unsigned int index)
{
	unsigned int	i;
	unsigned char	ch;

	i = 0;
	ch = '.';
	while (i < 16)
	{
		if (size - index - i == 0)
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
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char		*c;
	unsigned int		i;
	unsigned int		j;
	char				*tr;

	c = (unsigned char *) addr;
	i = 0;
	tr = "0123456789abcdef";
	if (size == 0)
		return (addr);
	while (i < size)
	{
		print_memory((long long)addr + i, tr);
		j = 0;
		while (j < 16)
		{
			print_text_16(c, (int)size, (int)i + (int)j, tr);
			print_text_16(c, (int)size, (int)i + (int)j + 1, tr);
			j = j + 2;
			write(1, " ", 1);
		}
		print_text(c, size, i);
		i += 16;
	}
	return (addr);
}
