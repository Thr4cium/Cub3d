/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:37:47 by mguy              #+#    #+#             */
/*   Updated: 2024/07/23 19:16:44 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	last_char(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (str[i - 1]);
}
