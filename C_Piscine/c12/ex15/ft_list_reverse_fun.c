/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 05:54:51 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/11 07:37:41 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_list	*reverse_list_return(t_list *begin_list)
{
	struct s_list	*prev;
	struct s_list	*current;
	struct s_list	*next;

	prev = NULL;
	current = begin_list;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return (prev);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	struct s_list	*end_list;
	struct s_list	*tmp_begin;
	struct s_list	*tmp_end;

	end_list = reverse_list_return(begin_list);
	tmp_begin = begin_list;
	tmp_end = end_list;
	while (tmp_end != tmp_begin || end_list != tmp_begin)
	{
		begin_list = tmp_begin;
		end_list = tmp_end;
		tmp_begin = tmp_begin->next;
		tmp_end = tmp_end->next;
	}
}
