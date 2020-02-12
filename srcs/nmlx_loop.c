/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmlx_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 11:06:29 by mbrunel           #+#    #+#             */
/*   Updated: 2020/02/12 17:06:55 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <not_mlx.h>

int	mlx_loop (void *mlx_ptr)
{
	SDL_Event	sdl_event;
	t_event		*event;
	int			x_event;
	t_loop		*loop_node;
	t_nmlx		*s;
	int			i;
	int			x;
	int			y;

	s = (t_nmlx*)mlx_ptr;
	while (1)
	{
		while (SDL_PollEvent(&sdl_event))
		{
			event = s->win->event;
			sdl_to_x(&i, &x_event, &sdl_event);
			if (x_event == EXIT)
			{
				s->loop_stop = 1;
				break ;
			}
			while (event)
			{
				if (x_event && event->event == x_event)
				{
					if (event->m)
					{
						SDL_GetMouseState(&x, &y);
						(*(event->funct_ptr))(i, x, y, event->param);
					}
					else if (sdl_event.key.repeat && !s->key_repeat)
					{
						event = event->next;
						continue ;
					}
					else
						(*(event->funct_ptr))(i, event->param);
					break ;
				}
				event = event->next;
			}
		}
		if (s->smart_hook && !x_event)
			continue ;
		loop_node = s->loop;
		while (loop_node)
		{
			(*(loop_node->funct_ptr))(loop_node->param);
			loop_node = loop_node->next;
		}
		if (s->loop_stop)
			break ;
	}
	return (0);
}
