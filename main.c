/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 20:32:45 by mzabalza          #+#    #+#             */
/*   Updated: 2017/12/03 04:04:10 by mzabalza         ###   ########.fr       */
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
	char	*line2;
	int		dst;
	
	fd = open(argv[1], O_RDONLY);
	dst = get_next_line(fd, &line);
	printf("str1: %s\n", line);
	dst = get_next_line(fd, &line);
	printf("str1: %s\n", line);
	dst = get_next_line(fd, &line);
	printf("str1: %s\n", line);
	dst = get_next_line(fd, &line);
	printf("str1: %s\n", line);
	dst = get_next_line(fd, &line);
	printf("str1: %s\n", line);
	close(fd);
	return (0);
}
