/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:47:23 by hchoo             #+#    #+#             */
/*   Updated: 2023/07/29 14:33:33 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*dup;
	int		size;
	int		index;

	size = 0;
	index = 0;
	while (src[size] != '\0')
		size++;
	dup = (char *)malloc(sizeof(char) * size + 1);
	while (index < size)
	{
		dup[index] = src[index];
		index++;
	}
	dup[index] = 0;
	return (dup);
}
