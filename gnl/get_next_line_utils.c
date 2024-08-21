/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:16:09 by rolamber          #+#    #+#             */
/*   Updated: 2024/08/21 16:08:42 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

size_t	ftt_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ftt_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str = ftt_calloc(sizeof(char), ftt_strlen(s1) + ftt_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	return (str);
}

int	ft_strsearch(char *s1, char c)
{
	char	*str;

	str = s1;
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char	*ftt_substr(char *s1, int start, int end)
{
	char	*str;
	int		i;

	i = 0;
	if (!s1 || !s1[0])
		return (NULL);
	str = ftt_calloc(sizeof(char), (end - start + 2));
	if (!str)
		return (NULL);
	while (start <= end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	return (str);
}

void	*ftt_calloc(size_t count, size_t size)
{
	char	*buff;
	size_t	i;

	i = 0;
	buff = malloc(count * size);
	if (!buff)
		return (NULL);
	while (i < count * size)
	{
		buff[i] = 0;
		i++;
	}
	return (buff);
}
