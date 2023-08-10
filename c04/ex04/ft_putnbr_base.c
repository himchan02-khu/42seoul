/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 00:56:57 by hchoo             #+#    #+#             */
/*   Updated: 2023/07/26 09:25:46 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	check_dup(char *base)
{
	int		index;
	int		i;

	index = 0;
	while (base[index] != '\0')
	{
		i = index + 1;
		while (base[i] != '\0')
		{
			if (base[index] == base[i])
				return (0);
			i++;
		}
		index++;
	}
	return (index);
}

int	check_out(char *base)
{
	int	index;
	int	check;

	index = 0;
	while (base[index] != '\0')
	{
		if (base[index] == '+' || base[index] == '-')
			return (0);
		index++;
	}
	check = check_dup(base);
	if (index < 2 || check == 0)
		return (0);
	else
		return (index);
}

void	nbr_to_base(char *base, unsigned int size, unsigned int nbr)
{
	char				str[33];
	unsigned int		index;

	index = 0;
	while (index < 33)
	{
		str[index] = 0;
		index++;
	}
	index = 0;
	while (nbr >= size)
	{
		str[index] = base[nbr % size];
		nbr = nbr / size;
		index++;
	}
	str[index] = base[nbr];
	while (index > 0)
	{
		write(1, &str[index], 1);
		index--;
	}
	write(1, &str[index], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	index;
	unsigned int	ch_nbr;

	if (!(check_out(base)))
		return ;
	index = 0;
	while (base[index] != '\0')
		index++;
	if (nbr < 0)
	{
		ch_nbr = nbr * (-1);
		write(1, "-", 1);
	}
	else
		ch_nbr = nbr;
	nbr_to_base(base, index, ch_nbr);
}
