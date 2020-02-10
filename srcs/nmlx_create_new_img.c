/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmlx_create_new_img.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 06:22:03 by mbrunel           #+#    #+#             */
/*   Updated: 2020/02/10 08:16:08 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <not_mlx.h>

void	*mlx_new_image(void *mlx_ptr,int width,int height)
{
	t_nmlx *s;

	s = (t_nmlx*)mlx_ptr;
	if (!(s->img = malloc(sizeof(t_win))))
		return (NULL);
	s->img->width = width;
	s->img->height = height;
	if (!(s->img->img = malloc(s->img->height * s->img->width * sizeof(uint8_t) * 4)))
		return (NULL);
	return ((void*)s->img);
}
