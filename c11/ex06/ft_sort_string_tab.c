/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:03:40 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/03 18:05:32 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strcmp(char *s1, char *s2);

void	ft_sort_str(char *str[], int size)
{
	char	*min;
	int		index;
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		index = i;
		while (j < size)
		{
			if (ft_strcmp(str[index], str[j]) > 0)
				index = j;
			j++;
		}
		if (index != i)
		{
			min = str[index];
			str[index] = str[i];
			str[i] = min;
		}
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	index;

	index = 0;
	while (s1[index] != '\0' || s2[index] != '\0')
	{
		if (s1[index] != s2[index])
			return (s1[index] - s2[index]);
		else
			index++;
	}
	return (s1[index] - s2[index]);
}

void	ft_sort_string_tab(char **tab)
{
	int	size;

	size = 0;
	while (tab[size] != 0)
		size++;
	ft_sort_str(tab, size);
}
