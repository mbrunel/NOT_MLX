/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmlx_destroy_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:48:09 by mbrunel           #+#    #+#             */
/*   Updated: 2020/02/11 16:06:00 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <not_mlx.h>

int	mlx_destroy_image(void *mlx_ptr, void *img_ptr)
{
	t_nmlx	*s;
	t_img	*img;
	t_img	*node;

	s = (t_nmlx*)mlx_ptr;
	img = (t_img*)img_ptr;
	node = s->img;
	if (img && node == img)
	{
		s->img = node->next;
		SDL_DestroyTexture(img->tex);
		free(img);
		return (0);
	}
	while (node && node->next != img)
		node = node->next;
	if (!node)
		return (-1);
	node->next = img->next;
	SDL_DestroyTexture(img->tex);
	free(img);
	return (0);
}
