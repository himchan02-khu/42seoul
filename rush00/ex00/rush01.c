/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rushOX.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeohwan <hyeohwan@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:38:06 by hyeohwan          #+#    #+#             */
/*   Updated: 2023/07/22 15:08:59 by hyeohwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_if(int i, int j, int x, int y)
{
	if (i == 0 && j == 0)
		ft_putchar('/');
	else if (i == 0 && j == y - 1)
		ft_putchar('\\');
	else if (i == x - 1 && j == 0)
		ft_putchar('\\');
	else if (i == x - 1 && j == y - 1)
		ft_putchar('/');
	else if (i == 0 || i == x - 1 || j == 0 || j == y - 1)
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	j = 0;
	if (x <= 0 || y <= 0)
		write (1, "error", 5);
	while (j < y && x > 0)
	{
		i = 0;
		while (i < x)
		{
			ft_if(i, j, x, y);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}
