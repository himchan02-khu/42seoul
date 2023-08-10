/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 23:21:02 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/11 06:49:31 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

t_btree	*btree_create_node(void *item);

int	cmp(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	btree_max_level(t_btree *root)
{
	if (root == 0)
		return (0);
	return (cmp(1 + btree_max_level(root->left), \
			1 + btree_max_level(root->right)));
}

void	btree_level_tf(t_btree *root, int *lev, int *tf, \
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	if (lev[0] < lev[1])
	{
		if (root->left != 0)
		{
			lev[0]++;
			btree_level_tf(root->left, lev, tf, applyf);
			lev[0]--;
			if (*tf == 1 && lev[0] + 1 == lev[1])
				*tf = 0;
		}
		if (root->right != 0)
		{
			lev[0]++;
			btree_level_tf(root->right, lev, tf, applyf);
			lev[0]--;
			if (*tf == 1 && lev[0] + 1 == lev[1])
				*tf = 0;
		}
	}
	else
		if (root->item != 0)
			applyf(root->item, lev[1], *tf);
	return ;
}

void	btree_apply_by_level(t_btree *root, \
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int	now_lev[2];
	int	tf;
	int	depth;

	depth = btree_max_level(root);
	now_lev[0] = 0;
	now_lev[1] = 0;
	while (now_lev[1] < depth)
	{
		tf = 1;
		btree_level_tf(root, now_lev, &tf, applyf);
		now_lev[1]++;
	}
}
