/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 06:24:20 by hchoo             #+#    #+#             */
/*   Updated: 2023/07/26 06:43:50 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	save;

	save = nb;
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else
		save *= ft_recursive_power(nb, power - 1);
	return (save);
}
