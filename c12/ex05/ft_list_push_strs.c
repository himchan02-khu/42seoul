/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 04:25:57 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/09 16:17:55 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list	*ft_list_push_strs(int size, char **strs)
{
	struct s_list	*list;
	struct s_list	*elem;
	int				i;

	i = 1;
	list = ft_create_elem(strs[0]);
	while (i < size)
	{
		elem = ft_create_elem(strs[i]);
		elem -> next = list;
		list = elem;
		i++;
	}
	return (list);
}
