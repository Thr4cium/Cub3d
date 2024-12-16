/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 02:18:56 by magrondi          #+#    #+#             */
/*   Updated: 2024/07/24 01:11:34 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
	if (!*lst)
	{
		new->length = 1;
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	new->prev = temp;
	temp->next = new;
	lst[0]->length = ft_lstsize(*lst);
}
