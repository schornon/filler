/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:56:16 by schornon          #+#    #+#             */
/*   Updated: 2019/02/25 16:21:52 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "get_next_line.h"

int		ft_aftern(char *buffer)
{
	int				i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			break ;
		i++;
	}
	i++;
	return (i);
}

void	ft_joindell(char *buffer, char **line)
{
	char			*t;

	t = *line;
	*line = ft_strjoin_f(*line, buffer);
}

int		ft_crtline(int fd, char **line, char *buffer, char **statbuff)
{
	if (ft_strchr(buffer, '\n'))
	{
		free(statbuff[fd]);
		statbuff[fd] = ft_strnew(BUFF_SIZE - ft_aftern(buffer) + 2);
		if (statbuff[fd] == NULL)
			return (-1);
		statbuff[fd] = ft_strcpy(statbuff[fd], &buffer[ft_aftern(buffer)]);
		buffer[ft_aftern(buffer) - 1] = 0;
		ft_joindell(buffer, line);
		return (1);
	}
	ft_joindell(buffer, line);
	return (0);
}

int		ft_checkstatic(char **statbuff, int fd, char **line)
{
	int				i;

	*line = NULL;
	if (statbuff[fd] != NULL)
	{
		if (ft_strchr(statbuff[fd], '\n'))
		{
			i = ft_aftern(statbuff[fd]);
			statbuff[fd][i - 1] = 0;
			ft_joindell(statbuff[fd], line);
			statbuff[fd] = ft_strcpy(statbuff[fd], &statbuff[fd][i]);
			return (1);
		}
		if (statbuff[fd][0] != 0)
		{
			ft_joindell(statbuff[fd], line);
			ft_strdel(&statbuff[fd]);
		}
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int				b;
	char			buffer[BUFF_SIZE + 1];
	int				res;
	static char		**statbuff = NULL;

	if (BUFF_SIZE > 0 && line && fd > -1 && fd <= OPEN_MAX)
	{
		if (statbuff == NULL)
			DOUBLECH((statbuff = (char**)malloc(sizeof(char*) * OPEN_MAX)));
		CHECKSTAT(ft_checkstatic(statbuff, fd, line));
		b = read(fd, buffer, BUFF_SIZE);
		BYTESERROR(b);
		CHK1(*line, b);
		CHK2(*line, b);
		while (b >= 1)
		{
			buffer[b] = 0;
			res = ft_crtline(fd, line, buffer, statbuff);
			CHECKRESULT(res);
			b = read(fd, buffer, BUFF_SIZE);
			ZEROBYTES(b);
		}
		return (1);
	}
	return (-1);
}
