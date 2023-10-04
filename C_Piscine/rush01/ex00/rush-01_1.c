/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:21:23 by hchoo             #+#    #+#             */
/*   Updated: 2023/07/30 19:22:31 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	can_field(int field[16], int i, int index, int tmp);

int	ft_left_while(int index, int end, int *field, int count)
{
	int	max;

	max = field[index];
	if (index > end)
	{
		while (index >= end)
		{
			if (max < field[index])
				max = field[index];
			if (max == field[index])
				count--;
			index--;
		}
		return (count);
	}
	while (index < end)
	{
		if (max < field[index])
			max = field[index];
		if (max == field[index])
			count--;
		index++;
	}
	return (count);
}

int	ft_right_while(int index, int end, int *field, int count)
{
	int	max;

	max = field[index];
	if (index > end)
	{
		while (index >= end)
		{
			if (max < field[index])
				max = field[index];
			if (max == field[index])
				count--;
			index = index - 4;
		}
		return (count);
	}
	while (index <= end)
	{
		if (max < field[index])
			max = field[index];
		if (max == field[index])
			count--;
		index = index + 4;
	}
	return (count);
}

int	check_side_row(int *field, int row, int **arr)
{
	if (!ft_left_while(row * 4, row * 4 + 4, field, arr[2][row]))
		return (1);
	if (!ft_left_while(row * 4 + 3, row * 4, field, arr[3][row]))
		return (1);
	return (0);
}

int	check_side_col(int *field, int col, int **arr)
{
	if (!ft_right_while(col, col + 12, field, arr[0][col]))
		return (1);
	if (!ft_right_while(col + 12, col, field, arr[1][col]))
		return (1);
	return (0);
}

void	check_field(int field[16], int index, int **arr, int put)
{
	int	flag;

	if (index >= 16)
		return ;
	while (put <= 4)
	{
		flag = 0;
		printf("%d, %d \n", field[index], index);
		if (field[index + 1] != 0)
			index++;
		else
		{
			field[index + 1] = put;
			if (can_field(field, index + 1, 0, 0) == 1)
				flag++;
			if ((index + 2) / 4 > index + 1 / 4)
				if (check_side_row(field, index / 4, arr) == 1)
					flag++;
			if (flag == 1 && (index + 1) / 4 == index / 4)
				check_field(field, index + 1, arr, 1);
			if (index >= 12)
				if (check_side_col(field, (index - 12), arr) == 1)
					flag++;
			if ((index < 12 && flag == 2) || (index >= 12 && flag == 3))
				check_field(field, index + 1, arr, 1);
			field[index + 1] = 0;
			put++;
		}
	}
}
