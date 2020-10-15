/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmlx_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 11:06:29 by mbrunel           #+#    #+#             */
/*   Updated: 2020/02/13 15:18:40 by mbrunel          ###   ########.fr       */
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

	s = (t_nmlx*)mlx_ptr;
	s->loop_stop = 0;
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
						SDL_GetMouseState(&event->x, &event->y);
					else if (sdl_event.key.repeat && !s->key_repeat)
					{
						event = event->next;
						continue ;
					}
					event->to_do = 1;
					break ;
				}
				event = event->next;
			}
		}
		if (s->loop_stop)
			break ;
		x_event = 0;
		while (event)
		{
			if (event->to_do)
			{
				event->to_do = 0;
				x_event = 1;
				if (event->m)
					(*(event->funct_ptr))(i, event->x, event->y, event->param);
				else
					(*(event->funct_ptr))(i, event->param);
			}
			event = event->next;
		}
		if (!x_event && s->smart_hook)
			continue ;
		loop_node = s->loop;
		while (loop_node)
		{
			(*(loop_node->funct_ptr))(loop_node->param);
			loop_node = loop_node->next;
		}
	}
	return (0);
}
