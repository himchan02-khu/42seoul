/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:30:43 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/11 03:55:33 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item);

void	btree_insert_data(t_btree **root, void *item, \
		int (*cmpf)(void *, void *))
{
	struct s_btree	*elem;

	elem = btree_create_node(item);
	if ((*root) == 0)
		*root = elem;
	else if (cmpf(elem->item, (*root)->item) < 0)
	{
		if ((*root)->left != 0)
			btree_insert_data(&((*root)->left), item, cmpf);
		else
			(*root)->left = elem;
	}
	else
	{
		if ((*root)->right != 0)
			btree_insert_data(&((*root)->right), item, cmpf);
		else
			(*root)->right = elem;
	}
}
