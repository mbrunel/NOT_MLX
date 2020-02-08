/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:51:03 by mbrunel           #+#    #+#             */
/*   Updated: 2019/10/28 13:42:12 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*new;
	t_list	*alst;
	void	*content;

	if (!lst)
		return (NULL);
	if (!f)
		return (ft_lstcpy(lst));
	alst = new;
	while (lst)
	{
		if (!(content = (*f)(lst->content)))
		{
			ft_lstclear(&alst, new);
			return (NULL);
		}
		if (!(new = ft_lstnew(content)))
		{
			ft_lstclear(&alst, new);
			return (NULL);
		}
		lst = lst->next;
	}
	return (alst);
}
