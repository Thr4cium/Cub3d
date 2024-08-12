/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:15:18 by rolamber          #+#    #+#             */
/*   Updated: 2024/01/13 19:23:08 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*buffswap(char *buffer)
{
	char	*final_buffer;
	int		i;
	int		j;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	final_buffer = ft_calloc(sizeof(char), (ft_strlen(buffer) - i + 1));
	if (!final_buffer)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i] != '\0')
		final_buffer[j++] = buffer[i++];
	free(buffer);
	return (final_buffer);
}

char	*buff_join(char *buffer, char *next_buff)
{
	char	*new_buff;

	new_buff = ft_strjoin(buffer, next_buff);
	free(buffer);
	return (new_buff);
}

char	*ft_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
		{
			line = ft_substr(buffer, 0, i);
			return (line);
		}
		i++;
	}
	line = ft_substr(buffer, 0, ft_strlen(buffer));
	return (line);
}

char	*buffcheck(char *buffer, int fd)
{
	char	*next_buff;
	int		end_or_error;

	if (!buffer)
		buffer = ft_calloc(sizeof(char), 1);
	end_or_error = 1;
	next_buff = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	while (end_or_error > 0 && !ft_strsearch(buffer, '\n'))
	{
		end_or_error = read(fd, next_buff, BUFFER_SIZE);
		if (end_or_error == -1)
		{
			free(next_buff);
			return (NULL);
		}
		if (end_or_error < BUFFER_SIZE)
			next_buff[end_or_error] = '\0';
		buffer = buff_join(buffer, next_buff);
	}
	free(next_buff);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = buffcheck(buffer, fd);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = buffswap(buffer);
	return (line);
}
