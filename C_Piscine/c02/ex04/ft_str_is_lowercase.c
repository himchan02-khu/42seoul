/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:55:13 by hchoo             #+#    #+#             */
/*   Updated: 2023/07/22 20:03:20 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	index;
	int	tf;

	index = 0;
	tf = 1;
	while (str[index] != '\0')
	{
		if (str[index] < 'a' || str[index] > 'z')
			tf = 0;
		index++;
	}
	return (tf);
}
