/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:21:34 by hchoo             #+#    #+#             */
/*   Updated: 2023/07/30 20:13:52 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	find_1_4(int field[16], int count, int find, int index)
{
	if (find == 1)
	{
		if (count < 4)
			field[count] = 4;
		else if (count >= 4 && count < 8)
			field[12 + count - 4] = 4;
		else if (count >= 8 && count < 12)
			field[(count - 8) * 4] = 4;
		else if (count >= 12 && count < 16)
			field[(count - 12) * 4 + 3] = 4;
		return ;
	}
	index = -1;
	while (++index < 4)
	{
		if (count < 4)
			field[count + (index * 4)] = index + 1;
		else if (count >= 4 && count < 8)
			field[count - 4 + (index * 4)] = 4 - index;
		else if (count >= 8 && count < 12)
			field[(count - 8) * 4 + index] = index + 1;
		else if (count >= 12 && count < 16)
			field[(count - 12) * 4 + index] = 4 - index;
	}
}
#include <stdio.h>
int	can_field(int field[16], int i, int index, int tmp)
{
	int	check_row[4];

	index = -1;
	while (++index < 4)
		check_row[index] = 0;
	index = (i / 4) * 4;
	for (int i = 0 ; i < 16; i++)
	{
		printf("%d ", field[i]);
		if(i % 4 == 3)
			printf("\n");
	}
	printf("\n\n");
	printf("i == %d\n", i);
	while (index++ < (((i / 4) * 4) + 4))
	{
		printf("index - 1 = %d  field[index - 1] == %d\n\n", index - 1, field[index-1]); 
		if (field[index - 1] == 0)
			break ;
		if (check_row[field[index - 1] % 4] == 0)
		{
			check_row[field[index - 1] % 4] = 1;
			printf("check_row\n");
		}
		else
			return (0);
	}
	index = -1;
	printf("$$break row$$\n");
	while (++index < 4)
		check_row[index] = 0;
	index = -1;
	while (++index < 4)
	{
		tmp = field[i % 4 + 4 * index];
		if (tmp == 0)
			break ;
		if (check_row[tmp - 1] == 0)
			check_row[tmp - 1] = 1;
		else
			return (0);
	}
	return (1);
}
