/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_iteam.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:11:29 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/11 00:16:53 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref, \
		int (*cmpf)(void *, void *))
{
	if (root == 0)
		return (0);
	else if (cmpf(data_ref, root->item) < 0)
	{
		if (root -> left != 0)
			return (btree_search_item(root->left, data_ref, cmpf));
		else
			return (0);
	}
	else if (cmpf(data_ref, root->item) == 0)
		return (root->item);
	else
	{
		if (root -> right != 0)
			return (btree_search_item(root->right, data_ref, cmpf));
		else
			return (0);
	}
}
