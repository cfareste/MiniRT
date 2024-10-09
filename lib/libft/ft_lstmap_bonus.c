/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 09:59:02 by arcanava          #+#    #+#             */
/*   Updated: 2024/01/20 16:33:16 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	update_lsts(t_list **new_lst, t_list **prev_lst, t_list *curr_lst)
{
	if (*new_lst)
	{
		(*prev_lst)->next = curr_lst;
		*prev_lst = (*prev_lst)->next;
	}
	else
	{
		*new_lst = curr_lst;
		*prev_lst = *new_lst;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*prev_n_list;
	t_list	*current_lst;
	void	*content_curr;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		content_curr = f(lst->content);
		current_lst = ft_lstnew(content_curr);
		if (!current_lst)
		{
			del(content_curr);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		update_lsts(&new_list, &prev_n_list, current_lst);
		lst = lst->next;
	}
	return (new_list);
}
