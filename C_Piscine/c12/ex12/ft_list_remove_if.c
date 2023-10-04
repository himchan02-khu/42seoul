/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 00:28:05 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/11 06:07:33 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_list_remove_if(t_list **begin_list, void *data_ref, \
		int (*cmp)(), void (*free_fct)(void *))
{
	struct s_list	*tmp;

	tmp = *begin_list;
	while ((*begin_list) != 0)
	{
		tmp = (*begin_list)->next;
		if (cmp(((*begin_list)->data), data_ref) == 0)
		{
			free_fct((*begin_list)->data);
			free(*begin_list);
		}
		*begin_list = tmp;
	}
}
