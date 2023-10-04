/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:45:51 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/03 20:08:50 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	index;
	int	tf1;
	int	tf2;

	index = 0;
	tf1 = 1;
	tf2 = 1;
	while (index + 1 < length)
	{
		if (f(tab[index], tab[index + 1]) > 0)
			tf1 = 0;
		if (f(tab[index], tab[index + 1]) < 0)
			tf2 = 0;
		index++;
	}
	if (tf1 == 1 || tf2 == 1)
		return (1);
	return (0);
}
