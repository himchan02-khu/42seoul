/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:48:23 by hchoo             #+#    #+#             */
/*   Updated: 2023/07/26 11:10:52 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	index;

	index = 0;
	argc = 1;
	if (*argv[0] != '\0')
	{	
		while (argv[0][index] != '\0')
		{
			write(1, &argv[0][index], 1);
			index++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
