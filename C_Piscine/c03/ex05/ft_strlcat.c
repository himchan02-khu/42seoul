/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:19:18 by hchoo             #+#    #+#             */
/*   Updated: 2023/07/24 02:24:10 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	index_dest;
	unsigned int	index_src;
	unsigned int	tmp;

	index_dest = 0;
	index_src = 0;
	tmp = 0;
	while (dest[index_dest] != '\0')
		index_dest++;
	while (src[index_src] != '\0')
		index_src++;
	if (size < index_dest)
		return (index_src + size);
	if (index_dest < size)
	{
		while (tmp < size - index_dest - 1 && src[tmp] != '\0')
		{
			dest[index_dest + tmp] = src[tmp];
			tmp++;
		}
		dest[index_dest + tmp] = '\0';
	}
	return (index_dest + index_src);
}
