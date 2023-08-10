/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:06:21 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/01 10:06:23 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putnbr(int nb)
{
	int		n;
	char	c;

	n = 1000000000;
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -1 * nb;
	}
	while (nb > 0 && n > 1)
	{
		c = (nb / n) % 10 + '0';
		if (nb / n != 0)
			write (1, &c, 1);
		n = n / 10;
	}
	c = nb % 10 + '0';
	write (1, &c, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	index;
	int	index_in;

	index = 0;
	while (par[index].str != 0)
	{
		index_in = -1;
		while (par[index].str[++index_in] != '\0')
			write(1, &par[index].str[index_in], 1);
		write(1, "\n", 1);
		index_in = -1;
		ft_putnbr(par[index].size);
		write(1, "\n", 1);
		while (par[index].copy[++index_in] != '\0')
			write(1, &par[index].copy[index_in], 1);
		write(1, "\n", 1);
		index++;
	}
}
