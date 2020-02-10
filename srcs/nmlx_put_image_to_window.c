/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmlx_put_image_to_window.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 07:34:10 by mbrunel           #+#    #+#             */
/*   Updated: 2020/02/10 08:18:27 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <not_mlx.h>

int	mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y)
{
	SDL_Texture	*tex;
	t_img		*s_img;
	t_win		*s_win;
	t_nmlx		*s;

	s = (t_nmlx*)mlx_ptr;
	if (!s->img || !s->win)
		return (-1);
	s_img = (t_img*)img_ptr;
	s_win = (t_win*)win_ptr;
	(void)x;(void)y;
	if (!(tex = SDL_CreateTexture(s_win->render, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, s_img->width, s_img->height)))
		return (-1);
	if (SDL_UpdateTexture(tex, NULL, s_img->img, s->img->width * sizeof (Uint32)) == -1)
		return (-1);
	if (SDL_RenderCopy(s_win->render,tex, NULL, NULL) == -1)
		return (-1);
	SDL_RenderPresent(s_win->render);
	SDL_DestroyTexture(tex);
	return (0);
}
