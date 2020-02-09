/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmlx_new_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 10:10:04 by mbrunel           #+#    #+#             */
/*   Updated: 2020/02/09 11:12:03 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <not_mlx.h>

void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title)
{
	t_nmlx *nlmx;

	nlmx = (t_nmlx*)mlx_ptr;
	return ((nlmx->win = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, size_x, size_y, SDL_WINDOW_SHOWN)));
}
