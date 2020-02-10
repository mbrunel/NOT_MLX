/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmlx_new_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 10:10:04 by mbrunel           #+#    #+#             */
/*   Updated: 2020/02/10 10:28:29 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <not_mlx.h>

void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title)
{
	t_nmlx *s;

	s = (t_nmlx*)mlx_ptr;
	if (s->win)
		free(s->win);
	if (!(s->win = malloc(sizeof(t_win))))
		return (NULL);
	if (!(s->win->win = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, size_x, size_y, SDL_WINDOW_SHOWN)))
		return (NULL);
	if (!(s->win->render = SDL_CreateRenderer((SDL_Window*)s->win->win, -1, 0)))
		return (NULL);
	if (!(s->win->event = malloc(sizeof(t_event))))
		return (NULL);
	s->win->event->next = NULL;
	s->win->event->funct_ptr = &exit_no_leaks;
	s->win->event->param = mlx_ptr;
	s->win->event->event = EXIT;
	return (s->win);
}
