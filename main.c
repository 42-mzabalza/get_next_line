/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 20:32:45 by mzabalza          #+#    #+#             */
/*   Updated: 2017/11/29 21:01:10 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"


int		main(int argc, char **argv)
{
	int		fd;
	char	**line;
	int		dst;
	
	line = argv;
	fd = open(argv[1], O_RDONLY);
	dst = get_next_line(fd, line);
	return (0);
}
