/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:04:29 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/03 17:47:41 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	count;
	int	index;

	index = 0;
	count = 0;
	while (index < length)
	{
		if (f(tab[index]) != 0)
			count++;
		index++;
	}
	return (count);
}
