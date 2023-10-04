/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 01:12:47 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/06 04:56:01 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	size_str(char **str, int n)
{
	int	index;

	index = 0;
	while (str[n][index] != '\0')
		index++;
	return (index);
}

char	*add_strs(int size, char **strs, char *sep, char *str)
{
	int	tmp_str;
	int	index;
	int	tmp;

	tmp_str = 0;
	index = -1;
	while (++index < size)
	{
		tmp = 0;
		while (strs[index][tmp] != '\0')
		{
			str[tmp_str] = strs[index][tmp];
			tmp++;
			tmp_str++;
		}
		tmp = 0;
		while (sep[tmp] != '\0' && index < size - 1)
		{
			str[tmp_str] = sep[tmp];
			tmp++;
			tmp_str++;
		}
	}
	str[tmp_str] = 0;
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		index;
	int		strs_size;
	char	*str;

	if (size <= 0)
	{
		str = (char *)malloc(1);
		str[0] = 0;
		return (str);
	}
	index = -1;
	strs_size = 0;
	while (++index < size)
		strs_size += size_str(strs, index);
	index = 0;
	while (sep[index] != '\0')
		index++;
	strs_size += index * (size - 1);
	str = (char *)malloc(sizeof(char) * strs_size + 2);
	str = add_strs(size, strs, sep, str);
	return (str);
}
