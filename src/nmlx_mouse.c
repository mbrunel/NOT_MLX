/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmlx_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 07:20:00 by mbrunel           #+#    #+#             */
/*   Updated: 2020/02/14 00:00:52 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <not_mlx.h>

int		mlx_mouse_get_pos(void *win_ptr, int *x, int *y)
{
	(void)win_ptr;
	return (SDL_GetMouseState(x, y));
}

int		mlx_mouse_hide()
{
	return (SDL_ShowCursor(SDL_DISABLE));
}

int		mlx_mouse_show()
{
	return (SDL_ShowCursor(SDL_ENABLE));
}

int		mlx_mouse_move(void *win_ptr, int x, int y)
{
	t_win *win;

	win = (t_win*)win_ptr;
	SDL_WarpMouseInWindow(win->win, x, y);
	return (0);
}
