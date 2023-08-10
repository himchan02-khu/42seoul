/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 05:14:58 by hchoo             #+#    #+#             */
/*   Updated: 2023/07/31 23:06:44 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int			check_space(char c);
int			check_base(char *base);
long long	ft_atoi_base(char *str, char *base);

char	*nbr_to_base(char *base, unsigned int size, unsigned int nbr, char *s)
{
	char	str[33];
	int		index;
	int		i;

	index = -1;
	while (++index < 33)
		str[index] = 0;
	index = 0;
	while (nbr >= size)
	{
		str[index] = base[nbr % size];
		nbr = nbr / size;
		index++;
	}
	str[index++] = base[nbr];
	i = 1;
	if (s[0] != '-')
		i--;
	while (index-- >= 0)
	{
		s[i] = str[index];
		i++;
	}
	s[i] = 0;
	return (s);
}

char	*ft_putnbr_base(long long nbr, char *base, char *str_return)
{
	unsigned int	index;
	unsigned int	ch_nbr;

	if (!(check_base(base)))
		return (0);
	index = 0;
	while (base[index] != '\0')
		index++;
	if (nbr < 0)
	{
		ch_nbr = nbr * (-1);
		str_return[0] = '-';
	}
	else
		ch_nbr = nbr;
	str_return = nbr_to_base(base, index, ch_nbr, str_return);
	return (str_return);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	tr_nbr;
	char		*str_return;

	tr_nbr = ft_atoi_base(nbr, base_from);
	if (tr_nbr == 0 && !check_base(base_from))
		return (0);
	str_return = (char *)malloc(sizeof(char) * 40);
	str_return = ft_putnbr_base(tr_nbr, base_to, str_return);
	return (str_return);
}
