/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:03:54 by hchoo             #+#    #+#             */
/*   Updated: 2023/07/22 20:10:57 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	index;
	int	tf;

	index = 0;
	tf = 1;
	while (str[index] != '\0')
	{
		if (str[index] < ' ' || str[index] > '~')
			tf = 0;
		index++;
	}
	return (tf);
}
