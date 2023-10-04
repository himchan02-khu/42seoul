/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:58:11 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/04 21:24:30 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putnbr(int nb);

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

int	find_operator(char *str)
{
	if (str[0] == '+')
		return (1);
	else if (str[0] == '-')
		return (2);
	else if (str[0] == '/')
		return (3);
	else if (str[0] == '*')
		return (4);
	else if (str[0] == '%')
		return (5);
	return (0);
}

int	cal_save(int save1, int save2, int operator)
{
	if (operator == 0)
		return (0);
	else if (operator == 1)
		return (save1 + save2);
	else if (operator == 2)
		return (save1 - save2);
	else if (operator == 3 && save2 != 0)
		return (save1 / save2);
	else if (operator == 4)
		return (save1 * save2);
	else if (operator == 5 && save2 != 0)
		return (save1 % save2);
	else if (save2 == 0 && (operator == 3 || operator == 5))
		return (0);
	return (0);
}

int	main(int argc, char **argv)
{
	int	save_1;
	int	save_2;
	int	operator;

	if (argc != 4)
		return (0);
	save_1 = ft_atoi(argv[1]);
	operator = find_operator(argv[2]);
	save_2 = ft_atoi(argv[3]);
	save_1 = cal_save(save_1, save_2, operator);
	if (save_2 == 0 && (operator == 3 || operator == 5))
	{
		if (operator == 3)
			write(1, "Stop : division by zero\n", 24);
		if (operator == 5)
			write(1, "Stop : modulo by zero\n", 22);
	}
	else
		ft_putnbr(save_1);
	return (0);
}
