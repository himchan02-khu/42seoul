/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 04:07:03 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/11 04:16:35 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	list_merge(t_list **begin_list1, t_list *begin_list2)
{
	if ((*begin_list1)->next != NULL)
		ft_list_merge(&((*begin_list1)->next), begin_list2);
	else
		(*begin_list1)->next = begin_list2;
}

t_list	**lists_sort(t_list **begin_list, int (*cmp)())
{
	void	*tmp;
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

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, \
		int (*cmp)())
{
	list_merge(begin_list1, begin_list2);
	begin_list1 = lists_sort(begin_list1, cmp);
}
