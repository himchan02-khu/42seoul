/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:54:01 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/09 14:34:50 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	struct s_list	*list;

	list = malloc(sizeof(t_list));
	list->next = NULL;
	list->data = data;
	return (list);
}
