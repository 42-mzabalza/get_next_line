/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 20:30:47 by mzabalza          #+#    #+#             */
/*   Updated: 2017/12/04 19:02:19 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
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

int		ft_findchar(char *str, char a, int len)
{
	int i;

	i = 0;
	while (len-- > 0)
	{
		if (str[i] == a)
			return (1);
	}
	return (0);
}
char	*ft_make_line(char *chaume, char *buff, char **line)
{
	char	*tmp;

	if (!chaume)
	{
		chaume = ft_strdup(buff);
	}
	else
	{
		if (!ft_strchr(chaume, '\n'))
		{
			tmp = ft_strdup(buff);
			chaume = ft_strjoin(chaume, tmp);
		}
	}
	if (!ft_strchr(chaume, '\n'))
	{
		return (chaume);
	}
	*line = ft_strsub(chaume, 0, ft_line_len(chaume));
	chaume = ft_strchr(chaume, '\n');
	chaume++;
	/*
	if (ft_findchar(buff, 0, BUFF_SIZE))
	{
		ft_putchar('m');
		free(chaume);
	}
	*/
	ft_memset(buff, 0, BUFF_SIZE + 1);
	return (chaume);
}

int		get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*chaume = NULL;
	int			i;
	
	if (fd < 0)
		return (-1);
	*line = NULL;
	ft_memset(buff, 0, BUFF_SIZE + 1);
	if (chaume && ft_strchr(chaume, '\n'))
	{
		chaume = ft_make_line(chaume, buff, line);
		return (1);
	}
	while ((i = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (!(ft_strchr(buff, '\n')))
		{
			chaume = ft_make_line(chaume, buff, line);
			if (i < BUFF_SIZE)
			{
				*line = chaume; 
				return (1);
			}
		}
		else 
		{
			chaume = ft_make_line(chaume, buff, line);

			return (1);
		}
	}
	if (i == 0 && chaume && (!(ft_strchr(chaume, '\n'))))
	{
		ft_putchar('z');
		ft_putstr(chaume);
		*line = ft_strdup(chaume);
		chaume = NULL;
		return (1);
	}
	return (0);
}

