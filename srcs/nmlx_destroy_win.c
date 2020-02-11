/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmlx_destroy_window.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:35:44 by mbrunel           #+#    #+#             */
/*   Updated: 2020/02/11 16:04:26 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <not_mlx.h>

static void	free_win(t_win *win)
{
	t_event	*node;
	t_event *freed;

	node = win->event;
	while (node)
	{
		freed = node;
		node = node->next;
		free(freed);
	}
	SDL_DestroyRenderer(win->render);
	SDL_DestroyWindow(win->win);
	free(win);
}

int			mlx_destroy_window(void *mlx_ptr, void *win_ptr)
{
	t_nmlx	*s;
	t_win	*win;
	t_win	*node;

	s = (t_nmlx*)mlx_ptr;
	win = (t_win*)win_ptr;
	node = s->win;
	if (win && node == win)
	{
		s->win = node->next;
		free_win(win);
		return (0);
	}
	while (node && node->next != win)
		node = node->next;
	if (!node)
		return (-1);
	node->next = win->next;
	free_win(win);
	return (0);
}
