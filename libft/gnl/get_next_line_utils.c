/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:13:08 by magrondi          #+#    #+#             */
/*   Updated: 2024/01/22 17:57:45 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t		result_index;
	size_t		cpy_index;
	char		*result;
	size_t		linelen;

	linelen = (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (linelen > INT_MAX)
		return (ft_reset_malloc(s1), NULL);
	result = (char *) malloc(sizeof(char) * linelen);
	if (!result)
	{
		ft_reset_malloc(s1);
		return (NULL);
	}
	result_index = 0;
	cpy_index = 0;
	while (cpy_index < ft_strlen(s1))
		result[result_index++] = s1[cpy_index++];
	cpy_index = 0;
	while (cpy_index < ft_strlen(s2))
		result[result_index++] = s2[cpy_index++];
	result[result_index] = '\0';
	ft_reset_malloc(s1);
	return (result);
}

void	ft_reset_malloc(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
}
