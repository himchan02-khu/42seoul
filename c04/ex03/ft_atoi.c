/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:10:48 by hchoo             #+#    #+#             */
/*   Updated: 2023/07/24 18:26:23 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	save_cal(char *str, int index)
{
	int	save;

	save = 0;
	while (str[index] >= '0' && str[index] <= '9')
	{
		save = save * 10 + (str[index] - 48);
		index++;
	}
	return (save);
}

int	ft_atoi(char *str)
{
	int	index;
	int	sign;
	int	save;

	index = 0;
	sign = 1;
	while (str[index] <= ' ')
		index++;
	while (str[index] != '\0')
	{
		if (str[index] == '+')
			sign *= 1;
		else if (str[index] == '-')
			sign *= -1;
		else
			break ;
		index++;
	}
	save = save_cal(str, index);
	return (save * sign);
}
