/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 16:33:42 by hchoo             #+#    #+#             */
/*   Updated: 2023/07/23 17:03:54 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	index;
	int	index_src;

	index = 0;
	index_src = 0;
	while (dest[index] != '\0')
		index++;
	while (src[index_src] != '\0')
	{
		dest[index + index_src] = src[index_src];
		index_src++;
	}
	dest[index + index_src] = '\0';
	return (dest);
}
