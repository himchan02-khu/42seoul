/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 03:59:40 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/11 07:34:59 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data);

void	list_push_front(t_list **begin_list, void *data)
{
	struct s_list	*list;

	list = ft_create_elem(data);
	list->next = *begin_list;
	*begin_list = list;
}

t_list	**list_sort(t_list **begin_list, int (*cmp)())
{
	void			*tmp;
	struct s_list	*list_tmp;

	while ((*begin_list)->next != 0)
	{
		list_tmp = *begin_list;
		while ((list_tmp)->next != 0)
		{
			if (cmp((list_tmp)->data, (list_tmp)->next->data) > 0)
			{
				tmp = (*begin_list)->data;
				(*begin_list)->data = (*begin_list)->next->data;
				(*begin_list)->next->data = tmp;
			}
			list_tmp = list_tmp->next;
		}
		(*begin_list) = (*begin_list)->next;
	}
	return (begin_list);
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	list_push_front(begin_list, data);
	begin_list = list_sort(begin_list, cmp);
}
