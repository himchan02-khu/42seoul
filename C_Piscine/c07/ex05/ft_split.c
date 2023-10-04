/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 01:45:00 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/01 03:01:57 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	check_base(char c, char *base)
{
	int	index;

	index = 0;
	while (base[index] != '\0')
	{
		if (c == base[index])
			return (1);
		index++;
	}
	return (0);
}

int	count_word(char *str, char *base)
{
	int	tf;
	int	index;
	int	count;

	count = 0;
	index = 0;
	tf = 1;
	while (str[index] != '\0')
	{
		if (check_base(str[index], base) == 0 && tf == 1)
		{
			count++;
			tf = 0;
		}
		else if (check_base(str[index], base) == 1 && tf == 0)
			tf = 1;
		index++;
	}
	return (count);
}

int	find_index(char *str, char *base, int x_index, int s_e)
{
	int	index;

	index = 0;
	if (s_e == 1)
	{
		while (str[x_index + index] != '\0')
		{
			if (check_base(str[x_index + index], base) == 1)
				index++;
			else
				break ;
		}
		return (x_index + index);
	}
	else
	{
		while (str[x_index + index] != '\0')
		{
			if (check_base(str[x_index + index], base) == 0)
				index++;
			else
				break ;
		}
		return (x_index + index);
	}
}

char	*add_strs(int index_start, int index_end, char *strs, char *str)
{
	int	tmp_str;

	tmp_str = 0;
	while (tmp_str < index_end - index_start)
	{
		strs[tmp_str] = str[tmp_str + index_start];
		tmp_str++;
	}
	strs[tmp_str] = 0;
	return (strs);
}

char	**ft_split(char *str, char *charset)
{
	char	**str_return;
	int		tmp;
	int		max;
	int		index;
	int		row;

	row = 0;
	max = count_word(str, charset);
	str_return = (char **)malloc(sizeof(char *) * max + 1);
	tmp = 0;
	while (row < max)
	{
		index = find_index(str, charset, tmp, 1);
		tmp = find_index(str, charset, index, 0);
		str_return[row] = (char *)malloc(sizeof(char) * (tmp - index + 1));
		str_return[row] = add_strs(index, tmp, str_return[row], str);
		row++;
	}
	str_return[row] = 0;
	return (str_return);
}
