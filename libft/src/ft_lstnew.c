/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:05:00 by magrondi          #+#    #+#             */
/*   Updated: 2024/02/12 02:58:05 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstnew(void *content, size_t index)
{
	t_list	*cell;

	cell = malloc(sizeof(t_list));
	if (!cell)
		return (free(content), NULL);
	cell->content = content;
	cell->next = NULL;
	cell->prev = NULL;
	cell->static_ref = NULL;
	cell->linelen = (ft_strlen((char *) content) - 1);
	cell->index = index;
	return (cell);
}
