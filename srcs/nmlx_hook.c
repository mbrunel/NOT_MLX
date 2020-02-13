/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmlx_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 09:11:59 by mbrunel           #+#    #+#             */
/*   Updated: 2020/02/13 17:05:08 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <not_mlx.h>

int	mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param)
{
	t_win	*win;
	t_event	*event;
	t_event *new;

	(void)x_mask;
	win = (t_win*)win_ptr;
	event = win->event;
	if (!(new = malloc(sizeof(t_event))))
		return (-1);
	new->next = NULL;
	new->event = x_event;
	new->funct_ptr = funct;
	new->param = param;
	new->to_do = 0;
	if (x_event == ButtonPress || x_event == ButtonRelease)
		new->m = 1;
	else
		new->m = 0;
	while (event->next && event->next->event != x_event)
		event = event->next;
	if (!event->next)
		event->next = new;
	return (0);
}

int	mlx_mouse_hook (void *win_ptr, int (*funct_ptr)(), void *param)
{
	return (mlx_hook(win_ptr, 5, 0, funct_ptr, param));
}

int	mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param)
{
	return (mlx_hook(win_ptr, 3, 0, funct_ptr, param));
}
