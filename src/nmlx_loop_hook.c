/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmlx_loop_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:13:00 by mbrunel           #+#    #+#             */
/*   Updated: 2020/02/12 16:38:04 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <not_mlx.h>

int	mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param)
{
	t_nmlx *s;
	t_loop *new;
	t_loop *node;

	s = (t_nmlx*)mlx_ptr;
	if (!(new = malloc(sizeof(t_loop))))
		return (-1);
	new->funct_ptr = funct_ptr;
	new->param = param;
	new->next = NULL;
	if (!s->loop)
	{
		s->loop = new;
		return (0);
	}
	node = s->loop;
	while (node->next && !(node->funct_ptr == funct_ptr && node->param == param))
		node = node->next;
	if (!node->next)
		node->next = new;
	return (0);
}
