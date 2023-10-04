/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 01:05:05 by hchoo             #+#    #+#             */
/*   Updated: 2023/07/29 09:21:23 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	index;
	int	*tmp;

	index = 0;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	tmp = (int *)malloc(sizeof(int) * (max - min));
	if (tmp == 0)
		return (-1);
	while (index < max - min)
	{
		tmp[index] = min + index;
		index++;
	}
	*range = tmp;
	return (index);
}
