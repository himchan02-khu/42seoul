/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 00:21:10 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/11 06:06:26 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), \
		void *data_ref, int (*cmp)())
{
	if (cmp(begin_list->data, data_ref) == 0 && begin_list != 0)
	{
		f(begin_list->data);
		ft_list_foreach_if(begin_list->next, f, data_ref, cmp);
	}
	else if (begin_list != 0)
		ft_list_foreach_if(begin_list->next, f, data_ref, cmp);
	else
		return ;
}
