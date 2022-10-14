/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:44:24 by gpasquet          #+#    #+#             */
/*   Updated: 2022/10/14 16:27:20 by gpasquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*copy_buf_size(int fd, char *buf)
{
	char		*new_buf;
	int			readed_bytes;
	int			old_buf_len;
	int			i;
	int			boo;

	old_buf_len = ft_strlen(buf);
	readed_bytes = 0;	
	while(readed_bytes < old_buf_len)
		readed_bytes += read(fd, buf, BUFFER_SIZE);
	boo = 0;
	new_buf = buf;
	while (boo == 0)
	{			
		i = 0;
		readed_bytes = read(fd, new_buf, BUFFER_SIZE);
		while (new_buf[i] && new_buf[i] != '\n')
				i++;
		if (buf[i] == '\n' || readed_bytes == 0)
			boo++;
		new_buf++;
	} 
	return (buf);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*buf;

	buf = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!buf)
		return (NULL);
	buf = copy_buf_size(fd, buf);	
	line = ft_strdup(buf);
	if (!line)
		return (NULL);		
	free(buf);
	close(fd);
	return (line);
}
