/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 02:18:41 by magrondi          #+#    #+#             */
/*   Updated: 2023/11/23 16:06:08 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int			i;
	t_list		*temp;

	i = 0;
	temp = lst;
	if (!lst)
		return (i);
	while (temp)
	{
		i ++;
		temp = temp->next;
	}
	return (i);
}
