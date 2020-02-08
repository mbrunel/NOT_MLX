/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:26:29 by mbrunel           #+#    #+#             */
/*   Updated: 2019/10/19 06:44:31 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstcpy(t_list *lst)
{
	t_list	**alst;
	t_list	*new;

	if (!lst)
		return (NULL);
	new = ft_lstnew(lst->content);
	alst = &new;
	while (lst->next)
	{
		lst = lst->next;
		new = ft_lstnew(lst->content);
		ft_lstadd_back(alst, new);
	}
	return (*alst);
}
