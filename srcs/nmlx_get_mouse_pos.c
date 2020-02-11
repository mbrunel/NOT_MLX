/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmlx_get_mouse_pos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 07:20:00 by mbrunel           #+#    #+#             */
/*   Updated: 2020/02/11 07:22:08 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <not_mlx.h>

int     mlx_mouse_get_pos(void *win_ptr, int *x, int *y)
{
	(void)win_ptr;
	SDL_GetMouseState(x, y);
}
