/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 05:25:32 by hchoo             #+#    #+#             */
/*   Updated: 2023/07/31 23:06:22 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else if (c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	check_base(char *base)
{
	int		i;
	int		j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || check_space(base[i]))
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

long long	check_str_in_base(char *str, char *base, int index)
{
	int		i;
	int		tf;

	tf = 1;
	while (tf == 1 && str[index] != '\0')
	{
		i = 0;
		tf = 0;
		while (base[i] != '\0')
		{
			if (str[index] == base[i])
			{
				tf = 1;
				break ;
			}
			else
				i++;
		}
		if (tf == 0)
			index--;
		index++;
	}
	return (index - 1);
}

long long	base_trans(char *str, char *base, long long i_s, long long i_e)
{
	long long	trans_10;
	long long	tmp;
	long long	base_size;
	long long	j;

	base_size = 0;
	trans_10 = 0;
	tmp = 1;
	while (base[base_size] != '\0')
		base_size++;
	while (i_e >= i_s)
	{
		j = 0;
		while (j < base_size)
		{
			if (str[i_e] == base[j])
				trans_10 += j * tmp;
			j++;
		}
		tmp = tmp * base_size;
		i_e--;
	}
	return (trans_10);
}

long long	ft_atoi_base(char *str, char *base)
{
	long long	index;
	long long	sign;
	long long	index_end;
	long long	save_after;

	index = 0;
	sign = 1;
	while (check_space(str[index]))
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
	if (!check_base(base))
		return (0);
	index_end = check_str_in_base(str, base, index);
	save_after = base_trans(str, base, index, index_end);
	return (save_after * sign);
}
