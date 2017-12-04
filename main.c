/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 20:32:45 by mzabalza          #+#    #+#             */
/*   Updated: 2017/12/04 19:05:22 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		dst;

	argc = 2;	
	fd = open(argv[1], O_RDONLY);
	dst = get_next_line(fd, &line);
	printf("str1: %s\n", line);
	printf("dst: %i\n", dst);
	dst = get_next_line(fd, &line);
	printf("str1: %s\n", line);
	printf("dst: %i\n", dst);
	dst = get_next_line(fd, &line);
	printf("str1: %s\n", line);
	dst = get_next_line(fd, &line);
	printf("str1: %s\n", line);
	dst = get_next_line(fd, &line);
	printf("str1: %s\n", line);
	printf("dst: %i\n", dst);
	dst = get_next_line(fd, &line);
	printf("str1: %s\n", line);
	printf("dst: %i\n", dst);
	close(fd);
	return (0);
}
