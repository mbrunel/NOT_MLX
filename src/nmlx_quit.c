/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmlx_quit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 10:27:18 by mbrunel           #+#    #+#             */
/*   Updated: 2020/02/12 17:29:11 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <not_mlx.h>

int					sig_kill(int i, void *mlx_ptr)
{
	(void)i;
	((t_nmlx*)(mlx_ptr))->loop_stop = 1;
	return (0);
}

void				nmlx_quit(void *mlx_ptr)
{
	t_nmlx *s;
	t_loop *node;
	t_loop *freed;

	s = (t_nmlx*)mlx_ptr;
	node = s->loop;
	while (node)
	{
		freed = node;
		node = node->next;
		free(freed);
	}
	free(mlx_ptr);
}
