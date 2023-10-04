/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:02:41 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/01 10:06:57 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	str_size(char **av, int n)
{
	int	index;

	index = 0;
	while (av[n][index] != '\0')
		index++;
	return (index);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	count;

	count = 0;
	while (src[count] != '\0')
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = src[count];
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					index;
	int					tmp;
	struct s_stock_str	*strs;

	index = 0;
	strs = (struct s_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	while (index < ac)
	{
		tmp = str_size(av, index);
		strs[index].str = (char *)malloc(sizeof(char) * (tmp + 1));
		strs[index].copy = (char *)malloc(sizeof(char) * (tmp + 1));
		strs[index].size = str_size(av, index);
		strs[index].str = ft_strcpy(strs[index].str, av[index]);
		strs[index].copy = ft_strcpy(strs[index].copy, av[index]);
		index++;
	}
	strs[index].str = 0;
	return (strs);
}
