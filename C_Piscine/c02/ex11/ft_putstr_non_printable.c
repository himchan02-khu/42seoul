/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 19:27:03 by hchoo             #+#    #+#             */
/*   Updated: 2023/07/23 17:34:17 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int				index;
	char			*tr;
	unsigned char	a;
	char			c;
	int				tmp;

	index = 0;
	tr = "0123456789abcdef";
	while (str[index] != '\0')
	{
		if (str[index] < ' ' || str[index] > '~')
		{
			write (1, "\\", 1);
			a = str[index];
			tmp = a / 16;
			c = tr[tmp];
			write (1, &c, 1);
			tmp = a % 16;
			c = tr[tmp];
			write (1, &c, 1);
		}
		else
			write (1, &str[index], 1);
		index++;
	}
}
