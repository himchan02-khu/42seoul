/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:41:07 by hchoo             #+#    #+#             */
/*   Updated: 2023/07/26 01:17:09 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	unsigned int	index_src;

	index = 0;
	index_src = 0;
	while (src[index_src] != '\0')
		index_src++;
	if (size == 0)
		return (index_src);
	while (index < size - 1 && src[index] != '\0')
	{
		if (src[index] != '\0')
		{
			dest[index] = src[index];
			index++;
		}
		else
			break ;
	}
	dest[index] = '\0';
	return (index_src);
}
