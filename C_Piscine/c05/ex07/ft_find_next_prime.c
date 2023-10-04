/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_nex_prime.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:23:04 by hchoo             #+#    #+#             */
/*   Updated: 2023/07/27 16:36:34 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	sqrt_check(int nb)
{
	int	sqrt;

	sqrt = 1;
	while (sqrt < nb / sqrt)
		sqrt++;
	return (sqrt);
}

int	ft_find_next_prime(int nb)
{
	int	tmp;
	int	max;
	int	tf;

	max = sqrt_check(nb) + 1;
	tmp = 2;
	tf = 1;
	if (nb <= 2)
		return (2);
	else if (nb == 3)
		return (3);
	while (tmp <= max)
	{
		if (nb % tmp == 0)
		{
			return (ft_find_next_prime(nb + 1));
		}
		else
			tmp++;
	}
	return (nb);
}
