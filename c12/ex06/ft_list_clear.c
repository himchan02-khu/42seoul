/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 06:53:15 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/09 16:53:37 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	struct s_list	*elem;

	while (begin_list != NULL)
	{
		elem = begin_list;
		free_fct(begin_list->data);
		begin_list = begin_list->next;
		free(elem);
	}
}
