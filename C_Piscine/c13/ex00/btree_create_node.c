/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 05:16:37 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/10 20:39:42 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_btree	*btree_create_node(void *item)
{
	struct s_btree	*new_btree;

	new_btree = malloc(sizeof(t_btree));
	new_btree->left = NULL;
	new_btree->right = NULL;
	new_btree->item = item;
	return (new_btree);
}
