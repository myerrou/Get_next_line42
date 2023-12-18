/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <myerrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:54:54 by myerrou           #+#    #+#             */
/*   Updated: 2023/12/18 15:53:43 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	unsigned int	i;
	char			*cf_src;
	char			*cf_dst;

	i = 0;
	cf_src = (char *)src;
	cf_dst = (char *)dst;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (cf_dst == cf_src)
		return (cf_dst);
	while (i < n)
	{
		cf_dst[i] = cf_src[i];
		i++;
	}
	return (dst);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
	s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(char *str)
{
	char	*s;
	size_t	len;
	size_t	i;

	len = ft_strlen(str) + 1;
	i = 0;
	s = malloc (len);
	if (!s || !str)
		return (0);
	ft_memcpy (s, str, len);
	return (s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2);
	res = (malloc(len * (sizeof (*res)) + 1));
	if (!res)
		return (NULL);
	while (s1[j])
		res[i++] = s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = 0;
	free (s1);
	return (res);
}
