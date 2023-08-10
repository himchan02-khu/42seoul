/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:25:55 by hchoo             #+#    #+#             */
/*   Updated: 2023/07/29 19:32:48 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	can_queen(char *str, int line)
{
	int	index;

	index = 0;
	while (index < line)
	{
		if (str[line] == str[index])
			return (-1);
		if (str[line] + line == str[index] + index)
			return (-1);
		if (str[line] - line == str[index] - index)
			return (-1);
		index++;
	}
	return (1);
}

int	check_queen(char *str, int line)
{
	int	index;
	int	count;

	if (can_queen(str, line) == -1 && line > 0)
		return (0);
	count = 0;
	index = 0;
	if (line >= 9)
	{
		write(1, str, 10);
		write(1, "\n", 1);
		return (1);
	}
	while (index < 10)
	{
		str[line + 1] = index + '0';
		if (can_queen(str, line + 1) == 1)
			count += check_queen(str, line + 1);
		index++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	char	str[10];
	int		index;
	int		count;

	index = -1;
	while (++index < 10)
		str[index] = '-';
	str[0] = index + '0';
	count = 0;
	count += check_queen(str, -1);
	return (count);
}
