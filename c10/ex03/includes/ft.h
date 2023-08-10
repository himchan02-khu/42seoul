/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 06:21:38 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/07 18:41:17 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <libgen.h>

int		str_len(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_print_memory(void *addr, unsigned int size, int c_x, int count);
void	no_args(int c_x);
int		check_op(char c1, char c2);
void	print_memory(long long iaddr, char *tr, int c_x, unsigned int size);
void	illegal(char *argv, char *input);

#endif
