/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:17:26 by hchoo             #+#    #+#             */
/*   Updated: 2023/07/27 16:12:22 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_sqrt(int nb)
{
	int	sqrt;

	sqrt = 1;
	while (sqrt < nb / sqrt)
		sqrt++;
	return (sqrt);
}

int	ft_is_prime(int nb)
{
	int	tmp;
	int	max;
	int	tf;

	tmp = 2;
	if (nb <= 1)
		return (0);
	if (nb == 2 || nb == 3)
		return (1);
	max = check_sqrt(nb) + 1;
	tf = 1;
	while (tmp <= max)
	{
		if (nb % tmp == 0)
		{
			tf = 0;
			return (0);
		}
		else
			tmp++;
	}
	if (tf == 1)
		return (1);
	else
		return (0);
}
