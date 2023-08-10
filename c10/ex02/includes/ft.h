/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 06:21:38 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/08 00:39:43 by hchoo            ###   ########.fr       */
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
void	no_args(int max, int bufsize);
void	illegal(char *argv, char *input);
int		print_header(int argc, char *argv[], int i, int tf);

#endif
