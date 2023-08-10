/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:54:43 by hchoo             #+#    #+#             */
/*   Updated: 2023/07/24 21:08:39 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_word(char c)
{
	if (c <= 'z' && c >= 'a')
		return (1);
	else if (c <= 'Z' && c >= 'A')
		return (1);
	else if (c <= '9' && c >= '0')
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	index;
	int	tf;

	index = 0;
	tf = 0;
	while (str[index] != '\0')
	{
		if (tf == 0)
		{
			if (str[index] <= 'z' && str[index] >= 'a')
			{
				str[index] = str[index] - 32;
				tf = 1;
			}
		}
		else
			if (str[index] <= 'Z' && str[index] >= 'A')
				str[index] = str[index] + 32;
		tf = check_word(str[index]);
		index++;
	}
	return (str);
}
