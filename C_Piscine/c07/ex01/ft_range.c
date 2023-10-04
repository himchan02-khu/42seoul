/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:16:34 by hchoo             #+#    #+#             */
/*   Updated: 2023/07/28 04:24:01 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	index;
	int	*str;

	if (min >= max)
		return (0);
	str = (int *)malloc(sizeof(int) * (max - min));
	index = 0;
	while (index < max - min)
	{
		str[index] = min + index;
		index++;
	}
	return (str);
}
