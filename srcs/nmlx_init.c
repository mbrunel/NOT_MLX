/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmlx_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 10:50:53 by mbrunel           #+#    #+#             */
/*   Updated: 2020/02/14 01:41:00 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <not_mlx.h>

void *mlx_init(void)
{
	t_nmlx *s;

	if (!(s = malloc(sizeof(t_nmlx))))
		return (NULL);
	s->win = NULL;
	s->img = NULL;
	s->loop = NULL;
	if (SDL_Init(SDL_INIT_VIDEO))
		return (NULL);
	s->smart_hook = 0;
	s->key_repeat = 1;
	s->loop_stop = 0;
	return ((void*)s);
}
