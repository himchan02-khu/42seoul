/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   original_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:04:22 by hchoo             #+#    #+#             */
/*   Updated: 2023/10/04 21:23:04 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(char c)
{
	if (c <= 'z' && c >= 'a')
		return (2);
	else if (c <= 'Z' && c >= 'A')
		return (1);
	else
		return (0);
}

int	ft_isdigit(char c)
{
	if (c <= '9' && c >= '0')
		return (4);
	else
		return (0);
}

int	ft_isalnum(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	else if (c <= 'z' && c >= 'a')
		return (1);
	else if (c <= 'Z' && c >= 'A')
		return (1);
	else
		return (0);
}

int	ft_isascii(int c)
{
	if (c <= 127 && c >= 0)
		return (1);
	else
		return (0);
}

int	ft_isprint(int c)
{
	if (c <= 127 && c >= 32)
		return (1);
	else
		return (0);
}
