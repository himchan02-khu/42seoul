/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:03:40 by hchoo             #+#    #+#             */
/*   Updated: 2023/07/26 11:04:09 by hchoo            ###   ########.fr       */
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

	i = 1;
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
	while (s1[index] != '\0' && s2[index] != '\0')
	{
		if (s1[index] != s2[index])
			return (s1[index] - s2[index]);
		else
			index++;
	}
	if (s1[index] != '\0' && s2[index] == '\0')
		return (s1[index]);
	else if (s1[index] == '\0' && s2[index] != '\0')
		return (-1 * s2[index]);
	else
		return (0);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	ft_sort_str(argv, argc);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
