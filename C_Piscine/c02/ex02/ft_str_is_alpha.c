/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:49:32 by hchoo             #+#    #+#             */
/*   Updated: 2023/07/22 20:45:43 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	index;
	int	tf;

	index = 0;
	tf = 1;
	while (str[index] != '\0')
	{
		if (str[index] < 'a' || str[index] > 'z')
			if (str[index] < 'A' || str[index] > 'Z')
				tf = 0;
		index++;
	}
	return (tf);
}	
