/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:24:55 by mbrunel           #+#    #+#             */
/*   Updated: 2019/10/19 07:43:02 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*obj;

	obj = ft_lstlast(*alst);
	if (!new)
		return ;
	if (obj)
	{
		new->next = NULL;
		obj->next = new;
	}
	else
		ft_lstadd_front(alst, new);
}
