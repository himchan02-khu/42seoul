/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 00:41:39 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/11 02:47:55 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_list_sort(t_list **begin_list, int (*cmp)())
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
}
