/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:02:23 by hchoo             #+#    #+#             */
/*   Updated: 2023/07/22 13:03:35 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	index;
	int	tf;

	index = 0;
	tf = 1;
	while (str[index] != '\0')
	{
		if (str[index] < 'A' || str[index] > 'Z')
			tf = 0;
		index++;
	}
	return (tf);
}
