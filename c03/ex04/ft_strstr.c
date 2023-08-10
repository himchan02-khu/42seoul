/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 17:04:13 by hchoo             #+#    #+#             */
/*   Updated: 2023/07/24 09:43:58 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	index_tf;
	int	index_str;

	index_str = 0;
	if (!(*to_find))
		return (str);
	while (str[index_str] != '\0')
	{
		index_tf = 0;
		if (str[index_str] == to_find[index_tf])
		{
			while (to_find[index_tf] != '\0')
			{
				if (str[index_str + index_tf] != to_find[index_tf])
					break ;
				else
					index_tf++;
			}
			if (to_find[index_tf] == '\0')
				return (&str[index_str]);
		}
		index_str++;
	}
	return (0);
}
