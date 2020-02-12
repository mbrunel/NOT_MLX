/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmlx_new_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 06:22:03 by mbrunel           #+#    #+#             */
/*   Updated: 2020/02/12 13:56:50 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <not_mlx.h>

void	*mlx_new_image(void *mlx_ptr,int width,int height)
{
	t_nmlx	*s;
	t_img	*node;
	t_img	*new;

	s = (t_nmlx*)mlx_ptr;
	if (!(new = malloc(sizeof(t_win))))
		return (NULL);
	new->width = width;
	new->height = height;
	if (!(new->img = malloc(height * width * sizeof(int8_t) * 4)))
		return (NULL);
	if (!(new->tex = SDL_CreateTexture(s->win->render, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, width, height)))
		return (NULL);
	new->next = NULL;
	if (!s->img)
		s->img = new;
	else
	{
		node = s->img;
		while (node->next)
			node = node->next;
		node->next = new;
	}
	return (new);
}
