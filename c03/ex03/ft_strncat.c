/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 16:59:09 by hchoo             #+#    #+#             */
/*   Updated: 2023/07/24 00:18:41 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	index;
	unsigned int	index_src;

	index = 0;
	index_src = 0;
	while (dest[index] != '\0')
		index++;
	while (src[index_src] != '\0' && index_src < nb)
	{
		dest[index + index_src] = src[index_src];
		index_src++;
	}
	dest[index + index_src] = '\0';
	return (dest);
}
