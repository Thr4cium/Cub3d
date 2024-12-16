/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:36:04 by magrondi          #+#    #+#             */
/*   Updated: 2023/12/06 05:57:38 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list_temp;
	t_list	*list;
	void	*function_temp;

	if (!lst || !f || !del)
		return (NULL);
	list = NULL;
	list_temp = NULL;
	while (lst)
	{
		function_temp = f(lst->content);
		list_temp = ft_lstnew(function_temp, 0);
		if (!list_temp)
		{
			ft_lstclear(&list, del);
			del(function_temp);
			function_temp = NULL;
			return (NULL);
		}
		ft_lstadd_back(&list, list_temp);
		lst = lst->next;
	}
	return (list);
}
