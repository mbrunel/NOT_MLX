/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_to_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 10:02:04 by mbrunel           #+#    #+#             */
/*   Updated: 2020/02/10 10:16:55 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <not_mlx.h>

/*						__			 __
** norm forbids switch    \__(*_*)__/
*/

void				sdl_to_x(int *x_event, SDL_Event *sdl_event)
{
	if (sdl_event->type ==  SDL_KEYDOWN)
		*x_event = KeyPress;
	if (sdl_event->type == SDL_KEYUP)
		*x_event = KeyRelease;
	if (sdl_event->type == SDL_QUIT)
		*x_event = EXIT;
}
