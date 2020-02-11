/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmlx_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 11:06:29 by mbrunel           #+#    #+#             */
/*   Updated: 2020/02/11 07:14:44 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <not_mlx.h>

int	mlx_loop (void *mlx_ptr)
{
	SDL_Event	sdl_event;
	t_event		*event;
	int			x_event;
	t_nmlx		*s;
	int			i;

	s = (t_nmlx*)mlx_ptr;
	while (1)
	{
		event = s->win->event;
		SDL_PollEvent(&sdl_event);
		sdl_to_x(&i, &x_event, &sdl_event);
		while (event)
		{
			if (x_event && event->event == x_event)
				(*(event->funct_ptr))(i, event->param);
			event = event->next;
		}
	}
	return (0);
}
