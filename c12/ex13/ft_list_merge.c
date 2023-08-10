/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 00:39:40 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/11 06:04:45 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	if ((*begin_list1)->next != NULL)
		ft_list_merge(&((*begin_list1)->next), begin_list2);
	else
	{
		while (begin_list2 != NULL)
		{
			(*begin_list1)->next = begin_list2;
			*begin_list1 = (*begin_list1)->next;
			begin_list2 = begin_list2->next;
		}
	}
}
