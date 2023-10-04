/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:50:38 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/03 18:11:33 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	index;
	int	*tmp;

	index = 0;
	tmp = (int *)malloc(sizeof(int) * length);
	while (index < length)
	{
		tmp[index] = f(tab[index]);
		index++;
	}
	return (tmp);
}
