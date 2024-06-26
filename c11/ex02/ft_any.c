/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:54:03 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/03 17:47:32 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char*))
{
	int	index;

	index = 0;
	while (tab[index] != 0)
	{
		if (f(tab[index]) != 0)
			return (1);
		index++;
	}
	return (0);
}
