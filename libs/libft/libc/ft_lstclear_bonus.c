/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:39:02 by mbrunel           #+#    #+#             */
/*   Updated: 2019/10/25 23:59:34 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list		*obj;

	if (!*lst)
		return ;
	obj = *lst;
	while (obj)
	{
		ft_lstdelone(obj, del);
		obj = obj->next;
	}
	*lst = NULL;
}
