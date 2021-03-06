/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmlx_new_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 10:10:04 by mbrunel           #+#    #+#             */
/*   Updated: 2020/02/14 21:19:13 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <not_mlx.h>

void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title)
{
	t_nmlx	*s;
	t_win	*new;
	t_win	*node;

	s = (t_nmlx*)mlx_ptr;
	if (!(new = malloc(sizeof(t_win))))
		return (NULL);
	if (!(new->win = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, size_x, size_y, SDL_WINDOW_SHOWN)))
	{
		free(new);
		return (NULL);
	}
	if (!(new->render = SDL_CreateRenderer((SDL_Window*)new->win, -1, 0)))
	{
		SDL_DestroyWindow(new->win);
		free(new);
		return (NULL);
	}
	if (SDL_SetRenderDrawColor(new->render, 0, 0, 0, 255) == -1)
	{
		SDL_DestroyRenderer(new->render);
		SDL_DestroyWindow(new->win);
		free(new);
		return (NULL);
	}
	if (!(new->event = malloc(sizeof(t_event))))
	{
		SDL_DestroyRenderer(new->render);
		SDL_DestroyWindow(new->win);
		free(new);
		return (NULL);
	}
	new->event->next = NULL;
	new->event->funct_ptr = &sig_kill;
	new->event->param = mlx_ptr;
	new->event->event = EXIT;
	new->next = NULL;
	if (!s->win)
		s->win = new;
	else
	{
		node = s->win;
		while (node->next)
			node = node->next;
		node->next = new;
	}
	return (s->win);
}
