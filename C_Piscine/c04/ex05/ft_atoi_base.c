/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:28:24 by hchoo             #+#    #+#             */
/*   Updated: 2023/07/26 16:41:31 by hchoo            ###   ########.fr       */
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

int	check_str_in_base(char *str, char *base, int index)
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

int	base_trans(char *str, char *base, int index_start, int index_end)
{
	int	trans_10;
	int	tmp;
	int	base_size;
	int	j;

	base_size = 0;
	trans_10 = 0;
	tmp = 1;
	while (base[base_size] != '\0')
		base_size++;
	while (index_end >= index_start)
	{
		j = 0;
		while (j < base_size)
		{
			if (str[index_end] == base[j])
				trans_10 += j * tmp;
			j++;
		}
		tmp = tmp * base_size;
		index_end--;
	}
	return (trans_10);
}

int	ft_atoi_base(char *str, char *base)
{
	int	index;
	int	sign;
	int	index_end;
	int	save_after;

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
	if (!check_str_in_base(str, base, index) || !check_base(base))
		return (0);
	index_end = check_str_in_base(str, base, index);
	save_after = base_trans(str, base, index, index_end);
	return (save_after * sign);
}
