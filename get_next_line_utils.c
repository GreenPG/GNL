/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:32:41 by gpasquet          #+#    #+#             */
/*   Updated: 2022/10/14 12:15:58 by gpasquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    *ft_calloc(size_t nmenb, size_t size)
{
	void    *ptr;
	int     len;

	if (nmenb > 2147483648 || size > 2147483648)
		return (0);
	ptr = malloc(nmenb * size);
	if (!ptr)
		return (0);
	len = nmenb * size;
	ft_memset(ptr, 0, len);
	return (ptr);
}

void    *ft_memset(void *s, int c, size_t n)
{
	char    *str;
	size_t  i;

	str = s;
	i = 0;
	while (n > i)
	{
		str[i] = (char)c;
		i++;
	}
	s = str;
	return (s);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	int		len;
	int		i;
	char	*new_s;

	len = ft_strlen(s);
	new_s = malloc(sizeof(char) * (len + 1));
	if (new_s == 0)
		return (0);
	i = 0;
	while (s[i])
	{
		new_s[i] = s[i];
		i++;
	}
	new_s[i] = 0;
	return (new_s);
}

