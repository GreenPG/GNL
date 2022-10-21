/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:32:41 by gpasquet          #+#    #+#             */
/*   Updated: 2022/10/21 16:15:38 by gpasquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmenb, long int size)
{
	void	*ptr;
	int		i;
	int		len;
	char	*s;

	if (nmenb > 2147483648 || size > 2147483648)
		return (0);
	ptr = malloc(nmenb * size);
	if (!ptr)
		return (0);
	s = ptr;
	len = nmenb * size;
	i = 0;
	while (len > i)
	{
		s[i] = '\0';
		i++;
	}
	ptr = s;
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_strjoin_cat(char *dst, const char *src, size_t len, size_t dst_end)
{
	int	j;

	j = 0;
	while (src[j] && (dst_end + j) < len)
	{
		dst[dst_end + j] = src[j];
		j++;
	}
	dst[dst_end + j] = '\0';
}

char	*ft_strjoin(char *s1, char const *s2, int len)
{
	char	*new_s;
	int		i;

	if (s1 == 0 || s2 == 0)
		return (0);
	new_s = malloc(sizeof(char) * (len + 1));
	if (!new_s)
		return (0);
	i = 0;
	while (s1[i])
	{
		new_s[i] = s1[i];
		i++;
	}
	ft_strjoin_cat(new_s, s2, len, i);
	free(s1);
	return (new_s);
}

void	clean_filled_buffer(char *buf, int buf_pos)
{
	int			j;

	j = 0;
	if (buf[buf_pos] == '\n')
		buf_pos++;
	if (buf[buf_pos] == '\0' && buf_pos < (BUFFER_SIZE - 1))
		buf_pos = 0;
	while (buf[j + buf_pos])
	{
		buf[j] = buf[buf_pos + j];
		j++;
	}
	while (buf[j])
	{
		buf[j] = '\0';
		j++;
	}
	buf[j] = '\0';
}
