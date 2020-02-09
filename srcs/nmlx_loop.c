/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmlx_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 11:06:29 by mbrunel           #+#    #+#             */
/*   Updated: 2020/02/09 15:00:58 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <not_mlx.h>

int	mlx_loop (void *mlx_ptr)
{
	SDL_Event event;
	(void)mlx_ptr;
	while (1)
		SDL_WaitEvent(&event);
	return (-1);
}
