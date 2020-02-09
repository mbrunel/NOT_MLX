/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 10:50:53 by mbrunel           #+#    #+#             */
/*   Updated: 2020/02/09 11:00:13 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <not_mlx.h>

void *mlx_init(void)
{
	t_nmlx *s;

	if (!(s = malloc(sizeof(t_nmlx))))
		return (NULL);
	if (SDL_Init(SDL_INIT_VIDEO))
		return (NULL);
	return ((void*)s);
}
