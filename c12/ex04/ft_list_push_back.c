/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 04:23:27 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/09 16:52:06 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_list_push_back(t_list **begin_list, void *data)
{
	struct s_list	*list;
	struct s_list	*elem;

	list = ft_create_elem(data);
	if (*begin_list == NULL)
		*begin_list = list;
	else
	{
		elem = *begin_list;
		while (elem->next != NULL)
		{
			elem = elem->next;
		}
		elem->next = list;
	}
}
