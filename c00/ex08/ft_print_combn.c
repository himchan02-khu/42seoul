/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:04:06 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/09 22:03:22 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print(char *arr, int n)
{
	int	index;

	index = 0;
	while (index < n)
	{
		write(1, &arr[index], 1);
		index++;
	}
	if (arr[0] != '9' - n + 1)
		write(1, ", ", 2);
}

int	check_max(char *arr, int index, int n)
{
	if (arr[index] == '9' - n + index + 1)
		return (check_max(arr, index - 1, n));
	else
		return (index + 1);
}

void	ft_print_combn(int n)
{
	char	arr[10];
	int		index;

	index = -1;
	while (++index < n)
		arr[index] = index + '0';
	index = 0;
	while (arr[0] <= '9' - n)
	{
		ft_print(arr, n);
		if (arr[n - 1] == '9')
			index = check_max(arr, n - 1, n);
		if (index > 0)
			arr[index - 1]++;
		while (index < n && index > 0)
		{
			arr[index] = arr[index - 1] + 1;
			index++;
		}
		if (index != n)
			arr[n - 1]++;
		index = 0;
	}
	ft_print(arr, n);
}
