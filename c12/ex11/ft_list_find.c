/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 00:24:32 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/11 06:06:47 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	if (cmp(begin_list->data, data_ref) == 0)
		return (begin_list);
	else
		return (ft_list_find(begin_list->next, data_ref, cmp));
}
