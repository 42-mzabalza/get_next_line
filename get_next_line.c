/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 20:30:47 by mzabalza          #+#    #+#             */
/*   Updated: 2017/12/03 04:10:14 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"

int		ft_line_len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return(i);
}

char	*ft_make_line(char *chaume, char *buff, char **line)
{
	char	**split;
	char	*tmp;
	
	if (!chaume)
	{
		ft_putchar('u');
		chaume = ft_strdup(buff);
		ft_putstr(chaume);
	}
	else
	{
		if (!ft_strchr(chaume, '\n'))
		{
			ft_putchar('b');
			tmp = ft_strsub(buff, 0, BUFF_SIZE);
			chaume = ft_strjoin(chaume, tmp);
		}
	}
	if (!ft_strchr(chaume, '\n'))
		return (chaume);
	ft_putchar('c');
	ft_putstr(chaume);
	ft_putnbr(ft_line_len(chaume));
	*line = ft_strsub(chaume, 0, ft_line_len(chaume));
	ft_putchar('z');
	ft_putstr(*line);
	chaume = ft_strchr(chaume, '\n');
	chaume++;
	return (chaume);
}

int		get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE];
	static char	*chaume = NULL;
	
	ft_putchar('a');
	*line = NULL;
	ft_memset(buff, 0, BUFF_SIZE + 1);
	if (chaume)
	{
		if (ft_strchr(chaume, '\n'))
		{
			ft_putchar('a');
			chaume = ft_make_line(chaume, buff, line);
			return (1);
		}
	}
	while (read(fd, buff, BUFF_SIZE) > 0)
	{
		if (!(ft_strchr(buff, '\n')))
			chaume = ft_make_line(chaume, buff, line);
		else
		{
			chaume = ft_make_line(chaume, buff, line);
			return(1);
		}
	}
	return (0);
}

