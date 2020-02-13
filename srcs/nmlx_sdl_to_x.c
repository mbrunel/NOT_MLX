/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmlx_sdl_to_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 10:02:04 by mbrunel           #+#    #+#             */
/*   Updated: 2020/02/13 14:31:23 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <not_mlx.h>

/*                      __           __
** norm forbids switch    \__(*_*)__/
*/

static const int g_laflemme[] = {-1, -1, -1, -1, -1, -1, -1, -1, 51,48,-1,-1,-1,36,-1,-1,-1,
			-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,53,-1,-1,-1,-1,49,-1,-1,-1,-1,-1,-1,
			39,-1,-1,-1,-1,43,27,47,44,29,18,19,20,21,23,22,26,28,25,-1,41,
			-1,24,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
			-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,42,30,-1,-1,50,0,11,8,2,14,3,
			5,4,34,38,40,37,46,45,31,35,12,15,1,17,32,9,13,7,16,6,51,57,122,
			120,99,118,96,97,98,100,101,109,103,111,-1,-1,-1,-1,115,116,-1,119,
			121,124,123,125,126,71,75,67,78,69,76,83,84,85,86,87,88,89,91,92,
			82,65,-1,-1,-1,81,105,107,113,106,64,79,80,90,-1,-1,-1,-1,-1,-1,-1,
			-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
			-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,};

void	sdl_to_x(int *i, int *x_event, SDL_Event *sdl_event)
{
	*x_event = 0;
	if (sdl_event->type == SDL_KEYDOWN)
		*x_event = KeyPress;
	if (sdl_event->type == SDL_KEYUP)
		*x_event = KeyRelease;
	if (*x_event)
	{
		if (sdl_event->key.keysym.sym > 1073741880 && sdl_event->key.keysym.sym < 1073742106)
			sdl_event->key.keysym.sym -= 1073741757;
		*i = g_laflemme[sdl_event->key.keysym.sym];

	}
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
