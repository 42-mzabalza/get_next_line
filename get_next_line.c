/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 20:30:47 by mzabalza          #+#    #+#             */
/*   Updated: 2017/11/29 21:01:12 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"


int		get_next_line(const int fd, char **line)
{
	char buff;

	while (read(fd, &buff, 1))
		write(1, &buff, 1);
	return (1);
}

