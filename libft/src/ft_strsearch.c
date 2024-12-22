/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:58:56 by magrondi          #+#    #+#             */
/*   Updated: 2024/12/19 17:59:50 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
