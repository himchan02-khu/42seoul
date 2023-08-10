/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:21:31 by hchoo             #+#    #+#             */
/*   Updated: 2023/07/30 18:50:29 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	find_1_4(int field[16], int count, int find, int index);
int	can_field(int field[16], int i, int index, int tmp);
int	check_field(int field[16], int index, int **arr, int put);
int	check_side_row(int *field, int row, int **arr);
int	check_side_col(int *field, int col, int **arr);
int	ft_right_while(int index, int end, int *field, int count);
int	ft_left_while(int index, int end, int *field, int count);

void	setting(char *argv, int **arr, int field[16])
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (argv[index] != '\0')
	{
		if (argv[index] == ' ')
			index++;
		else
		{
			if (count < 4)
				arr[0][count] = argv[index] - '0';
			else if (count >= 4 && count < 8)
				arr[1][count - 4] = argv[index] - '0';
			else if (count >= 8 && count < 12)
				arr[2][count - 8] = argv[index] - '0';
			else if (count >= 12 && count < 16)
				arr[3][count - 12] = argv[index] - '0';
			if (argv[index] == '4' || argv[index] == '1')
				find_1_4(field, count, argv[index] - '0', 0);
			index++;
			count++;
		}
	}
}

void	clear(int field[16])
{
	int	i;

	i = 0;
	while (i < 16)
	{
		field[i] = 0;
		i++;
	}
}

void	print_arr(int **arr)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = '0' + arr[i][j];
			write(1, &c, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	print_field(int field[16])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = '0' + field[4 * i + j];
			write(1, &c, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	field[16];
	int	**arr;

	if (argc < 2)
	{
		write(1, "Error", 5);
		return (0);
	}
	arr = (int **)malloc(sizeof(int *) * 4);
	arr[0] = (int *)malloc(sizeof(int) * 4);
	arr[1] = (int *)malloc(sizeof(int) * 4);
	arr[2] = (int *)malloc(sizeof(int) * 4);
	arr[3] = (int *)malloc(sizeof(int) * 4);
	clear(field);
	setting(argv[1], arr, field);
	check_field(field, -1, arr, 1);
	print_field(field);
}
