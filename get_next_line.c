/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <myerrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:54:21 by myerrou           #+#    #+#             */
/*   Updated: 2023/12/18 21:59:48 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_function(int fd, char *stat)
{
	char	*buf;
	int		bit;

	bit = 1;
	buf = malloc((size_t)BUFFER_SIZE + 1);
	while (!ft_strchr(stat, '\n') && bit != 0)
	{
		bit = read(fd, buf, BUFFER_SIZE);
		if (bit == -1)
		{
			free(buf);
			free(stat);
			return (NULL);
		}
		buf[bit] = '\0';
		stat = ft_strjoin(stat, buf);
	}
	free(buf);
	return (stat);
}

char	*starting_line(char *stat)
{
	char	*tp;
	int		i;

	i = 0;
	if (!stat[i])
		return (NULL);
	while (stat[i] && stat[i] != '\n')
		i++;
	tp = malloc(i + 2);
	if (!tp)
		return (NULL);
	i = 0;
	while (stat[i] && stat[i] != '\n')
	{
		tp[i] = stat[i];
		i++;
	}
	if (stat[i] == '\n')
	{
		tp[i] = stat[i];
		i++;
	}
	tp[i] = '\0';
	return (tp);
}

char	*next_line(char *stat)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (stat[i] && stat[i] != '\n')
		i++;
	if (!stat[i])
	{
		free(stat);
		return (NULL);
	}
	str = malloc(ft_strlen(stat) - i + 1);
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (stat[i])
		str[j++] = stat[i++];
	str[j] = '\0';
	free(stat);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*f_line;
	static char	*statiq;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	statiq = read_function(fd, statiq);
	if (!statiq)
		return (NULL);
	f_line = starting_line(statiq);
	statiq = next_line(statiq);
	return (f_line);
}
