/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:53:06 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/09 17:39:36 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	print_file(char *filename)
{
	int		fd;
	int		len;
	int		i;
	char	buf[1024];

	i = 0;
	fd = open(filename, O_RDONLY);
	len = 1;
	if (fd == -1)
	{
		write(2, "Cannot read file.\n", 18);
		return ;
	}
	while (len != 0)
	{
		len = read(fd, buf, 1024);
		write(1, &buf[i], len);
	}
	close(fd);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write (2, "Too many arguments.\n", 20);
	else
		print_file(argv[1]);
	return (0);
}
