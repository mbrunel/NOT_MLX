/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_to_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 10:02:04 by mbrunel           #+#    #+#             */
/*   Updated: 2020/02/11 16:42:23 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <not_mlx.h>

/*                      __           __
** norm forbids switch    \__(*_*)__/
*/

void				sdl_to_x(int *i, int *x_event, SDL_Event *sdl_event)
{
	*x_event =  0;
	if (sdl_event->type ==  SDL_KEYDOWN)
		*x_event = KeyPress;
	if (sdl_event->type == SDL_KEYUP)
		*x_event = KeyRelease;
	if (*x_event)
		*i = sdl_event->key.keysym.sym;
	else
	{
		if (sdl_event->type == SDL_MOUSEBUTTONDOWN)
			*x_event = ButtonPress;
		if (sdl_event->type == SDL_MOUSEBUTTONUP)
			*x_event = ButtonRelease;
		if (*x_event)
			*i = sdl_event->button.button == 3 ? 2 : sdl_event->button.button;
		else
			*i = 0;
	}
	if (sdl_event->type == SDL_QUIT)
		*x_event = EXIT;
}
