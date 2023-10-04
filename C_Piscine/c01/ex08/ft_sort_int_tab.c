/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:16:04 by hchoo             #+#    #+#             */
/*   Updated: 2023/07/23 14:47:33 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	min;
	int	index;
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		index = i;
		while (j < size)
		{
			if (tab[index] > tab[j])
				index = j;
			j++;
		}
		if (index != i)
		{
			min = tab[index];
			tab[index] = tab[i];
			tab[i] = min;
		}
		i++;
	}
}
