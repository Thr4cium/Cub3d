/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:13:04 by magrondi          #+#    #+#             */
/*   Updated: 2024/12/19 18:34:57 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd == -1)
		return (ft_free(buffer), NULL);
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE >= INT_MAX
		|| BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	line = NULL;
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
	{
		ft_free(buffer);
		return (NULL);
	}
	line = ft_cpy_current_line(buffer);
	if (!line)
	{
		ft_reset_malloc(line);
		ft_reset_malloc(buffer);
		return (NULL);
	}
	buffer = ft_trim_buffer(buffer, line);
	return (line);
}

char	*ft_read_file(int fd, char *buffer)
{
	char	*tmp_buffer;
	int		byte_read;

	byte_read = 1;
	tmp_buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp_buffer)
		return (ft_free(buffer), NULL);
	ft_bzero(tmp_buffer, (BUFFER_SIZE + 1));
	while (!ft_strchr(tmp_buffer, '\n') && byte_read != 0)
	{
		byte_read = read(fd, tmp_buffer, BUFFER_SIZE);
		if (byte_read < 0)
		{
			ft_reset_malloc(tmp_buffer);
			ft_reset_malloc(buffer);
			return (NULL);
		}
		tmp_buffer[byte_read] = '\0';
		buffer = ft_strjoin_gnl(buffer, tmp_buffer);
	}
	return (ft_reset_malloc(tmp_buffer), buffer);
}

char	*ft_cpy_current_line(char *buffer)
{
	size_t		i;
	char		*line;

	i = 0;
	if (!buffer || !buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i ++;
	line = (char *) malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i ++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i ++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_trim_buffer(char *buffer, char *line)
{
	size_t		i;
	size_t		j;
	char		*str;
	char		*trim_buffer;

	i = 0;
	trim_buffer = ft_strchr(buffer, '\n');
	if (!trim_buffer || !trim_buffer[i])
	{
		ft_reset_malloc(buffer);
		return (NULL);
	}
	str = (char *) malloc(sizeof(char) * (ft_strlen(trim_buffer) + 1));
	if (!str)
	{
		ft_reset_malloc(&line);
		ft_reset_malloc(buffer);
		return (NULL);
	}
	i ++;
	j = 0;
	while (trim_buffer[i])
		str[j++] = trim_buffer[i++];
	str[j] = '\0';
	return (ft_reset_malloc(buffer), str);
}
